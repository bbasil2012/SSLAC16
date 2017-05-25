@win32\curl -s  -F filedata=@..\data\1SetUp.html http://192.168.4.1/upload
@win32\curl -s  -F filedata=@..\data\EmLight.html http://192.168.4.1/upload
@win32\curl -s  -F filedata=@..\data\Fan.html http://192.168.4.1/upload
@win32\curl -s  -F filedata=@..\data\Master_Slave.html http://192.168.4.1/upload
@win32\curl -s  -F filedata=@..\data\favicon.ico http://192.168.4.1/upload
@win32\curl -s  -F filedata=@..\data\root_page.html http://192.168.4.1/upload
@win32\curl -s  -F filedata=@..\data\setuphw.html http://192.168.4.1/upload
@win32\curl -s  -F filedata=@..\data\sslac.js http://192.168.4.1/upload
@echo "rebooting now..."
@win32\curl -s "http://192.168.4.1/set?reboot="