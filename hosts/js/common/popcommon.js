$(document).ready(function(){
    $(".bottom_button").delegate(".close","click",closeWindow);
});
function closeWindow(){
    window.opener=null;   
    window.open("","_self");    
    window.close();
}
