void start_softAP(){
  if (esp_hostname.length()==0) esp_hostname="SSLAC";
  String SSID_AP =esp_hostname;
  SSID_AP+="_";
  String PASSWORD_AP;
  if (ESP.getChipId()<10000000){
    SSID_AP+=String(10000000+ESP.getChipId());
    PASSWORD_AP=String(10000000+ESP.getChipId());
  } else {
    SSID_AP+=String(ESP.getChipId());
    PASSWORD_AP=String(ESP.getChipId());
  }
  if (isHidePassword==1){
    SSID_AP=esp_hostname;
    if (isConn) PASSWORD_AP=password;
  }

  
  IPAddress local_ip(192,168,82,66);
  IPAddress gtw_ip(192,168,82,66);
  IPAddress netmask_ip(255,255,255,0);
  if (isMaster) WiFi.softAPConfig(local_ip,gtw_ip,netmask_ip);
  
  WiFi.softAP(SSID_AP.c_str(), PASSWORD_AP.c_str());
  Serial.print(F("Starting AP new : "));Serial.print(SSID_AP);Serial.print("/");Serial.println(PASSWORD_AP);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print(F("AP IP address: "));
  Serial.println(myIP);
 }

bool found_WIFI(String _SSID){
  foundedNet = WiFi.scanNetworks();
  bool result = false;
  if (foundedNet == 0) { 
      result=false;
  } else{
    for (int i = 0; i < foundedNet; ++i) {
      if (_SSID==WiFi.SSID(i)) {
          result=true;
          break;
      }
    }
  }
  return result;
}


