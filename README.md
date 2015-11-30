# ￼SSLAC16

Simple&Smart LED Aquarium Controller 16 channels 
control over Wi-Fi via WEB interface.


Why is simple:

For the full functionality you need only 2 component and 5 wires.

No need to learn any programming language for micro-controllers.

No need to install on your computer any big and fat development environment, compile the source code, fix it etc.

The necessary components are easily accessible. 


Why smart:

1. 16 control channels. Dimming 12 bits (4096 steps) with a frequency from 50 to 1500Hz.

2. Each channel has individual settings 4 time points: start of the Sunrise, start of the Day (maximum mode), start of the Sunset, start of the Night (minimum mode)

3. For each channel individual setting fro  ​​dimming values of the Day and Night mode, the values ​​in transient conditions (sunrise / sunset) calculated by the controller itself.

4. Each channel can be configured Inverse mode - convenient when using LED drivers with different type of dimming.

5. In addition to the standard mode of operation channel, there is a possibility of the channel defined as a controlled fan cooling and "snap" them to any or temperature sensor. Number of temperature sensors up to 8. In this case, each sensor can be "linked" with any number of channels.

6. Each channel and each temperature sensor may have their own name (16 characters maximum)
This allows you to remove the need to remember a channel number which corresponds to.
You can simply write: Warm_white, Sump_fan etc. 
Likewise, you can give the names of the temperature sensor: T_LedModule1, T_MainTank etc.
And relate them to one-to-another only by their own names.
The controller itself can also have its own name: 1st_Room_control.

7. "Emergency light" - when suddenly the night you need to turn on the light in the aquarium - press the "flash" on the module ESP forcibly convert all channels into daily (maximum) mode. Pressing the button disables.

8. You can create and upload their own HTML pages for management

9. Experimental (use with caution) function for firmware and  file system image upgrade "on the air". Now there is no need to connect the computer cable to the controller for the upgrade - it can be done from the Web interface allowing commando download the appropriate file. (This feature is not available for modules with a capacity of flash memory 512kb)

10. The module works as both a client and a WiFi network as the "access point" - that is, it can be connected to an existing Wi-Fi network and can connect to it from any device.

11. Coming soon: master/slave mode for multiple controllers.


What you need to purchase:

1. The module based ESP8266, recommend NodeMCU.

2. Module on PCA9685.

3. The power supply - will suit any battery charger from the mobile phone 5V and 300mA.

4. Optional: module "Real Time Clock" on the  PCF8563. (Support for DS1307 RTC also have but I do not recommend to use it)

5. Optional: temperature sensors type DS18x20.


How to flashing firmware in ESP8266:

1. read the notes and hints on connecting to a computer ESP8266 https://
github.com/esp8266/Arduino/blob/master/doc/boards.md

2. For firmware highly recommend esptool
https://github.com/igrr/esptool-ck/releases

3. Flashing the main firmware file.
esptool -v -cp <COMport> -cb 115200 -ca 0x00000000 -cf 0x0<versiin>.bin

4. Flashing the SPIFF image data file

for 512kb module:
esptool -v -cp <COMport> -cb 115200 -ca 0x0006b000 -cf 0x6b<version).spifs.bin.bin

For 4mb module:
esptool -v -cp <COMport> -cb 115200 -ca 0x10000 -cf 0x1<version>.spiffs.bin

5. Reboot ESP8266

6. After a reboot of the module in the list of available networks should appear WIFI
network named SSLAC_xxxxxxxx, connect to the network using as password last
digits (xxxxxxxx) of network name

7. Open your browser page http: /192.168.4.1

Author: bbasil2012@gmail.com

Thanks Google translator for the translation :)


