# esp2leds16ch-PWM
SSLAC16

16-channel PWM controller entry for the aquarium LED light

￼What you need:

1. ESP8266 board
￼￼2. PWM PCA9685 board
3. The real-time clock DS1307 board or RTC PCF8563 board (optional)
￼￼4. DS18x20 (optional)
What's the result:
1. 16 channels of 12-bit control (4096 steps) with a frequency of 50 - 1500Hz (can be
customized)
2. Each channel has independent settings, to set the time for the sunrise/day/sunset/
night.
3. Each channel has individual adjustment of the PWM value for the day / night.
PWM value for sunrise / sunset are calculated automatically.
4. Each channel may be associated with one of the sensors DS18x20. In this case,
the PWM value of this channel will be calculated based on readings of the
temperature sensor. Any temperature sensor can be attached to any channels.
5. Each channel can have individual settings for inverting the PWM signal.
6.Emergency light - all channels are set using the maximum value. Activated by
pressing «flash» button module esp8266. Deactivated by pressing again.
6. WEB management interface.
7. The ability to create and upload their own HTML pages management interface.
8. WIFI Access Point, and both WIFI Station
How to flashing firmware in ESP8266:
1. read the notes and hints on connecting to a computer ESP8266 https://
github.com/esp8266/Arduino/blob/master/doc/boards.md
2. For firmware highly recommend esptool
https://github.com/igrr/esptool-ck/releases
3. Flashing the main firmware file.
esptool -v -cp <COM port> -cb 115200 -ca 0x00000000 -cf 0x00000000.bin
4. Flashing the data file:
esptool -v -cp / <COM port> -cb 115200 -ca 0x0006b000 -cf 0x0006b000.bin
5. Reboot ESP8266
6. After a reboot of the module in the list of available networks should appear WIFI
network named esp8266_xxxxxxxx, connect to the network using as password last
digits (xxxxxxxx) of network name
7. Open your browser page http: /192.168.4.1
...
Author: bbasil2012@gmail.com
Thanks Google translator for the translation :)
