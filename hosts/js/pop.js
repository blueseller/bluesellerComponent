$(document).ready(function(){
    $('table.more tr').delegate("td","click",tableshowStyle);
    $('table.more tr td').contextMenu('myMenu1', {
        onContextMenu: function(e) {
            tableshowStyle(e);
            return true;
        },
        bindings: {
            'addnew': function(t) {
                var url = $('table.more').attr('tip');
                showPage('?who='+url,600,400)
            },
            'edit': function(t) {
                var url = $('table.more').attr('tip');
                showPage('?who='+url+'&contentid='+t.id,600,400);
            },
            'check': function(t) {
                showPage('?who=popview&contentid='+t.id,700,500);
            },
            'delete': function(t) {
                showPage('?who=deletecontent&contentid='+t.id,600,400);
            }
        },
        onShowMenu: function(e, menu) {
            return menu;
        }
    });
    
    $('.save').bind("click",saveContent);
   
});


function saveContent(e){
    e.preventDefault();
    var who = $(".save").attr("flagwho");
    var fun = saveButton.save;
    switch(who){
        case 'addcustomer':
            fun.addcustomer(e);
            break;
        case 'addCustomerGroup':
            fun.addCustGroup(e);
            break;
        case 'addNotice':
            fun.addNotice(e);
            break;
        case 'addsupplier':
            fun.addSupplier(e);
            break;
        case 'sharecustomer':
            $('#pop_form').ajaxSubmit(suboptions);
            break;
        case 'sharecustomerGroup':
            $('#pop_form').ajaxSubmit(suboptions);
            break;
        case 'addContactContent':
            fun.addContactContent(e);
            break;
        case 'addRemind':
            fun.addRemind(e);
            break;
        case 'updateRemind':
            fun.addRemind(e);
            break;
        case 'addproduct':
            fun.addProduct(e);
            break;
        case 'addsample':
            fun.addSample(e);
            break;
        case 'shareSample':
            fun.shareSample(e);
            break;
 
    }
}

var saveButton = {};
var suboptions = {
    type:'post',
    url:'subform.php',
    success:callbackfun
};
saveButton.save ={
    addcustomer:function(e){
        e.preventDefault();
        var cust_name = $("#customerName").val();
        var cust_group = $("#customerName").val();
        var cust_contact_name = $("#custcontactName").val();
        var cust_contact_email = $("#custcontactEmail").val();
        var substatus = "on";
        if(cust_name == ""){
            alert("请填写客户名称");
            substatus ="off";
            return false;
        }
        if(cust_group == ""){
            alert("请填写所属分租");
            substatus ="off";
            return false;
        }
        if(cust_contact_name == ""){
            alert("请填写主联系人");
            substatus ="off";
            return false;
        }
        if(cust_contact_email == ""){
            alert("请填写联系人电子邮箱");
            substatus ="off";
            return false;
        }
        
        if(!checkEmail(cust_contact_email)){
            alert("电子邮件格式不正确，请重新输入");
            substatus ="off";
            $("#custcontactEmail").focus();
            return false;
        }

        if(checkIsNUM($("#PostalCode").val())&&$("#PostalCode").val() !=''){
            alert("邮编只能位数字");
            substatus ="off";
            $("#PostalCode").focus();
            return false;
        }
        if(substatus == "on"){
            $('#pop_form').ajaxSubmit(suboptions);
        }
    },
    addCustGroup:function(e){
        var cust_name = $("#custgroupname").val();
        var substatus = 'on';
        if(cust_name == ""){
            alert("请填分组名称");
            substatus ="off";
        }
        if(substatus == "on"){
            $('#pop_form').ajaxSubmit(suboptions);
        }
    },
    addNotice:function(e){
        var substatus = 'on';
        var title = $("#noticetitle").val();
        var content = $("#noticeContent").val();
        if(title == ""){
            alert("请填写通知标题");
            substatus ="off";
            return false;
        }
        if(content == ""){
            alert("请填写通知内容");
            substatus ="off";
            return false;
        }

        if(substatus == "on"){
            $('#pop_form').ajaxSubmit(suboptions);
        }
    },
    addSupplier:function(e){
        e.preventDefault();
        var supplierName = $("#supplierName").val();
        var supplierContactName = $("#supplierContactName").val();
        if(supplierName==""){
            alert("供应商名称不能为空");
            return false;
        }
        if(supplierContactName==""){
            alert("联系人不能为空");
            return false;
        }
        $('#pop_form').ajaxSubmit(suboptions);
    },
    addContactContent:function(e){
        e.preventDefault();
        var contactername = $("#contactername").val();
        var contacteremail = $("#contacteremail").val();
        if(contactername==""){
            alert("联系人不能为空");
            return false;
        }
        if(contacteremail==""){
            alert("联系人邮箱不能为空");
            return false;
        }
        suboptions["url"]="../ajax/addContent.php"
        $('#pop_form').ajaxSubmit(suboptions);
    },
    addRemind:function(e){
        e.preventDefault();
        var remindtitle = $("#remindtitle").val();
        if(remindtitle==""){
            alert("提醒标题不能为空");
            return false;
        }
        $('#pop_form').ajaxSubmit(suboptions);
    },
    addProduct:function(e){
        var productnamecn = $("#productnamecn").val();
        var productnameen = $("#productnameen").val();
        if(productnamecn==""){
            alert("产品中文名不能为空");
            return false;
        }
        if(productnameen==""){
            alert("产品英文名不能为空");
            return false;
        }
        $('#pop_form').ajaxSubmit(suboptions);
    },
    addSample:function(){
        var sample_express_company = $("#sample_express_company").val();
        var sample_express_num = $("#sample_express_num").val();
        var toaddress_customerid = $("#toaddress_customerid").val();
        if(sample_express_company==""){
            alert("请填写快递公司");
            return false;
        }
        if(sample_express_num==""){
            alert("请填写快递单号");
            return false;
        }
        if(toaddress_customerid==""){
            alert("请填写客户名称");
            return false;
        }
        $('#pop_form').ajaxSubmit(suboptions);
    },
    shareSample:function(){
        var selectedName = $("#selectedName").val();
        if(selectedName==""){
            alert("请选择要分配给的同事姓名");
            return false;
        }
        $('#pop_form').ajaxSubmit(suboptions);
    }
}
function callbackfun (data, status){
    if(status!='success'){
        alert('网络忙，请重试');
        return false;
    }
    if(data == "success"){
        alert("数据保存成功,点击确定关闭页面");
        $('.close').click();
    }
    if(data == 'nodoit'){
        alert("数据保存失败,请重新添加数据");
    }
    
}

