function checkEmail(email_val){
    var search_str = /^[\w\-\.]+@[\w\-\.]+(\.\w+)+$/;
    if(!search_str.test(email_val)){
        return false;
    }else{
        return true;
    }
}

function checkIsNUM(num_val){
    var search_str = /^\d+$/;
    if(search_str.test(num_val)){
        return false;
    }else{
        return true;
    }
}