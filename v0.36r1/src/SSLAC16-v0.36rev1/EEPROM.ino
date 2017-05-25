int readEmLight(int address){
  byte _buff[sizeof emLight];
  int i;
  for (i=0;i<sizeof emLight;i++){
    _buff[i]=EEPROM.read(address);
    address++;
  }
  memcpy(emLight,_buff,sizeof emLight);
  Serial.print("readEmligth=");Serial.println(address);
  return address;
}

int saveEmLight(int address){
 byte _buff[sizeof emLight];
  memcpy(_buff,emLight,sizeof emLight);
  int i;
  for(i=0;i<sizeof emLight;i++) {
    EEPROM.write(address,_buff[i]);
    yield();
    address++;
  }
  return address;
}

int readNewAlarm(int address){
  byte _buff[sizeof newAlarm];
  int i;
  for (i=0;i<sizeof newAlarm;i++){
    _buff[i]=EEPROM.read(address);
    address++;
  }
  memcpy(newAlarm,_buff,sizeof newAlarm);
  Serial.print("NewAlarm=:"); Serial.println("address");
  return address;
}

int saveNewAlarm(int address){
 byte _buff[sizeof newAlarm];
  memcpy(_buff,newAlarm,sizeof newAlarm);
  int i;
  for(i=0;i<sizeof newAlarm;i++) {
    EEPROM.write(address,_buff[i]);
    yield();
    address++;
  }
  return address;
}

int readNewCh(int address){
  byte _buff[sizeof newCh];
  int i;
  for (i=0;i<sizeof newCh;i++){
    _buff[i]=EEPROM.read(address);
    address++;
  }
  memcpy(newCh,_buff,sizeof newCh);
  Serial.print("readNewCh=:");Serial.println(address);
  return address;
}
int saveNewCh(int address){
 byte _buff[sizeof newCh];
  memcpy(_buff,newCh,sizeof newCh);
  int i;
  for(i=0;i<sizeof newCh;i++) {
    EEPROM.write(address,_buff[i]);
    yield();
    address++;
  }
  saveVersion();
  for(byte i=0;i<16;i++){
  }
  return address;
}

void readVersion(){
  version[0]=EEPROM.read(4093);
  version[1]=EEPROM.read(4094);
  version[2]=EEPROM.read(4095);
}
void saveVersion(){
  EEPROM.write(4094,version[1]);
}

