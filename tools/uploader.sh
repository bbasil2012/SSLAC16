echo 'Upload Master_Slave.html'
curl -s  -F filedata=@../data/Master_Slave.html http://$1/upload >/dev/null
echo 'Upload favicon.ico'
curl -s  -F filedata=@../data/favicon.ico http://$1/upload >/dev/null
echo 'Upload set_ch.html'
curl -s  -F filedata=@../data/set_ch.html http://$1/upload >/dev/null
echo 'Upload set_sched.html'
curl -s  -F filedata=@../data/set_sched.html http://$1/upload >/dev/null
echo 'Upload set_wifi.html'
curl -s  -F filedata=@../data/set_wifi.html http://$1/upload >/dev/null
echo 'Upload cur_ch.html'
curl -s  -F filedata=@../data/cur_ch.html http://$1/upload >/dev/null
echo 'Upload root_page.html'
curl -s  -F filedata=@../data/root_page.html http://$1/upload >/dev/null
echo 'Upload set_i2c.html'
curl -s  -F filedata=@../data/set_i2c.html http://$1/upload >/dev/null
echo 'Upload set_time.html'
curl -s  -F filedata=@../data/set_time.html http://$1/upload >/dev/null
echo 'Upload sslac.js'
curl -s  -F filedata=@../data/sslac.js http://$1/upload >/dev/null

echo 'Set channels value...'
for ((i=0; i<16; i++))
do
#    curl http://$addr/rest?ch=$i&max=$j
    curl -s 'http://'$1'/set?tp='$i'&=sunrise&=7&=0' >/dev/null
    curl -s 'http://'$1'/set?tp='$i'&=day&=9&=0' >/dev/null
    curl -s 'http://'$1'/set?tp='$i'&=sunset&=21&=0' >/dev/null
    curl -s 'http://'$1'/set?tp='$i'&=night&=23&=0' >/dev/null
    curl -s 'http://'$1'/set?ch='$i'&desc=Channel_'$i >/dev/null

done

curl  -s 'http://'$1'/set?isSlave=0' >/dev/null
curl  -s 'http://'$1'/set?isMaster=0' >/dev/null
curl  -s 'http://'$1'/set?&time=&tz=157&h=15&m=50&s=3' >/dev/null
curl  -s 'http://'$1'/set?&pSDA=4' >/dev/null
curl  -s 'http://'$1'/set?&pSCL=5' >/dev/null

echo 'Saving...'
curl  -s 'http://'$1'/sv' >/dev/null
