$(document).ready(function(){
    $(".tohighsearch").bind("click",{
        msg: "high"
    },showSearch);
    $(".tobasesearch").bind("click",{
        msg: "base"
    },showSearch);
    $("#browser").treeview();
    $('.detailRight table tr td').live("click",tableshowStyle);
    
    $('.customerlist').delegate(".groups","click",{
        type:"getcustomer"
    },selectedCustomerGroup);
    $('.supplierlist').delegate(".groups","click",{
        type:"getsupplier"
    },selectedCustomerGroup);
    $('.productlist').delegate(".groups","click",{
        type:"getproduct"
    },selectedCustomerGroup);
    $('.listcontentLeft').delegate(".cate","click",leftTree);
    $('#bottompaging').delegate("#pagegoto","click",pagegoto);
    
    
});

function showSearch(event){
    var which = event.data.msg;
    if(which=="high"){
        $('.highsearch').removeClass("hidden");
        $('.search').addClass("hidden");
    }else if(which=="base"){
        $('.highsearch').addClass("hidden");
        $('.search').removeClass("hidden");
    }
}


function  selectedCate(event){
//    $(".st_tree .folder a").css("color","#000");
//    $(event.target).parent().find("a").css("color","red");
    $("#selectedGroupId").val($(event.target).parent().parent().find("span").attr('name'));
    
}

function selectedCustomerGroup(event){
    var type = event.data.type;
    $(".st_tree .folder a").css("color","#000");
    $(this).find("a").css("color","red");
    $("#selectedGroupId").val($(this).attr('name'));
    var option = $("#leftlistname").val();
    $("#pageoptions").val(option);
    var id=$(this).attr('name');
    $("#thisid").val(id);
    var pagenum = 1;
    ajaxGetCustomer(id,option,pagenum,type);
}

function ajaxGetCustomer(id,option,pagenum,type){
    $.ajax({
        type:"post",
        cache:false,
        url:"/pages/ajax/getHtml.php",
        data:({
            id:id,
            option:option,
            who:type,
            pagenum:pagenum
        }),
        success:function(data){
            if($.trim(data)!=""){
                var result=$.parseJSON(data);
                $(".detailRight table").html(result.customer);
                $(".detailPageOptions .bottom").html(result.paging);
                detailRightMenuBind();
                supplierRightMenuBind();
                sampleListRightMenu();
            }
        }
    });
}

//左侧树形按钮操作
function listleftpop(who,width,height){
    var id = $("#selectedGroupId").val();
    if(id==""){
        alert("请选择要操作的分组");
        return false;
    }
    var url = who+'&id='+id;
    showPage(url,width,height);
}

function deleteGroupContent(){
    var id = $("#selectedGroupId").val();
    if(id==""){
        alert("请选择要操作的分组");
        return false;
    }
    if(confirm('是否删除选中分组？'))
    {
        $.ajax({
            type:"post",
            cache:false,
            url:"/pages/ajax/updateContent.php",
            data:({
                id:id,
                who:'deleteGroupContact'
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
}

function leftTree(){
    $(".listcontentLeft .treeContent").addClass('hidden');
    $(this).siblings("div").removeClass('hidden');
    $(this).siblings("div").addClass('cateselected');
    $("#leftlistname").val($(this).attr("name"));
}

function pagegoto(){
    var pagenum = $("#inputpagenum").val();
    var pagemax = $("#pagemaxnum").val();
    var who = $("#pagetowho").val();
    if(pagenum !=""&&!checkIsNUM(pagenum)&&pagenum>0&&pagenum<pagemax){
        pagechange(pagenum,who);
    }else{
        alert("请填写正确的跳转页码");
    }
}
function pagechange(num,who){
    var option = $("#pageoptions").val();
    var id=$("#thisid").val();
    ajaxGetCustomer(id,option,num,who);
}

function remind(id){
    showPage('pages/common/popShow.php?who=checkRemind&id='+id,600,300);
}
function deleteRemind(){
    var id = $("#selectedID").val();
    if(id==""){
        alert("请选择要操作的行");
        return false;
    }
    $.ajax({
        type:"post",
        cache:false,
        url:"/pages/ajax/updateContent.php",
        data:({
            id:id,
            who:'deleteRemind'
        }),
        success:function(data){
            if($.trim(data)=="success"){
                alert("操作成功");
                history.go(0) 
            }else{
                alert("操作失败，请重新尝试");
            }
        }
    });
}

function selectSamplebyStatus(){
    var option = $("#samplestatusselect").val();
    var id="";
    var pagenum="1";
    var type="getsample";
    ajaxGetCustomer(id, option, pagenum, type);
}