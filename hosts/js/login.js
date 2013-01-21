(function(){
    $(document).ready(function(){ 
        $(".c_bottom").delegate(".login","click",login);        
    });
    function login(){
        var name = $("#username").val();
        var passwd = $("#password").val();
        if(name!=''||passwd!=''){
            $('#fm1').attr("action","index.php");
            $('#fm1').submit();
        }
    }
})()

function loginout(){
    if(confirm("是否退出系统")){
        window.location.href="loginout.php"
    }
}