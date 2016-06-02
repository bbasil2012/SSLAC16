#SSLAC16
(actual version 0.36rev0)

##Simple&Smart LED Aquarium Controller 16 channels 
controled over Wi-Fi via WEB interface.
(ESP8266 based)


###Why it is “simple”:
#####You need only 2 components and 5 wires for the full functionality.
#####No need to learn any programming language for micro-controllers.
#####No need to install on your computer any big and fat development environment, compile the source code, fix it etc. The necessary components are easily accessible.
#####Very low cost


###Why it is “smart”:
######version 0.36r0
"To control the light in real time"


#####16 "time points."
individually for each light control channel. (Total maximum of 256 points)
 
#####16 control channels.
Each control channel can specify your own name up to 32 characters (or 16 characters with the use of the national language in the 2-byte character set) That is a multi-language support channel names
The color display on the daily schedule can be set and changed by the user.
Each channel can be one of two types:
-channel light control.
-channel control cooling fan.
 
#####8 groups of channels. (Yes, now the channels can be randomly scattered on 8 groups)
For each group, you can specify your own name up to 32 characters (or 16 characters with the use by the national language 2-byte encodings), multi-language support group names
Each group may contain any number of light control channels (0 to 16)
you can assign a "temperature alarm" Each channel group.
#####8 "temperature alarm"
For each channel group, you can set your own critical temperature and decreasing step dimming values ​​for the channels of the group.
#####"PlayTime" function
Using this feature, you can see in real time as will appear on your aquarium light at any given time.
Functions can be applied both to all channels at once, and to any group of channels.
 
#####Mode. "Emergency light"
May use any number of light control channels. Each used channel has individual dimming settings for this mode.
 
#####8 temperature sensors tip.DS18x20
Each temperature sensor can control any number of cooling channels and control any number of "temperature alarm"

###What do you need to purchase:
1. The module based ESP8266, recommend NodeMCU.
2. Module on PCA9685.
3. The power supply - will suit any battery charger from the mobile phone 5V and 300mA.
4. Optional: module "Real Time Clock" on the  PCF8563 or DS3231. (Support for DS1307 RTC also have but I do not recommend to use it)
5. Optional: temperature sensors type DS18x20.

###Updating firmware SSLAC.

We strongly recommend using a program that comes with Arduino IDE for ESP8266
Separately it can be downloaded at various  OS here: https://github.com/igrr/esptool-ck/releases

#####1 .The main firmware:
######Latest release can be found there: https://github.com/bbasil2012/SSLAC16/releases/latest
esptool -v -cp "COM-port" -cb 115200 -ca 0x00000000 -cf 0x0-SSLAC16-v0.36rev0.bin  
where "COM-port" name of COM port.  
For example on my Mac OS X NodeMCU designated as /dev/tty.SLAB_USBtoUART

You need restart your module and after restarting the module in the list of available WiFi networks should appear SSLAC_xxxxxxxx (Where xxxxxxxx - password) 
#####2. Additional file(SPIFFS image)
And now you can upload SPIFFS image by WiFi network from page http://194.168.4.1/rescue 
or upload all .html and .js files separately (I recomend upload files separately)


Connect to the network module, type http://192.168.4.1 in the address bar and ehjoy :)

Short video:
https://youtu.be/XsKu5m_CHkc
