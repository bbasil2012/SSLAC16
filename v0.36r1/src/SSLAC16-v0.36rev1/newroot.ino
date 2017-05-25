void _get(){
    int value;
    snprintf(stream,1024,"%s\n\r","Not implemented");
    
    if (server.method()==HTTP_GET) {

        if (server.argName(0)=="alarmN"){
          snprintf(stream,1024,"\
[[%d,%d],\n\r[%d,%d],\n\r[%d,%d],\n\r[%d,%d],\n\r\
[%d,%d],\n\r[%d,%d],\n\r[%d,%d],\n\r[%d,%d],\n\r\
[%d,%d],\n\r[%d,%d],\n\r[%d,%d],\n\r[%d,%d],\n\r\
[%d,%d],\n\r[%d,%d],\n\r[%d,%d],\n\r[%d,%d]]\n\r",
newAlarm[0].index,newAlarm[0].temp,newAlarm[1].index,newAlarm[1].temp,newAlarm[2].index,newAlarm[2].temp,newAlarm[3].index,newAlarm[3].temp,\
newAlarm[4].index,newAlarm[4].temp,newAlarm[5].index,newAlarm[5].temp,newAlarm[6].index,newAlarm[6].temp,newAlarm[7].index,newAlarm[7].temp,\
newAlarm[8].index,newAlarm[8].temp,newAlarm[9].index,newAlarm[9].temp,newAlarm[10].index,newAlarm[10].temp,newAlarm[11].index,newAlarm[11].temp,\
newAlarm[12].index,newAlarm[12].temp,newAlarm[13].index,newAlarm[13].temp,newAlarm[14].index,newAlarm[14].temp,newAlarm[15].index,newAlarm[15].temp);          
          server.send(200,text_json,stream);
          return;
        }
        
        if (server.argName(0)=="emLightN"){
          snprintf(stream,1024,"[%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d]\n\r",\
          emLight[0],emLight[1],emLight[2],emLight[3],emLight[4],emLight[5],emLight[6],emLight[7],\
          emLight[8],emLight[9],emLight[10],emLight[11],emLight[12],emLight[13],emLight[14],emLight[15]);
          server.send(200,text_json,stream);
          return;
        }
        if (server.argName(0)=="chN"){
          if(server.arg(0)=="name"){
            snprintf(stream,1024,"[\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"]\n\r",\
            newCh[0].name,newCh[1].name,newCh[2].name,newCh[3].name,newCh[4].name,newCh[5].name,newCh[6].name,newCh[7].name,\
            newCh[8].name,newCh[9].name,newCh[10].name,newCh[11].name,newCh[12].name,newCh[13].name,newCh[14].name,newCh[15].name);
            server.send(200,text_json,stream);
            return;
          }
          if (server.arg(0)=="current"){
            snprintf(stream,1024,"[%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d]\n\r",\
            newCurrent[0],newCurrent[1],newCurrent[2],newCurrent[3],newCurrent[4],newCurrent[5],newCurrent[6],newCurrent[7],
            newCurrent[8],newCurrent[9],newCurrent[10],newCurrent[11],newCurrent[12],newCurrent[13],newCurrent[14],newCurrent[15]);
            server.send(200,text_json,stream);
            return;
          }
          if ((server.arg(0)=="All") or (server.arg(0)=="")){
            server.send(200,text_json,"[]");
            return;
            
          }else {
            byte _ch=server.arg(0).toInt();
            //Serial.print("getting channel:");Serial.println(_ch);
            snprintf(stream,1024,"[\
[%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d],\n\r\
[%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d],\n\r\
[%d,%d,%d],\n\r\
[%d],\n\r\
[%d],\n\r\
[%d],\n\r\
[\"%s\"]]\n\r",\
newCh[_ch].value[0],newCh[_ch].value[1],newCh[_ch].value[2],newCh[_ch].value[3],\
newCh[_ch].value[4],newCh[_ch].value[5],newCh[_ch].value[6],newCh[_ch].value[7],\
newCh[_ch].value[8],newCh[_ch].value[9],newCh[_ch].value[10],newCh[_ch].value[11],\
newCh[_ch].value[12],newCh[_ch].value[13],newCh[_ch].value[14],newCh[_ch].value[15],\
(newCh[_ch].time[0].Hour*60+newCh[_ch].time[0].Minute),(newCh[_ch].time[1].Hour*60+newCh[_ch].time[1].Minute),\
(newCh[_ch].time[2].Hour*60+newCh[_ch].time[2].Minute),(newCh[_ch].time[3].Hour*60+newCh[_ch].time[3].Minute),\
(newCh[_ch].time[4].Hour*60+newCh[_ch].time[4].Minute),(newCh[_ch].time[5].Hour*60+newCh[_ch].time[5].Minute),\
(newCh[_ch].time[6].Hour*60+newCh[_ch].time[6].Minute),(newCh[_ch].time[7].Hour*60+newCh[_ch].time[7].Minute),\
(newCh[_ch].time[8].Hour*60+newCh[_ch].time[8].Minute),(newCh[_ch].time[9].Hour*60+newCh[_ch].time[9].Minute),\
(newCh[_ch].time[10].Hour*60+newCh[_ch].time[10].Minute),(newCh[_ch].time[11].Hour*60+newCh[_ch].time[11].Minute),\
(newCh[_ch].time[12].Hour*60+newCh[_ch].time[12].Minute),(newCh[_ch].time[13].Hour*60+newCh[_ch].time[13].Minute),\
(newCh[_ch].time[14].Hour*60+newCh[_ch].time[14].Minute),(newCh[_ch].time[15].Hour*60+newCh[_ch].time[15].Minute),\
newCh[_ch].color[0],newCh[_ch].color[1],newCh[_ch].color[2],\
newCh[_ch].group,\
newCh[_ch].type,\
newCh[_ch].Inv,\
newCh[_ch].name);
             server.send(200,text_json,stream);
             return;
          }
        }

      
        if (server.argName(0)=="wifi"){
            if (server.arg(0)=="disconnect") {
              server.send(200,text_plain,F("\n\r"));
              WiFi.disconnect();
              isConn=0;
              return;
            }
            if (server.arg(0)==""){
               WiFi.scanDelete();
               snprintf(stream,1024,"[%d]\n\r",WiFi.scanNetworks());
            } else {
              snprintf(stream,1024,"[\"%s\",%d,%d,%d,%d,%d]\n\r",\
              WiFi.SSID(server.arg(0).toInt()).c_str(),\
              WiFi.encryptionType(server.arg(0).toInt()),\
              WiFi.RSSI(server.arg(0).toInt()),\
              WiFi.BSSID(server.arg(0).toInt()),\
              WiFi.channel(server.arg(0).toInt()),\
              WiFi.isHidden(server.arg(0).toInt()));
            }
            server.send(200,text_json,stream);
            return;
        }
        if ((server.argName(0)=="ssid") and (server.arg(0)=="") and (isConn==1)) {
          server.send(200,text_json,"[\""+ssid+"\"]\n\r");
          return;
        }
        if (server.argName(0)=="info") {
           if (server.arg(0)=="") {
                snprintf(stream,1024,"[\
                [%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s],\n\r\
                [%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\"%s\",\"%s\",%d,%d,%d,\"%s\",%d,%d,%d,%d,\"%s\"],\n\r\
                [%d,%d,%d],\n\r\
                [%d,%d,%d,%d],\n\r\
                [%d],\n\r\
                [\"%s\",\"%s\",\"%s\",\"%s\"],\n\r\
                [%d,%d,%d,%d,%d]]\n\r",
                "\"isMode\"","\"isSetupCh\"","\"channelGroup\"","\"isAlone\"",\
                "\"pwmFreq\"","\"EmLight\"","\"pSDA\"","\"pSCL\"","\"pOneWire\"",\
                "\"isConn\"","\"IP\"","\"SSID\"","\"isPCA\"","\"isRCT\"",\
                "\"is_time_set\"","\"hostname\"","\"isMaster\"","\"isSlave\"","\"ID\"","\"Sender_ID\"",\
                isMode,isSetupCh,channelGroup,isAlone,\
                pwmFreq,EmLight,pSDA,pSCL,pOneWire,\
                isConn,WiFi.localIP().toString().c_str(),ssid.c_str(),isPCA,isRTC,\
                is_time_set,esp_hostname.c_str(),isMaster,isSlave,ESP.getChipId(),sPacket.sender_id,WiFi.softAPIP().toString().c_str(),\
                tm.Hour,tm.Minute,tm.Second,\
                _millis/3600000/24,\ //Uptime days
                _millis/3600000%24,\ //Uptime hours
                _millis/60000%60,\   //Uptime minutes
                _millis/1000%60,\    //Uptime seconds
                Time_Zone,\
                "isAlarm","tAlarm.index","tAlarm.temp","tAlarm.step",\
                isAlarm,tAlarm.index,tAlarm.temp,tAlarm.step,isHidePassword);
                server.send(200,text_json,stream);
                return;
           }
           if (server.arg(0)=="0"){
              snprintf(stream,1024,"[[%d,%d,%d],\n\r[%d,%d,%d,%d],\n\r[%d],\n\r[%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d]]\n\r",\
              tm.Hour,tm.Minute,tm.Second,\
              _millis/3600000/24,\ //Uptime days
              _millis/3600000%24,\
              //Uptime hours
              _millis/60000%60,\
              //Uptime minutes
              _millis/1000%60,\
              //Uptime seconds
              Time_Zone,\
              newCurrent[0],newCurrent[1],newCurrent[2],newCurrent[3],newCurrent[4],newCurrent[5],newCurrent[6],newCurrent[7],\
              newCurrent[8],newCurrent[9],newCurrent[10],newCurrent[11],newCurrent[12],newCurrent[13],newCurrent[14],newCurrent[15]);
              server.send(200,text_json,stream);
              return;
           }
           if (server.arg(0)="1"){
              snprintf(stream,1024,"[\
[%d,%d,%d,%d],\n\r\
[%d,%d,%d],\n\r\
[\"%s\",\"%s\",\"%s\",\"%s\",%d,%d],\n\r\
[%d]]\n\r",\
              tm.Hour,tm.Minute,tm.Second,Time_Zone,\
              pSDA,pSCL,pwmFreq,\
              esp_hostname.c_str(),WiFi.localIP().toString().c_str(),ssid.c_str(),WiFi.softAPIP().toString().c_str(),foundedNet,isConn,cSensor);   
              server.send(200,text_json,stream);
              return;         
           }
           
        }
        if (server.argName(0)=="alarm") {
          snprintf(stream,1024,"[%d,%d,%d]\n\r",tAlarm.index,tAlarm.temp,tAlarm.step);
          server.send(200,text_json,stream);
          return;
        }
        if (server.argName(0)=="version") {
          
          snprintf(stream,1024,"[\"%s\",%d,%d,%d,\"%s\",\"%s\"]",\
          "SSLAC16",version[0],version[1],version[2],__DATE__,__TIME__);
          //Serial.println(stream);
          server.send(200,text_json,stream);
          return;
        }
        if (server.argName(0)=="time"){
           if (server.arg(0)==""){
              snprintf(stream,1024,"[\
              [%d,%d,%d],\n\r\
              [%d,%d,%d,%d],\n\r\
              [%d]]\n\r",\
              tm.Hour,tm.Minute,tm.Second,\
              _millis/3600000/24,\
              _millis/3600000%24,\
              _millis/60000%60,\ 
              _millis/1000%60,\ 
              Time_Zone);
              server.send(200,text_json,stream);
              return;
           }
         
        }
        if (server.argName(0)=="temp"){
          if (server.arg(0)==""){
            snprintf(stream,1024,"[%d]\n\r",cSensor);
            } else {
              value = server.arg(0).toInt();
                  snprintf(stream,1024,"[%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\"%s\"]\n\r",\
                  Sensor[value].addr[0],\
                  Sensor[value].addr[1],\
                  Sensor[value].addr[2],\
                  Sensor[value].addr[3],\
                  Sensor[value].addr[4],\
                  Sensor[value].addr[5],\
                  Sensor[value].addr[6],\
                  Sensor[value].addr[7],\
                  Sensor[value].index,\
                  int(Sensor[value].Temp*1000),\
                  Sensor[value].Desc);
              //}
          }
          server.send(200,text_json,stream);
          return;
        }
        if (server.argName(0)=="grN"){
          if ((server.arg(0)=="all") or (server.arg(0)=="")){
             snprintf(stream,1024, "[[\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"],\n\r\
             [%d,%d,%d,%d,%d,%d,%d,%d],\n\r\
             [%d,%d,%d,%d,%d,%d,%d,%d],\n\r\
             [%d,%d,%d,%d,%d,%d,%d,%d],\n\r\
             [%d,%d,%d,%d,%d,%d,%d,%d]]\n\r",\
              group[0].name,\
              group[1].name,\
              group[2].name,\
              group[3].name,\
              group[4].name,\
              group[5].name,\
              group[6].name,\
              group[7].name,\
              group[0].alarmIndex,group[1].alarmIndex,group[2].alarmIndex,group[3].alarmIndex,group[4].alarmIndex,group[5].alarmIndex,group[6].alarmIndex,group[7].alarmIndex,\
              group[0].temp,group[1].temp,group[2].temp,group[3].temp,group[4].temp,group[5].temp,group[6].temp,group[7].temp,\
              group[0].step,group[1].step,group[2].step,group[3].step,group[4].step,group[5].step,group[6].step,group[7].step,\
              group[0].isAlarm,group[1].isAlarm,group[2].isAlarm,group[3].isAlarm,group[4].isAlarm,group[5].isAlarm,group[6].isAlarm,group[7].isAlarm\
              );
              server.send(200,text_json,stream);
          
          return;
          }
        }
        
    }
 
}
void _set(){
  int value;
  if (server.method()==HTTP_POST){
    server.send(200,text_plain,F("\n\r"));

if ((server.argName(0)=="ssid") and (server.argName(1)=="passwd")) {
          ssid=server.arg(0);
          password=server.arg(1);
          isConn=false;
          WiFi.disconnect(true);
          WiFi.begin(ssid.c_str(), password.c_str());
            tmp_a=0;
            while (WiFi.status() != WL_CONNECTED) {
              delay(500);
                Serial.print(F("."));
                tmp_a++;
                isConn=true;
                if (tmp_a>128) {
                    isConn=false;
                    break;
                }
            }
          
        }


    
    if (server.argName(0)=="grN") {
          if ((server.arg(0)!="all") and (server.arg(0)!="")) {
            byte _gr=server.arg(0).toInt();
            server.arg(1).toCharArray(group[_gr].name,server.arg(1).length()+1);
          }
     }
     if (server.argName(0)=="chN") {
        if ((server.arg(0)!="all") and (server.arg(0)!="")){
          byte _ch=server.arg(0).toInt();
          server.arg(1).toCharArray(newCh[_ch].name,server.arg(1).length()+1); 
        }
     }

  }
  if (server.method()==HTTP_GET) {
        server.send(200,text_plain,F("\n\r"));
        if (server.argName(0)=="GPIO") {
            return;          
        }
        if (server.argName(0)=="i2c") {
          return;
        }
        if (server.argName(0)=="1wire") {
          if (server.arg(0)=="rescan") {
            scanDS18x20();
            return;
          }
          if (server.arg(0)=="clear"){
            clearDS18x20();
            cSensor=0;
            return;
          }
        }
        if (server.argName(0)=="hostname") {
          esp_hostname="";
          esp_hostname=server.arg(0);
        }
        if (server.argName(0)=="time") {
          for (byte i=0; i<server.args(); i++) {
            if (server.argName(i)=="h") tm.Hour=server.arg(i).toInt();
            if (server.argName(i)=="m") tm.Minute=server.arg(i).toInt();
            if (server.argName(i)=="s") tm.Second=server.arg(i).toInt();
            if (server.argName(i)=="tz") Time_Zone=server.arg(i).toInt();
            if (is_time_set == 0) is_time_set=1;
          }
          msStart=0;
          msCurrent=(tm.Hour*3600+tm.Minute*60+tm.Second+1)*1000;
          ticker();
          setTimeRTC();
          return;
        }
        if ((server.argName(0)=="ssid") and (server.argName(1)=="passwd")) {
          ssid=server.arg(0);
          password=server.arg(1);
          isConn=false;
          WiFi.disconnect(true);
          WiFi.begin(ssid.c_str(), password.c_str());
            tmp_a=0;
            while (WiFi.status() != WL_CONNECTED) {
              
              delay(500);
                tmp_a++;
                isConn=true;
                if (tmp_a>128) {
                    isConn=false;
                    break;
                }
            }
          
        }
            
        if (server.argName(0)=="isMode") {
            if (isSlave==0) isMode=server.arg(0).toInt();
            return;
        } 
        if (server.argName(0)=="isSetupCh") {
            return;
        } 
        if (server.argName(0)=="channelGroup") {
            if (isSlave==0) channelGroup=server.arg(0).toInt();
            return;
        } 
        if (server.argName(0)=="isAlone") {isAlone=server.arg(0).toInt();
            return;
        }
        if (server.argName(0)=="pwmFreq") {pwmFreq=server.arg(0).toInt();
            return;
        }
        if (server.argName(0)=="EmLight") {
            EmLight=server.arg(0).toInt();
            return;
        }
        if (server.argName(0)=="isHidePassword") {
            isHidePassword=server.arg(0).toInt();
            return;
        }
        if (server.argName(0)=="pSDA") {pSDA=server.arg(0).toInt();return;}
        if (server.argName(0)=="pSCL") {pSCL=server.arg(0).toInt();return;}
        if (server.argName(0)=="pOneWire") {pOneWire=server.arg(0).toInt();return;}
        if (server.argName(0)=="isMaster") {
          isMaster=server.arg(0).toInt();
          if (isMaster==1) {
            isSlave=0;
          }
          return;
        }
        if (server.argName(0)=="isSlave") {
          isSlave=server.arg(0).toInt();
          if (isSlave==1) isMaster=0; 
          return;
        }
        if (server.argName(0)=="temp") {
            value=server.arg(0).toInt();
            server.arg(1).toCharArray(Sensor[value].Desc,16);
        }  
        if (server.argName(0)=="emLightN"){
          emLight[server.arg(0).toInt()]=server.arg(1).toInt();
          return;
        }
        if (server.argName(0)=="save"){
          saveall();
          return;
        }
        if (server.argName(0)=="reboot"){
          reboot();
          return;
        }
        if (server.argName(0)=="alarmN"){
          byte _ch=server.arg(0).toInt();
          for (byte i=1;i<server.args();i++){
            if (server.argName(i)=="index") newAlarm[_ch].index=server.arg(i).toInt();
            if (server.argName(i)=="temp") newAlarm[_ch].temp=server.arg(i).toInt();
            if (server.argName(i)=="step") newAlarm[_ch].step=server.arg(i).toInt();
          }
        }
        if (server.argName(0)=="tpN"){
          byte _ch=server.arg(0).toInt();
          
          for (byte i=1;i<server.args();i++){
            newCh[_ch].time[server.argName(i).toInt()].Hour=server.arg(i).toInt()/60;
            newCh[_ch].time[server.argName(i).toInt()].Minute=server.arg(i).toInt() %60;
          }
          return;
        }
        if (server.argName(0)=="playTime"){
          playTime=server.arg(0).toInt();
        }
        if (server.argName(0)=="colorN"){
          byte _ch=server.arg(0).toInt();
          newCh[_ch].color[0]=server.arg(1).toInt();
          newCh[_ch].color[1]=server.arg(2).toInt();
          newCh[_ch].color[2]=server.arg(3).toInt();
          return;
        }
        if (server.argName(0)=="typeN"){
          byte _ch=server.arg(0).toInt();
          newCh[_ch].type=server.arg(1).toInt();
          return;
        }
        if (server.argName(0)=="invN"){
          byte _ch=server.arg(0).toInt();
          newCh[_ch].Inv=server.arg(1).toInt();
          return;
        }
        if ((server.argName(0)=="grN") and (server.argName(1)=="")){
          byte _ch=server.arg(0).toInt();
          newCh[_ch].group=server.arg(1).toInt();
          return;
        }
        if ((server.argName(0)=="grN") and (server.arg(0)!="")){
          byte _ch=server.arg(0).toInt();
          for (byte i=1;i<server.args();i++){
            if (server.argName(i)=="alarmIndex") group[_ch].alarmIndex=server.arg(i).toInt();
            if (server.argName(i)=="temp") group[_ch].temp=server.arg(i).toInt();
            if (server.argName(i)=="step") group[_ch].step=server.arg(i).toInt();
          }
          return;
        }
        if ((server.argName(0)=="addTp") and (server.arg(0)!="")){
          int _tp=server.arg(0).toInt();
          byte _gr=255;
          byte _Ch=255;
          int _Value=-1;
          if ((server.argName(1)=="group") and (server.arg(1)!="")){
            _gr=server.arg(1).toInt();
          }
          if ((server.argName(2)=="chN") and (server.arg(2)!="")){
            _Ch=server.arg(2).toInt();
          }
          if ((server.argName(3)=="val") and (server.arg(3)!="")){
            _Value=server.arg(3).toInt();
          }
          
          addTp(_tp,_gr,_Ch,_Value);
          return;
        }
        if (server.argName(0)=="chN"){
          if(server.arg(0)!="all") {
            byte _ch=server.arg(0).toInt();
            for (byte i=1;i<server.args();i++){
              int _value=server.arg(i).toInt();
              newCh[_ch].value[server.argName(i).toInt()]=_value;
              newCurrent[_ch]=_value;
              invPWM(_ch, newCurrent[_ch]);
  
            }
          }
           else {
            for (byte i=1;i<server.args();i++){
              byte _ch=server.argName(i).toInt();
              newCurrent[_ch]=server.arg(i).toInt();
            }
           }
            return;
        }
    }
}
void handleNotFound(){
  if (server.uri().endsWith(".pdf")) server.send(404,text_plain,F("May be You are using 512k module\n\rIn this case no room for manual, sorry."));  
   String _resp="Not found "+server.uri()+"\n";
   for (byte i=0;i<server.args();i++) {
    Serial.print("arg(");Serial.print(i);Serial.print(") - ");
    Serial.println(server.argName(i)+" : "+server.arg(i));
   }
   server.send(404,text_plain,_resp);
   
 
}


