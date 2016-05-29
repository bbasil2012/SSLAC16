win32\esptool -v -cd nodemcu -cp %1 -cb 115200 -ca 0x00000000 -cf ..\bin\4mb\0x0-SSLAC16-latest.bin
@pause
cmdinfo
echo test
