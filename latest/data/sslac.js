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
//alert ('get_rest: '+req);
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
//alert('set_rest: '+req);
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
function get_version(){
    return get_rest('version');
}