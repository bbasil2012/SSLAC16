 _URL='https://raw.githubusercontent.com/bbasil2012/SSLAC16/main/latest/';
 _HTML='data/index.txt';
 _FirmWare='bin/4mb/version'; 
 var ii;
 var total;
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
/*function update_progress(e)
{
    alert("_pID");
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
    }
}  
*/
function get_version(){
    return get_rest('version');
}

  function uFirmWare(pID){
    var files=get_version_github(_URL,_FirmWare);
    updater(_URL+'bin/4mb/',files[0],pID);
    //alert("FirmWare updated. Rebooting.");
  }
  
  function uHTML(pID){
	  
	ii=0;
	setInterval(progress, 10);
    var files=get_version_github(_URL,_HTML);
	var prg=document.getElementById("pHTML");
	prg.value =0;
	function _prg(){
		prg.value=ii*10;
	}
	setInterval(_prg,10);
	alert("It well be update:"+files.length+" files");
	total=files.length;
    for (i=0;i<Object.keys(files).length; i++){
		//prg.value =ii*10;
        setTimeout(updater(_URL+'data/',files[i],pID));
    
    }
    //alert("User interface updated");
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
  function upload(_data,pID){
	  //alert("firmware update begin");
      if (window.XMLHttpRequest){
  	    var xhr=new XMLHttpRequest();
	}else{
  	    var xhr=new ActiveXObject('Microsoft.XMLHTTP');
	}
      
      
       
       xhr.onload = function(e){
		  //alert(this.status); 
		if (this.readyState == 4) {  
	  	if (this.status == 200) {
			if (pID=="pFirmWare")alert ("Firmware update end");
			if (pID=="pHTML") {
				//console.log((i-total)/total*100);
				//document.getElementById(pID).value=(current+1)/total*100;
				//if ((i-total)==total) alert("User interface updated !!!\n"+(i-total)+"/"+total);
				//document.getElementById(pID).value =(i-total)/total*100;
				//document.getElementById('sHTML').innerHTML=(i-total)/total*100;
				//document.getElementById(pID).value =(ii+1)/total*100;
				//console.log((ii)/total*100);
				setTimeout(function(){
					console.log((ii)/total*100);
					document.getElementById(pID).value =(ii+1)/total*100;
				});
				console.log(ii);
				document.getElementById(pID).value =(ii+1)/total*100;
				if((ii+1)==total) alert("Update user files complete");
				//delay(100);
			}
		}
	  }
  }
//	  xhr.upload.onprogress = function(e){
		  //alert("progress");
//	      if (e.lengthComputable)
//	      {
//	  	var percentage = Math.round((e.loaded/e.total)*100);
//	  	console.log("percent " + percentage + '%' );
//	  	document.getElementById("pFirmWare").value =percentage;
//	      }
//	      else 
//	      {
//	  	console.log("Unable to compute progress information since the total size is unknown");
//	      }
//		
//	  }

xhr.upload.addEventListener("progress", function(e) {
	//alert("progress");
        if (e.lengthComputable) {
          var percentage = Math.round((e.loaded * 100) / e.total);
          //console.log("percent " + percentage + '%' );
		  if (pID=="pFirmWare") document.getElementById(pID).value =percentage;
        }
      }, false);
	  
	  
	  if (pID=="pFirmWare") xhr.open('POST', sURL); else xhr.open('POST', sURL,false);
      xhr.send(_data);
  }
  function updater(uURL,uFileName,pID) {
    sURL='/upload';
    //_current=current;
	//_total=total
    _pID=pID;
    window.URL = window.URL || window.webkitURL;
    var xhr_dowload = new XMLHttpRequest();
	xhr_dowload.responseType = "blob";
    xhr_dowload.open('GET',uURL+uFileName);
    //xhr_dowload.responseType = "blob";
    
    xhr_dowload.onload = function(e) {
      if (this.status == 200) {
        var blob = this.response;
        var fd = new FormData();
        fd.append("afile", blob,uFileName);
        
        setTimeout(upload(fd,_pID));
		ii++;
      }
    };
  xhr_dowload.send();
  }
  function progress(){
  	document.getElementById("pHTML").value =(ii+1)/total*100;
  }
