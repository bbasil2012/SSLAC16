OS=`uname`
M=`uname -m`
DIR=`uname`'-'`uname -m`

$DIR/esptool -v -cd nodemcu -cp $1 -cb $2 -ca 0x00000000 -cf ../bin/4mb/0x0-SSLAC16-latest.bin
