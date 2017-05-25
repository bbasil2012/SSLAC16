#define PCF8563address 0x51
#define DS1307address 0x68
void check_RTC() {
      Wire.beginTransmission(PCF8563address);
      if (Wire.endTransmission()==0) 
        { 
          isRTC+=2;
          readPCF8563(tm);
        }
        Wire.beginTransmission(DS1307address);
        if (Wire.endTransmission()==0) 
          { 
            isRTC+=1;
          }
        if (isRTC==3) isRTC=2;
        if (isRTC==0) Serial.println("RTC not found !!!");
}

byte bcdToDec(byte value)
{
  return ((value / 16) * 10 + value % 16);
}
byte decToBcd(byte value){
  return (value / 10 * 16 + value % 10);
}

void setPCF8563(tmElements_t &tm_pcf){
// this sets the time and date to the PCF8563

  Wire.beginTransmission(PCF8563address);
  Wire.write(0x02);
  Wire.write(decToBcd(tm_pcf.Second));  
  Wire.write(decToBcd(tm_pcf.Minute));
  Wire.write(decToBcd(tm_pcf.Hour));     
  Wire.write(decToBcd(tm_pcf.Day));
  Wire.write(decToBcd(tm_pcf.Wday));  
  Wire.write(decToBcd(tm_pcf.Month));
  Wire.write(decToBcd(tm_pcf.Year));
  Wire.endTransmission();
}
void readPCF8563(tmElements_t &tm_pcf)

// this gets the time and date from the PCF8563
{
  
  Wire.beginTransmission(PCF8563address);
  Wire.write(0x02);
  Wire.endTransmission();
  Wire.requestFrom(PCF8563address,7);
  tm_pcf.Second     = bcdToDec(Wire.read() & B01111111); // remove VL error bit
  tm_pcf.Minute     = bcdToDec(Wire.read() & B01111111); // remove unwanted bits from MSB
  tm_pcf.Hour       = bcdToDec(Wire.read() & B00111111); 
  tm_pcf.Day = bcdToDec(Wire.read() & B00111111);
  tm_pcf.Wday  = bcdToDec(Wire.read() & B00000111);  
  tm_pcf.Month      = bcdToDec(Wire.read() & B00011111);  // remove century bit, 1999 is over
  tm_pcf.Year       = bcdToDec(Wire.read());
}




void ticker(){
    
        _millis=millis();
    if ((msStart==0) and (msCurrent==0)){
      Serial.print("msSatrt=0: ");
      msStart=(tm.Hour*3600+tm.Minute*60+tm.Second)*1000;
      Serial.println(msStart);
      if (msStart>_millis) msStart=msStart-_millis;
      msCurrent=msStart+_millis;
    }
    if ((msStart==0) and (msCurrent>0)) {
      msCurrent=(tm.Hour*3600+tm.Minute*60+tm.Second)*1000;
      Serial.println(msStart);
      while (1){
        yield();
        if (msCurrent>_millis){
          msStart=msCurrent-_millis;
          Serial.print("msStart rol:");
          Serial.println(msStart);
          break;
        } else msCurrent+=86400000;
      }
    }
    
    if (_millis % 1000==0){
        if (isRTC==1)  ds1307RTC.read(tm);
        if (isRTC==2)  readPCF8563(tm);
        if (isRTC==0){
          tm.Hour= (msCurrent/1000)  % 86400L / 3600;
          tm.Minute = (msCurrent/1000) % 3600 / 60;
          tm.Second = (msCurrent/1000) % 60;
        }
        if ((is_time_set==0) and (isConn)){
          if (sntp_get_current_timestamp()!=0){
              tm.Hour=(hour(sntp_get_current_timestamp()));
              tm.Minute=(minute(sntp_get_current_timestamp()));
              tm.Second=(second(sntp_get_current_timestamp()));
              tm.Day=(day(sntp_get_current_timestamp()));
              tm.Month=(month(sntp_get_current_timestamp()));
              tm.Year=(year(sntp_get_current_timestamp()));
              msCurrent=(tm.Hour*3600+tm.Minute*60+tm.Second)*1000;
              is_time_set=1;
              setTimeRTC();
          }
        }
        
  }
  
  if ((_millis %500 == 0) and (isMaster==1)) {
    sendUdpSync();
    
  }
  if (_millis %5000 ==0) {
    sensors.requestTemperatures();
    for (byte i=0;i<8;i++){
        if (group[i].alarmIndex!=255){
          byte _index=group[i].alarmIndex;
           if (group[i].temp < Sensor[_index].Temp) {
              group[i].isAlarm=1;
              for (byte j=0;j<16;j++) {
                if ((newCh[j].group==i) and (newCh[j].type==0)) {
                  if (newCurrent[j]>group[i].step) { 
                    newCurrent[j]-=group[i].step;
                    invPWM(j,newCurrent[j]);
                  }
                  
                }
              }
            } 
            else group[i].isAlarm=0;
           
        } else group[i].isAlarm=0;
    }
  
    for (byte i=0;i<cSensor;i++){ 
      Sensor[i].Temp=sensors.getTempC(Sensor[i].addr);
    }
    
    
  }
  if (_millis% 10==0) {
      if (msCurrent>=86400000) msCurrent=0; else msCurrent+=10 ;
     int pc=slave_udp.parsePacket();
     if (pc!=0){
        receiveUdpSync(pc); 
        master_alive=0;
     }
     else 
        master_alive++;
  }

  
  
}



void setTimeRTC(){
     if (isRTC==1) ds1307RTC.write(tm);
     if (isRTC==2) setPCF8563(tm);
     if (isRTC==3){
      setPCF8563(tm);
     }
     
}

