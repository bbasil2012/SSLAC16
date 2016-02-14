 _URL='https://raw.githubusercontent.com/bbasil2012/SSLAC16/main/latest/';
 _HTML='data/index.txt';
 _FirmWare='bin/4mb/version'; 
 var _prg=0;
    function sv(){
          if (window.XMLHttpRequest){
            var xmlhttp=new XMLHttpRequest();
          }else{
            var xmlhttp=new ActiveXObject('Microsoft.XMLHTTP');
          }
          xmlhttp.open('GET','/sv',false);
          xmlhttp.send();
        }
        function sr(){
          if (window.XMLHttpRequest){
            var xmlhttp=new XMLHttpRequest();
          }else{
            var xmlhttp=new ActiveXObject('Microsoft.XMLHTTP');
          }
          xmlhttp.open('GET','/reboot',false);    xmlhttp.send();
        }
function get_rest(req){
  var resp;
  if (window.XMLHttpRequest){
     var xmlhttp=new XMLHttpRequest();
  }else{
     var xmlhttp=new ActiveXObject('Microsoft.XMLHTTP');
  }
  xmlhttp.onreadystatechange=function() {
     if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
       resp=JSON.parse(xmlhttp.responseText);
       return resp;
     }
  }
  xmlhttp.open('GET', '/get?'+req+'=', false);
  xmlhttp.send();
  return resp;  

}

function set_rest(req){
  if (window.XMLHttpRequest){
     var xmlhttp=new XMLHttpRequest();
  }else{
     var xmlhttp=new ActiveXObject('Microsoft.XMLHTTP');
  }
  xmlhttp.open('GET', '/set?'+req, false);
  xmlhttp.send();
  

}
function byteToHex(b) {
    var hexChar = ['0', '1', '2', '3', '4', '5', '6', '7','8', '9', 'A', 'B', 'C', 'D', 'E', 'F'];
        return hexChar[(b >> 4) & 0x0f] + hexChar[b & 0x0f];
}
function update_progress(e)
{
    console.log(_pID);
    if (e.lengthComputable)
    {
	var percentage = Math.round((e.loaded/e.total)*100);
	console.log("percent " + percentage + '%' );
	document.getElementById(_pID).value =percentage;
    }
    else 
    {
	console.log("Unable to compute progress information since the total size is unknown");
	//_prg++;
	//console.log(_prg);
	//document.getElementById(_pID).value =_pgr*10;
	
    }
}  

function get_version(){
    return get_rest('version');
}

  function uFirmWare(pID){
    var files=get_version_github(_URL,_FirmWare);
    setTimeout(updater(_URL+'bin/4mb/',files[0],pID));
    alert("FirmWare updated. Will be Rebooting.");
  }
  function uSPIFFS(pID){
    var files=get_version_github(_URL,_FirmWare);
    updater(_URL+'bin/4mb/','0x1-SSLAC16-latest.spiffs.bin',pID);
    alert("SPIFFS updated. Rebooting.");
  }
  
  function uHTML(pID){
    var files=get_version_github(_URL,_HTML);
    document.getElementById(pID).value =0;
    for (i=0;i<files.length; i++){
        setTimeout(updater(_URL+'data/',files[i],pID));
        //var percentage = Math.round( ((i+1)/Object.keys(files).length)*100 );
	//console.log("percent " + percentage + '%' );
	//document.getElementById(pID).value =percentage;
    }
    alert("User interface updated");
  }
  function get_version_github(uURL,uFileName) { 
  var resp;
 if (window.XMLHttpRequest){
     var xmlhttp=new XMLHttpRequest();
  }else{
     var xmlhttp=new ActiveXObject('Microsoft.XMLHTTP');
  }
  xmlhttp.onreadystatechange=function() {
     if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
       resp= JSON.parse(xmlhttp.responseText);
     }
  }
  xmlhttp.open('GET', uURL+uFileName, false);
  xmlhttp.send();
  return resp;
  }
  function updater(uURL,uFileName,pID) {
    sURL='/upload';
    
    _pID=pID;
    window.URL = window.URL || window.webkitURL;
    var xhr_dowload = new XMLHttpRequest();
    xhr_dowload.open('GET',uURL+uFileName , true);
    xhr_dowload.responseType = "blob";
    xhr_dowload.onprogress = update_progress;
    xhr_dowload.onload = function(e) {
      if (this.readyState == 4 && this.status == 200) {
        var blob = this.response;
        var fd = new FormData();
        fd.append("afile", blob,uFileName);
        var xhr = new XMLHttpRequest();
		
        xhr.onreadystatechange=function() {
   		 	if (xhr.readyState == 4) {
   				if (xhr.status == 200) {
					_prg++;
					console.log(_prg+":"+uFileName+" Done!!!");
					document.getElementById("pHTML").value =_prg*10;
					alert(uFileName+" - updated");
				}
		  	}
	 	}
		
		
        xhr.open('POST', sURL, false);
        xhr.send(fd);
      }
    };
  xhr_dowload.send();
  }
