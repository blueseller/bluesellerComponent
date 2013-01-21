<?php
include(ROOT . "trade_inc/pages/customer/checkleft.inc");

$customerId = Tools::getValue('id', '');
$custoemrArray = array();
if(!empty($customerId)){
    $custoemrArray = customerHandler::getCustomerById($customerId);
}
$custoemrArray = customerBean::setCustomerData($custoemrArray);

?>
<div class="ckecksContent">
    <div class="checkoptions">
        <span class="options">
            <a href="javascript:void(0)" onclick="showPage('pages/common/popShow.php?who=addcustomer',850,700)"><span class="noticeadd"><img src="../../images/button/plus.png" width="14px" height="14px">新建</span></a>
            <a href="javascript:void(0)" onclick="listpost2pop('addshare',600,400)"><span class="noticeadd"><img src="../../images/button/pencil_edit.png" width="14px" height="14px">修改</span></a>
            <a href="javascript:void(0)" onclick="listpost2pop('deletecontent',550,450)"><span class="noticeadd"><img src="../../images/button/close_delete.png" width="14px" height="14px">删除</span></a>
            <a href="javascript:void(0)" onclick="showPage('pages/common/popShow.php?who=checkCustomer',850,700)"><span class="noticeadd"><img src="../../images/button/comment.png" width="14px" height="14px">查看</span></a>
        </span>
    </div>
    <table class="checktable">
        <span class="checktitle">基础信息</span>
        <tr>
            <td class="doublename">客户编码:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['customer_id'];?></label></td>
            <td class="doublename">拥有者:</td>
            <td class="doubleinput"><label><?php echo requestCustomer::getCustomerIsWhohave($custoemrArray['customer_whohave']);?></label></td>
        </tr>
        <tr>
            <td class="doublename">客户名称:</td>
            <td class="doubleinput" colspan=3><label><?php echo $custoemrArray['customer_name'];?></label></td>
        </tr>
        <tr>
            <td class="doublename">地址:</td>
            <td class="doubleinput" colspan=3><label><?php echo $custoemrArray['customer_addr'];?></label></td>
        </tr>
        <tr>
            <td class="doublename">邮编:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['customer_postal_code'];?></label></td>
            <td class="doublename">网站:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['customer_website'];?></label></td>
        </tr>
        <tr>
            <td class="doublename">国家:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['customer_country'];?></label></td>
            <td class="doublename">地区:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['customer_province'];?></label></td>
        </tr>
        <tr>
            <td class="doublename">所属分组:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['customer_group'];?></label></td>
            <td class="doublename">客户等级:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['customer_grade'];?></label></td>
        </tr>
        <tr>
            <td class="doublename">客户来源:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['customer_from'];?></label></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <td class="doublename">关注产品:</td>
            <td class="doubleinput" colspan=3><label><?php echo $custoemrArray['customer_attention'];?></label></td>
        </tr>
    </table>
    
    <table class="checktable checkmiddle">
        <span class="checktitle">交易概况</span>
        <tr>
            <td class="doublename">收到邮件:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['customer_id'];?></label></td>
            <td class="doublename">发送邮件:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['customer_id'];?></label></td>
        </tr>
        <tr>
            <td class="doublename">历史样品:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['customer_id'];?></label></td>
            <td class="doublename">最近历史报价:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['customer_id'];?></label></td>
        </tr>
        <tr>
            <td class="doublename">历史订单:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['customer_id'];?></label></td>
            <td class="doublename">成交金额:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['customer_id'];?></label></td>
        </tr>  
        <tr>
            <td class="doublename">已收款:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['customer_id'];?></label></td>
            <td class="doublename">未收款:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['customer_id'];?></label></td>
        </tr>  
    </table>
    <table class="checktable">
        <span class="checktitle">客户联系人</span>
        <tr>
            <td class="doublename">主联系人:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['contact_name'];?></label></td>
            <td class="doublename">传真:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['contact_fax'];?></label></td>
        </tr>
        <tr>
            <td class="doublename">电话:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['contact_tel'];?></label></td>
            <td class="doublename">手机:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['contact_phone'];?></label></td>
        </tr>
        <tr>
            <td class="doublename">MSN:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['contact_msn'];?></label></td>
            <td class="doublename">电子邮件:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['contact_email'];?></label></td>
        </tr> 
        <tr>
            <td class="doublename">Skype:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['contact_skype'];?></label></td>
            <td class="doublename">其他:</td>
            <td class="doubleinput"><label><?php echo $custoemrArray['contact_other'];?></label></td>
        </tr> 
    </table>
</div>