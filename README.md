#SSLAC16

##Simple&Smart LED Aquarium Controller 16 channels 
controled over Wi-Fi via WEB interface.
(ESP8266 based)


###Why it is “simple”:
#####You need only 2 components and 5 wires for the full functionality.
#####No need to learn any programming language for micro-controllers.
#####No need to install on your computer any big and fat development environment, compile the source code, fix it etc. The necessary components are easily accessible.
#####Very low cost


###Why it is “smart”:

1. 16 channels. Dimming 12 bits of dept (4096 steps) with a frequency from 50 to 1500Hz.
2. Each channel has individual settings for 4 time points: start of the Sunrise, start of the Day (maximum mode), start of the Sunset, start of the Night (minimum mode)
3. For each channel individual setting for  ​​dimming values of the Day and Night mode, the values ​​in transient conditions (sunrise / sunset) calculated by the controller itself.
4. Each channel can be configured Inverse mode - convenient when using LED drivers with different type of dimming.
5. In addition to the standard mode of operation channel, there is a possibility of the channel defined as a controlled fan cooling and "snap" them to any or temperature sensor. Number of temperature sensors up to 8. In this case, each sensor can be "linked" with any number of channels.
6. Each channel and each temperature sensor may have their own name (16 characters maximum)
This allows you to remove the need to remember a channel number which corresponds to. 
You can simply write: Warm_white, Sump_fan etc.
Likewise, you can give the names of the temperature sensor: T_LedModule1, T_MainTank etc.
And (relate) link  them to one-to-another only by their own names.
The controller can also have its own name: 1st_Room_control.
7. "Emergency light" - when suddenly in the night you need to turn light ON in the aquarium - press the "flash" button on the module. SSLAC forcibly convert all channels into daily (maximum) mode. Pressing the button disables.
8. You can create and upload your own HTML pages for management.
9. Experimental  function (use with caution) for firmware and  file system image upgrade "on the air". Now there is no need to connect the computer cable to the controller for the upgrade - it can be done from the Web interface allowing command download the appropriate file. (This feature is not available for modules with a capacity of flash memory 512kb)
10. The module can to work as a client of existing Wi-Fi network and as WiFi "access point" - it can be connected to an existing Wi-Fi network and can connect to it from any device.
11. Coming soon: master/slave mode for multiple controllers.


###What you need to purchase:
1. The module based ESP8266, recommend NodeMCU.
2. Module on PCA9685.
3. The power supply - will suit any battery charger from the mobile phone 5V and 300mA.
4. Optional: module "Real Time Clock" on the  PCF8563. (Support for DS1307 RTC also have but I do not recommend to use it)
5. Optional: temperature sensors type DS18x20.

Updating firmware SSLAC.

We strongly recommend using a program that comes with Arduino IDE for ESP8266
Separately it can be downloaded at various  OS here: https://github.com/igrr/esptool-ck/releases

1 .The main firmware:
esptool -v -cp <COM-port> -cb 115200 -ca 0x00000000 -cf 0x0-SSLAC16-v0.35rev2.bin
where <COM-port> name COM port. For example on my Mac OS X NodeMCU designated as /dev/tty.SLAB_USBtoUART

2. Additional file(SPIFFS image)
for 4mb ESP8266 module:
esptool -v -cp / <COM-port> -cb 115200 -ca 0x00100000 -cf 0x1-SSLAC16-v0.35rev2.spiffs.bin

for 512k ESP8266 module:
esptool -v -cp / <COM-port> -cb 115200 -ca 0x0006b000 -cf 0x6-SSLAC16-v0.35rev2.spiffs.bin


3. After restarting the module in the list of available WiFi networks should appear SSLAC_xxxxxxxx Network

Connect to the network module