byte returnIndex(int _tp, byte _ch){
  byte _index=0;
  if (newCh[_ch].time[0].Hour*60+newCh[_ch].time[0].Minute>_tp) return _index;
  for (byte i=0;i<15;i++) {
    _index=i+1;
    if (newCh[_ch].time[i].Hour*60+newCh[_ch].time[i].Minute==0) {
      _index=i;
      return _index;
    }
    if ((newCh[_ch].time[i].Hour*60+newCh[_ch].time[i].Minute<_tp) and (newCh[_ch].time[i+1].Hour*60+newCh[_ch].time[i+1].Minute>_tp)) return _index;
  }
}




void addTpCh(int _tp, byte _ch, byte _index,byte _Channel, int _Value){
  _shed _time[16];
  int _value[16];
  if (_Value!=-1) {
    
    return;
  }
  for (byte i=0;i<15;i++){
    if (i<_index){
      _time[i].Hour=newCh[_ch].time[i].Hour;
      _time[i].Minute=newCh[_ch].time[i].Minute;
      _value[i]=newCh[_ch].value[i];
    }
    if (i>_index){
      _time[i].Hour=newCh[_ch].time[i-1].Hour;
      _time[i].Minute=newCh[_ch].time[i-1].Minute;
      _value[i]=newCh[_ch].value[i-1];
    }
    if (i==_index){
      _time[i].Hour=_tp/60;
      _time[i].Minute=_tp%60;
      _value[i]=newCurrent[_ch];
    }
  }
  memcpy(newCh[_ch].time,_time,sizeof _time);
  memcpy(newCh[_ch].value, _value, sizeof _value);
}
void addTp(int _tp,byte _gr, byte _Channel, int _Value){
  for (byte i=0;i<16;i++){
    if ((newCh[i].group==_gr) and (newCh[i].type==0)){
      addTpCh(_tp,i,returnIndex(_tp,i),_Channel,_Value);
    } else {
      if ((i==_Channel) and (newCh[i].type==0))
          addTpCh(_tp,i,returnIndex(_tp,i),_Channel,_Value);
    }
      
      
    }
  }

