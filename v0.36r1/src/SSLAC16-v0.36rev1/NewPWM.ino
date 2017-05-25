void Dosing(byte _ch){
  //Serial.print(tm.Hour);Serial.print(":");Serial.print(tm.Minute);Serial.print(":");Serial.println(tm.Second);
  //Serial.println(tm.Hour*60+tm.Minute);
  byte On = 0;
  for (byte i=0;i<16;i++){
    //int mt=newCh[_ch].time[i].Hour*60+newCh[_ch].time[i].Minute;
    int st=(newCh[_ch].time[i].Hour*60+newCh[_ch].time[i].Minute)*60; //chanell time point in second
    int ct=(tm.Hour*60+tm.Minute)*60+tm.Second;                       //Systwem time in second
    
    if ((ct>=st) and (ct<=st+newCh[_ch].value[i])) {
        On=1;
        //Serial.print(tm.Hour);Serial.print(":");Serial.print(tm.Minute);Serial.print(":");Serial.print(tm.Second);Serial.print(" SwitchOn CH:");Serial.println(_ch);
        break;
     } 
  }
  if ((On==1) and (newCurrent[_ch]!=4095)) {
     newCurrent[_ch]=4095;     
     invPWM(_ch,newCurrent[_ch]);
     Serial.print(tm.Hour);Serial.print(":");Serial.print(tm.Minute);Serial.print(":");Serial.print(tm.Second);Serial.print(" SwitchOn CH:");Serial.println(_ch);
  }
  if ((On==0) and (newCurrent[_ch]!=0)) {
    newCurrent[_ch]=0;
    invPWM(_ch,newCurrent[_ch]);
    Serial.print(tm.Hour);Serial.print(":");Serial.print(tm.Minute);Serial.print(":");Serial.print(tm.Second);Serial.print(" SwitchOff CH:");Serial.println(_ch);

    
  }
}
void setFan(byte _ch){
        if (cSensor==0) {
          newCurrent[_ch]=4095;
          invPWM(_ch,newCurrent[_ch]);
          return;
        }
        byte tMin=newCh[_ch].time[0].Hour;
        byte tMax=newCh[_ch].time[0].Minute;
        
        int fanMin=newCh[_ch].value[0];
        float tCurrent;
      if (sensors.validAddress(Sensor[newCh[_ch].type].addr)){
        
        tCurrent=Sensor[newCh[_ch].type-16].Temp;
        if (tCurrent<15){
           newCurrent[_ch]=4095;
           invPWM(_ch,newCurrent[_ch]);
           return;
        }
        if (tCurrent<=tMin){
          newCurrent[_ch]=fanMin;
          invPWM(_ch,newCurrent[_ch]);
          return;
        }  
        if (tCurrent>=tMax) {
          newCurrent[_ch]=4095;
          invPWM(_ch,newCurrent[_ch]);
          return;
        }  
        newCurrent[_ch]=map (tCurrent, tMin,tMax,fanMin,4095);
        invPWM(_ch,newCurrent[_ch]);
        if (cSensor==0) {
          newCurrent[_ch]=4095;
          invPWM(_ch,newCurrent[_ch]);
          return;     
        }
      }else {
        newCurrent[_ch]=4095;
        invPWM(_ch,newCurrent[_ch]);
      }
}

int getPWM(byte Ch,unsigned long Tp){
   float a=0,b=0,_value=0;
    for (byte i=0;i<15;i++){
      if (newCh[Ch].value[i+1]<0) {
        return newCh[Ch].value[i];
      }
      unsigned long time_a=(newCh[Ch].time[i].Hour*60+newCh[Ch].time[i].Minute)*60000;
      if (Tp<time_a) {
        return newCh[Ch].value[i];
      }
      unsigned long time_b=(newCh[Ch].time[i+1].Hour*60+newCh[Ch].time[i+1].Minute)*60000;
      if ((Tp>time_a) and (Tp<time_b)){
        a=newCh[Ch].value[i+1]-newCh[Ch].value[i];
        a=a/(time_b-time_a);
        b=newCh[Ch].value[i]-time_a*a;
        _value=a*Tp+b;
        return int(_value);
      }
    }
    return int(_value);
  }
  void setChannelPWM(byte _ch){
    if (group[newCh[_ch].group].isAlarm==1) 
      return; 
    if (newCh[_ch].group==playTime) {
      invPWM(_ch,newCurrent[_ch]);
      return;
    }
    if (playTime==0) {
      invPWM(_ch,newCurrent[_ch]);
      return;
    }
    if (playTime==newCh[_ch].type){
      return;
    }
    if (newCh[_ch].type!=0){
      if (newCh[_ch].type>15) {
        setFan(_ch);
      }
      if ((newCh[_ch].type==1) or (newCh[_ch].type==2)){
        Dosing(_ch);
      }
      return;
    }
    if (EmLight==1){
        if (emLight[_ch]!=-1) {
          newCurrent[_ch]=emLight[_ch];
          invPWM(_ch,newCurrent[_ch]);
          return;
        } else {
          if (newCh[_ch].type==0) {
            if (newCurrent[_ch]!=newCh[_ch].value[0]) {
              newCurrent[_ch]=newCh[_ch].value[0];
              invPWM(_ch,newCurrent[_ch]);
              return;
            }
          }
        }
        return;
    }
      byte _alarmIndex=group[newCh[_ch].group].alarmIndex;
      if (_alarmIndex<8) {
      }
      int _value=getPWM(_ch,msCurrent);
      if (_value!=newCurrent[_ch]) {
        newCurrent[_ch]=_value;
        invPWM(_ch, newCurrent[_ch]);
      }
    }
  
  void invPWM(byte _ch,int _value){
    if (_value>4095) _value=4095;
    if (_value<0) _value=0;
    if (newCh[_ch].Inv==0) pwm.setPWM(_ch, 0, _value); else pwm.setPWM(_ch, 0, (4095 - _value)); 
  }
  void convertPWM(){
    
  for (byte i=0;i<16;i++){
    newCh[i].value[0]=ch[i].Min;
    newCh[i].value[1]=ch[i].Max;
    newCh[i].value[2]=ch[i].Max;
    newCh[i].value[3]=ch[i].Min;
    newCh[i].time[0].Hour=ch[i].Sunrise.Hour;
    newCh[i].time[0].Minute=ch[i].Sunrise.Minute;
    newCh[i].time[1].Hour=ch[i].Day.Hour;
    newCh[i].time[1].Minute=ch[i].Day.Minute;
    newCh[i].time[2].Hour=ch[i].Sunset.Hour;
    newCh[i].time[2].Minute=ch[i].Sunset.Minute;
    newCh[i].time[3].Hour=ch[i].Night.Hour;
    newCh[i].time[3].Minute=ch[i].Night.Minute;
    newCh[i].Inv=ch[i].Inv;
    memcpy(newCh[i].name,ch[i].Desc,sizeof ch[i].Desc);
  }
}

