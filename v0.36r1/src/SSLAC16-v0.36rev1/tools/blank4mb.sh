OS=`uname`
M=`uname -m`
DIR=`uname`'-'`uname -m`

$DIR/esptool -v -cd nodemcu -cp $1 -cb 115200 -ca 0x00000000 -cf blank4M.bin

