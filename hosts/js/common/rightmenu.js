$(document).ready(function(){
    
    detailRightMenuBind();
    supplierRightMenuBind();
    productRightMenuBind();
    TreeRightMenu();
    sampleListRightMenu();
});

function TreeRightMenu(){
    $('.st_tree .folder').contextMenu('TreeRightMenu', {
        onContextMenu: function(e) {
            selectedCate(e);
            return true;
        },
        bindings: {
            'addGroup': function(t) {
                showPage('pages/common/popShow.php?who=addCustGroup&catetype='+$("#typename").val(),600,400);
            },
            'editGroup': function(t) {
                listleftpop('pages/common/popShow.php?who=addCustGroup',600,400);
            },
            'checkGroup': function(t) {
                listleftpop('pages/common/popShow.php?who=addCustGroup&check=true',600,400);
            },
            'deleteGroup': function(t) {
                deleteGroupContent();
            }
        }
    });
}
function sampleListRightMenu(){
    $('table.sampledetailContent tr td').contextMenu('sampleListRightMenu', {
        onContextMenu: function(e) {
            tableshowStyle(e);
            return true;
        },
        bindings: {
            'add': function(t) {
                showPage('pages/common/popShow.php?who=addsample',850,550);
            },
            'edit': function(t) {
                editContentPage('pages/common/popShow.php?who=addsample',850,550);
            },
            'check': function(t) {
                editContentPage('pages/common/popShow.php?who=checksample',850,550);
            },
            'delete': function(t) {
                $("#deleteCustomer").click();
            },
            'shareforortherpeople':function(t){
                editContentPage('pages/common/popShow.php?who=sharesample',450,300);
            }
        },
        onShowMenu: function(e, menu) {
            return menu;
        }
    });
}
function productRightMenuBind(){
    $('table.productdetailContent tr td').contextMenu('productListRightMenu', {
        onContextMenu: function(e) {
            tableshowStyle(e);
            return true;
        },
        bindings: {
            'add': function(t) {
                showPage('pages/common/popShow.php?who=addproduct',850,700);
            },
            'edit': function(t) {
                editContentPage('pages/common/popShow.php?who=addproduct',850,700);
            },
            'check': function(t) {
                editContentPage('pages/common/popShow.php?who=checkproduct',950,630);
            },
            'delete': function(t) {
                $("#deleteCustomer").click();
            }
        },
        onShowMenu: function(e, menu) {
            return menu;
        }
    });
}

function supplierRightMenuBind(){
    $('table.suppliers tr td').contextMenu('supplierRightMenu', {
        onContextMenu: function(e) {
            tableshowStyle(e);
            return true;
        },
        bindings: {
            'checksupplier': function(t) {
                editContentPage('pages/common/popShow.php?who=checkSupplier',950,630);
            },
            'addsupplier': function(t) {
                showPage('pages/common/popShow.php?who=addsupplier',850,700);
            },
            'editsupplier': function(t) {
                editContentPage('pages/common/popShow.php?who=addsupplier',850,700);
            },
            'deletesupplier': function(t) {
                $("#deleteCustomer").click();
            },
            'addSupplierContacter': function(t) {
                editContentPage('pages/common/popShow.php?who=addsuppliercontact',500,300);
            }
        },
        onShowMenu: function(e, menu) {
            return menu;
        }
    });
}

function detailRightMenuBind(){
    
    $('table.customerdetailContent tr td').contextMenu('customerTableListRightMenu', {
        onContextMenu: function(e) {
            tableshowStyle(e);
            return true;
        },
        bindings: {
            'add': function(t) {
                showPage('pages/common/popShow.php?who=addcustomer',850,700);
            },
            'edit': function(t) {
                editContentPage('pages/common/popShow.php?who=addcustomer',850,700);
            },
            'check': function(t) {
                editContentPage('pages/common/popShow.php?who=checkCustomer',950,630);
            },
            'delete': function(t) {
                $("#deleteCustomer").click();
            },
            'tocustGroup': function(t) {
                editContentPage('pages/common/popShow.php?who=tocustGroup',500,300);
            },
            'editcustGroup': function(t) {
                editContentPage('pages/common/popShow.php?who=editcustGroup',500,300);
            },
            'addContacter': function(t) {
                editContentPage('pages/common/popShow.php?who=addContacter',700,500);
            },
            'addremind':function(t) {
                editContentPage('pages/common/popShow.php?who=addRemind',600,400);
            },
            'checkremind':function(t) {
                editContentPage('pages/common/popShow.php?who=checkRemind',600,300)
            },
            'deleteremind':function(){
                deleteRemind();
            }
            
        },
        onShowMenu: function(e, menu) {
            return menu;
        }
    });
}

function tableshowStyle(e){
    $(e.target).parent().parent().find("td").removeClass("righton");
    $(e.target).addClass("righton").siblings().addClass("righton");
    $("#selectedID").val($(e.target).parent().attr('id'));
}