void readall(){
  
  EEPROM.begin(max_addr);
  int addr=0;
  byte ssid_addr=0;
  byte passwd_addr=0;
  for (byte i=0; i<16; i++){

    int a=EEPROM.read(addr);
    int b=EEPROM.read(addr+1);
    ch[i].Max = a*256+b;
  
    if (ch[i].Max>4095){
      clearEEPROM();
      break;
    }
    addr+=2;
  }
  addr+=2;
  addr+=2;
  addr++;
  pSDA=EEPROM.read(addr);
  Serial.print("pSDA Addr:");Serial.println(addr);
  if ((pSDA<1) || (pSDA>15)){
    pSDA=4;
  }
  addr++;
  pSCL=EEPROM.read(addr);
  Serial.print("pSCL Addr:");Serial.println(addr);
  if ((pSCL<1) || (pSCL>15)){
    pSCL=5;
  }
  addr++;
  isAlone=EEPROM.read(addr);
  Serial.print("isAlone Addr:");Serial.println(addr);
  addr++;
  pOneWire=EEPROM.read(addr);
  if ((pOneWire>16) || (pOneWire==pSDA) || (pOneWire==pSCL) || (pOneWire==0)) {
      pOneWire=13;
  }
  addr++;
  Serial.print("Start old ch vlue:");Serial.println(addr);
  for (byte i=0; i<16; i++) {
    
    int a=EEPROM.read(addr);
    int b=EEPROM.read(addr+1);
    ch[i].Min = a*256+b;
    if (ch[i].Min>ch[i].Max){
      ch[i].Min=0;
    }
 
    addr+=2;
  }
  addr++;
  Serial.print("after old ch value reading Addr:");Serial.println(addr);
  for (byte i=0; i<16; i++){
    
    ch[i].Inv=EEPROM.read(addr);
    if (ch[i].Inv>1) {
      ch[i].Inv=0;
    }
    addr++;
  }
  Serial.print("Addr old ch Inv:");Serial.println(addr);
  int a=EEPROM.read(addr);
  int b=EEPROM.read(addr+1);
  pwmFreq=a*256+b;
  if ((pwmFreq>1500) or (pwmFreq<40)) pwmFreq=1000;
  addr+=2;
  Serial.print("pwmFreq Addr:");Serial.println(addr);
  Time_Zone=EEPROM.read(addr);
  Serial.print("TimeZone end Addr:");Serial.println(addr);
  Serial.print("ds18x20 start Addr:");Serial.println(addr);
  addr=rDS18x20(100);
  Serial.print("DS18x20 end addr:");Serial.println(addr);
  ssid="";
  ssid_addr=EEPROM.read(447);
  Serial.print("ssid Addr:");Serial.println(addr);
  if ((ssid_addr<32)and (ssid_addr>0)){
    for (addr=448; addr<448+ssid_addr;addr++){
      ssid+=char(EEPROM.read(addr));
    }
  }
  passwd_addr=EEPROM.read(479);
  Serial.print("password Addr:");Serial.println(addr);

  password="";
  if ((passwd_addr<32) and (passwd_addr>0)){
    for (addr=480; addr<480+passwd_addr;addr++){
      password+=char(EEPROM.read(addr));
    }
  }
  addr=576;
  Serial.print("Group begin Addr:");Serial.println(addr);
  addr=readGroup(addr);
  Serial.print("Group end Addr:");Serial.println(addr);
  Serial.print("Alarm begin Addr:");Serial.println(addr);
  addr=864;
  Serial.print("Alarm end Addr:");Serial.println(addr);
  Serial.print("EmLight begin Addr:");Serial.println(addr);
  addr=readEmLight(addr);
  Serial.print("EmLight end Addr:");Serial.println(addr);
  Serial.println(sizeof Pumps);
  addr=1024;
  Serial.print("old chanell begin schedule Addr:");Serial.println(addr);
  for (byte i=0; i<16; i++){
    ch[i].Sunrise.Hour=EEPROM.read(addr);addr++;ch[i].Sunrise.Minute=EEPROM.read(addr);addr++;
    ch[i].Day.Hour=EEPROM.read(addr);addr++;ch[i].Day.Minute=EEPROM.read(addr);addr++;
    ch[i].Sunset.Hour=EEPROM.read(addr);addr++;ch[i].Sunset.Minute=EEPROM.read(addr);addr++;
    ch[i].Night.Hour=EEPROM.read(addr);addr++;ch[i].Night.Minute=EEPROM.read(addr);addr++;
    yield();
  }
  addr++;
  Serial.print("old chanell end schedule Addr:");Serial.println(addr);
  for (byte j=0;j<16;j++){
    for (byte i=0;i<16;i++) {
      ch[j].Desc[i]=EEPROM.read(addr);
      addr++;
    }
  }
  Serial.print("end of old ch description -:");Serial.println(addr);
  Serial.print("Sensors start Addr:");Serial.println(addr);
  for (byte j=0;j<8;j++){
    for (byte i=0;i<16;i++) {
      Sensor[j].Desc[i]=EEPROM.read(addr);
      addr++;
    }
  }
  Serial.print("Sensors end Addr:");Serial.println(addr);
  Serial.print("Start of old ch sensor -:");Serial.println(addr);
  for (byte j=0;j<16;j++) {
    for (byte i=0;i<sizeof ch[j].ds18x20_addr;i++) {
      ch[j].ds18x20_addr[i]=EEPROM.read(addr);
      addr++;
    }
  }
  Serial.print("End of old ch sensor -:");Serial.println(addr);
  byte _length = EEPROM.read(addr);
  Serial.println("\nHostname len: "+String(_length)+" at addr: "+String(addr));
  for (byte j=0; j<_length; j++){
    addr++;
    byte i=EEPROM.read(addr);
    if ((i>32) and (i<127)) {
      esp_hostname+=char(i);
    }
  }
  addr++;
  isMaster=EEPROM.read(addr);
  Serial.print("isMaster Addr:");Serial.println(addr);
  addr++;
  isSlave=EEPROM.read(addr);
  Serial.print("isSlave Addr:");Serial.println(addr);
  addr++;
  tAlarm.index=EEPROM.read(addr);
  Serial.print("tAlarm.index Addr:");Serial.println(addr);
  addr++;
  tAlarm.temp=EEPROM.read(addr);
  Serial.print("tAlarm.temp Addr:");Serial.println(addr);
  addr++;
  tAlarm.step=EEPROM.read(addr);
  Serial.print("tAlarm.step Addr:");Serial.println(addr);
  addr++;
  isHidePassword=EEPROM.read(addr);
  Serial.print("isHidePassword Addr:");Serial.println(addr);
  addr++;
  Serial.print("Last addr3 ");Serial.println(addr);
  readVersion();
  if (version[1]!=36) {
    convertPWM();
    version[1]=36;
  } else {
    addr=readNewCh(addr);
  }
}
void saveall(){
  server.send(200,text_plain,"\n\r");
  EEPROM.begin(max_addr);
  int addr=0;
  for (byte i=0; i<16; i++) {
    int a = ch[i].Max/256;
    int b = ch[i].Max % 256;
    EEPROM.write(addr,a);
    EEPROM.write(addr+1,b);
    addr+=2;
  }
  addr+=2;
  addr+=2;
  addr++;
  EEPROM.write(addr,pSDA);
  addr++;
  EEPROM.write(addr,pSCL);
  addr++;
  EEPROM.write(addr,isAlone);
  addr++;
  EEPROM.write(addr,pOneWire);
  addr++;
  
  for (byte i=0; i<16; i++) {
    int a = ch[i].Min/256;
    int b = ch[i].Min % 256;
    EEPROM.write(addr,a);
    EEPROM.write(addr+1,b);
    addr+=2;
 
  }
  addr++;
  for (byte i=0; i<16; i++){
    EEPROM.write(addr,ch[i].Inv);
    addr++;
  }
  int a= pwmFreq/256;
  int b= pwmFreq%256;
  EEPROM.write(addr,a);
  EEPROM.write(addr+1,b);
  addr+=2;
  EEPROM.write(addr,Time_Zone);
  sDS18x20(100);
  EEPROM.write(447,ssid.length());
  for (addr = 448; addr < 448+ssid.length(); addr++)
          {
            EEPROM.write(addr, ssid[addr-448]);
          }
  EEPROM.write(479,password.length());
  for (addr = 480; addr < 480+password.length(); addr++)
          {
            EEPROM.write(addr, password[addr-480]);
          }
  addr=576;
  addr=saveGroup(addr);
  addr=864;
  addr=saveEmLight(addr);
  addr=1024;
  for (byte i=0; i<16; i++){
    EEPROM.write(addr,ch[i].Sunrise.Hour);addr++;EEPROM.write(addr,ch[i].Sunrise.Minute);addr++;
    EEPROM.write(addr,ch[i].Day.Hour);addr++;EEPROM.write(addr,ch[i].Day.Minute);addr++;
    EEPROM.write(addr,ch[i].Sunset.Hour);addr++;EEPROM.write(addr,ch[i].Sunset.Minute);addr++;
    EEPROM.write(addr,ch[i].Night.Hour);addr++;EEPROM.write(addr,ch[i].Night.Minute);addr++;
    yield();
  }
  addr++;
  for (byte j=0;j<16;j++){
    for (byte i=0;i<16;i++) {
      EEPROM.write(addr,ch[j].Desc[i]);
      addr++;
    }
  }
  for (byte j=0;j<8;j++){
    for (byte i=0;i<16;i++) {
      EEPROM.write(addr,Sensor[j].Desc[i]);
      addr++;
    }
  }
  for (byte j=0;j<16;j++) {
    for (byte i=0;i<sizeof ch[j].ds18x20_addr;i++) {
      EEPROM.write(addr,ch[j].ds18x20_addr[i] );
      addr++;
    }
  }
   
  if (esp_hostname.length()<23) EEPROM.write(addr,esp_hostname.length());
  addr++;
  for (byte j=0; j<esp_hostname.length(); j++){
    EEPROM.write(addr,esp_hostname[j]);
    addr++;
  }
  
  EEPROM.write(addr,isMaster);
  addr++;
  EEPROM.write(addr,isSlave);
  addr++;
  EEPROM.write(addr,tAlarm.index);
  addr++;
  EEPROM.write(addr,tAlarm.temp);
  addr++;
  EEPROM.write(addr,tAlarm.step);
  addr++;
  EEPROM.write(addr,isHidePassword);
  addr++;
  addr=saveNewCh(addr);
  EEPROM.commit();
 }

 void clearEEPROM(){
  
  EEPROM.begin(max_addr);
  for (int i=0; i<max_addr; i++) {
    EEPROM.write(i,0);
    yield();
  }
  EEPROM.commit();
  server.sendContent(F("EEPROM cleared"));
}
void sDS18x20(int address){
  byte _buff[sizeof Sensor ];
  memcpy(buff,Sensor,sizeof Sensor);
  for (int i=0;i<sizeof Sensor;i++){
    EEPROM.write(address+i,buff[i]);
    yield();
  }
}
int saveGroup(int address){
  byte _buff[sizeof group];
  memcpy(_buff,group,sizeof group);
  int i;
  for(i=0;i<sizeof group;i++) {
    EEPROM.write(address+i,_buff[i]);
    yield();
  }
  return address+i;
}

int rDS18x20(int address) {
  for (int i=0;i<sizeof Sensor;i++){
    buff[i]=EEPROM.read(address+i);
  }
  memcpy(Sensor,buff,sizeof Sensor);
  Serial.print("ds1820=");Serial.println(address+sizeof Sensor);
  return address+sizeof Sensor;
}
int readGroup (int address) {
  byte _buff[sizeof group];
  int i;
  for (i=0;i<sizeof group;i++){
    _buff[i]=EEPROM.read(address+i);
  }
  memcpy(group,_buff,sizeof group);
  Serial.print("readGroup=");Serial.println(address+i);
  return address+i;
}