function changeToMainContact(contID,custID){
    $.ajax({
        type:"post",
        cache:false,
        url:"/pages/ajax/updateContent.php",
        data:({
            customerid:custID,
            contactid:contID,
            who:'updateMainContact'
        }),
        success:function(data){
            if($.trim(data)=="success"){
                alert("操作成功");
                location.reload();
            }else{
                alert("操作失败，请重新尝试");
            }
        }
    });
}

function changeContactContent(domid,contid,type){
    var listLabel = $("#"+domid).find('td label');
    var selector  = "#"+domid+" .doubleinput";
    $(selector).css("border-bottom"," 0px solid #2D74C6");
    if(type=="customer"){
        listLabel.each(function(i){
            var nowvalue = $(this).html();
            var now = "<input name=\"contact"+i+"\" value=\""+nowvalue+"\">"
            $(this).html(now);
        });
    }else if(type=="supplier"){
        listLabel.each(function(i){
            var nowvalue = $(this).html();
            var j = i;
            if(i==4){
                j=5;
            }
            if(i==5){
                j=7;
            }
            var now = "<input name=\"contact"+j+"\" value=\""+nowvalue+"\">"
            $(this).html(now);
        });
    }
    
    $("#"+domid).find("#changecontact").addClass("hidden");
    $("#"+domid).find("#savecontact").removeClass("hidden");
}

function saveContactContent(domid,contid){
    var listLabel = $("#"+domid).find('td label input');
    var arr = '';
    listLabel.each(function(i){
        var nowvalue = $(this).val();
        var key  = $(this).attr("name");
        arr = arr + '&'+ key + '=' + nowvalue;
    });
    arr = arr + '&who=updateContact&contactid='+contid;
    $.ajax({
        type:"post",
        cache:false,
        url:"/pages/ajax/updateContent.php",
        data:arr,
        success:function(data){
            if($.trim(data)=="success"){
                alert("操作成功");
            }else{
                alert("操作失败，请重新尝试");
            }
            location.reload();
        }
    });
}

function showInsert(){
    $("#insertContactDiv").removeClass('hidden');
    $("#showtitle").removeClass('hidden');
}

function insertContactContent(domid,flag,customerid){
    var listLabel = $("#"+domid).find('td label input');
    var arr = '';
    listLabel.each(function(i){
        var nowvalue = $(this).val();
        var key  = $(this).attr("name");
        arr = arr + '&'+ key + '=' + nowvalue;
    });
    arr = arr + '&who=addContactContent&customerid='+customerid+"&contactflag="+flag;
    $.ajax({
        type:"post",
        cache:false,
        url:"/pages/ajax/addContent.php",
        data:arr,
        success:function(data){
            if($.trim(data)=="success"){
                alert("操作成功");
            }else{
                alert("操作失败，请重新尝试");
            }
            location.reload();
        }
    });
}

function deleteContact(contactid){
    $.ajax({
        type:"post",
        cache:false,
        url:"/pages/ajax/updateContent.php",
        data:({
            contactid:contactid,
            who:'deleteContact'
        }),
        success:function(data){
            if($.trim(data)=="success"){
                alert("操作成功");
                location.reload();
            }else{
                alert("操作失败，请重新尝试");
            }
        }
    });
}




function tableshowStyle(e){
    $(e.target).parent().parent().find("td").removeClass("righton");
    $(e.target).addClass("righton").siblings().addClass("righton");
    $("#contentid").val($(e.target).attr('id'));
}

//列表上面部分按钮操作
function listpost2pop(who,width,height){
    var id = $("#contentid").val();
    if(id==""){
        alert("请选择要操作的行");
        return false;
    }
    var url = '?who='+who+'&contentid='+id;
    if(who=='popview'){
        width = 700;
        height = 500;
    }
    showPage(url,width,height);
}

