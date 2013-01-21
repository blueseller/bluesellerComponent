(function(){
    $(document).ready(function(){
        $("#mainMenu").delegate("li","mouseover",tabnav);
        $(".pop_main").delegate(".closeButton","click",popdiveinit);
        var flag = new PopupLayer({
            trigger:"#deleteCustomer",
            popupBlk:"#blk9",
            closeBtn:".closeButton",
            useOverlay:true,
            useFx:true,
            isresize:true, 
            offsets:{
                x:0,
                y:-41
            },
            onBeforeStart:function(){
                var returnFlag= deleteContent();
                if(returnFlag == 'false'){
                    return fasle;
                }else{
                    var name = $("#"+returnFlag).attr("class");
                    $("#poplaye_title").html("您是否要删除 客户名为 "+name+" 的数据");
                    $("#popdiv").delegate("#deleteYesButton","click",deleteYes);
                    $('.closeInput').val('否');
                }
            }
        });
        flag.doEffects = function(way){
            if(way == "open"){
                this.popupLayer.css({
                    opacity:0.3
                }).show(300,function(){
                    this.popupLayer.animate({
                        left:($(document).width() - this.popupLayer.width())/2,
                        top:(document.documentElement.clientHeight - this.popupLayer.height())/2 + $(document).scrollTop(),
                        opacity:0.8
                    },300,function(){
                        this.popupLayer.css("opacity",1)
                    }.binding(this));
                }.binding(this));
            } else{
                this.popupLayer.animate({
                    left:this.trigger.offset().left,
                    top:this.trigger.offset().top,
                    opacity:0.1
                },{
                    duration:200,
                    complete:function(){
                        this.popupLayer.css("opacity",1);
                        this.popupLayer.hide()
                    }.binding(this)
                });
            }
        }
    });
    function tabnav(){
        var num = $(this).index()+1;
        $(".nav-bottomtab div").addClass('hidden');
        $("#con"+num).removeClass('hidden');
    }

})()
function showPage(url,width,height,title){
    var top = (window.screen.availHeight/2)-(height/2);
    var left = (window.screen.availWidth/2)-(width/2);  
    var params = "height="+height+"px,width="+width+"px,top="+top+"px,left="+left+"px ,toolbar=no, menubar=no, scrollbars=no, resizable=no,location=n o, status=no";
    window.open(url,'',params);
}

function editContentPage(url,width,height){
    var id = $("#selectedID").val();
    if(id==""){
        alert("请选择要操作的行");
        return false;
    }
    var url =url +'&id='+id;
    showPage(url,width,height);
}

function deleteContent(url){
    var id = $("#selectedID").val();
    if(id==""){
        alert("请选择要操作的行");
        return 'false';
    }
    return id;
}

function deleteYes(){
    var id = $("#selectedID").val();
    var type = $("#typename").val();
    $.ajax({
        type:"post",
        cache:false,
        url:"pages/ajax/deleteContent.php",
        data:({
            customerid:id,
            who:'deleteCustomer',
            type:type
        }),
        success:function(data){
            $("#deleteYesButton").addClass('hidden');
            if($.trim(data)=="success"){
                $("#poplaye_title").html("删除数据成功");
                $("#"+id).html("");
                $('.closeInput').val('关闭');
            }else{
                $("#poplaye_title").html("删除数据失败，请重新尝试");
            }
        }
    });
}

function popdiveinit(){
    $("#poplaye_title").html("您是否要删除此条数据？");
    $("#deleteYesButton").removeClass('hidden');
}
