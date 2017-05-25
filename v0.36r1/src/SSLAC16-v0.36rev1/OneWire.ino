void scanDS18x20(){
  byte isNew=0; // 0 - новый, 1 - уже запомненый
  byte _addr[8]={0,0,0,0,0,0,0,0};
  oneWire.reset();
  sensors.begin();
  cSensor=sensors.getDeviceCount();
  // проверяем сенсоры на наличие их описания
  for (byte i=0; i<cSensor;i++) {
    if (sensors.getAddress(addr,i)) {
        isNew=0;
        for (byte j=0;j<8;j++){
            if (memcmp(addr,Sensor[j].addr,sizeof Sensor[j].addr)==0) {
                Sensor[j].index=i;
                isNew=1;   
             } 
        }
        if (isNew==0) {
            byte k=0;
            while (k<8){
                if (memcmp(Sensor[k].addr,_addr,sizeof _addr)==0) {
                  // нашли первый свободный
                    memcpy(Sensor[k].addr,addr,sizeof addr);
                    Sensor[k].index=i;
                    String _desc="Sensor_"+String(i);
                    _desc.toCharArray(Sensor[k].Desc,sizeof _desc);
                    k=8; 
                }
                k++;
            }
        }
     }
  }
}

void clearDS18x20(){
  char _desc[16]="";
  byte _addr[8]={0,0,0,0,0,0,0,0};
  for (byte i=0;i<8;i++){
    Sensor[i].index=255;
    memcpy(Sensor[i].Desc,_desc,sizeof _desc);
    memcpy(Sensor[i].addr,_addr,sizeof _addr);
  }
}




