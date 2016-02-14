OS=`uname`
M=`uname -m`
DIR=`uname`'-'`uname -m`
echo $DIR
$DIR/esptool -v -cd nodemcu -cp $1 -cb 115200 -ca 0x00000000 -cf ../bin/$2/0x0-SSLAC16-latest.bin