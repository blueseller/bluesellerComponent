<?php
include(ROOT . "trade_inc/pages/supplier/checkleft.inc");
$supplierId = Tools::getValue('id', '');
$supplierArray = array();
if (!empty($supplierId)) {
    $permission = userPermissionHandler::getSuppliersPermissionByUserId($_COOKIE["userId"]);
    $supplierArray = supplierHandler::getSupplierById($permission, $supplierId);
}
$supplierArray = supplierBean::setSupplierData($supplierArray);
?>
<div class="ckecksContent">
    <div class="checkoptions">
        <span class="options">
            <a href="javascript:void(0)" onclick="showInsert()"><span class="noticeadd"><img src="../../images/button/plus.png" width="14px" height="14px">新建</span></a>
        </span>
    </div>

    <table class="checktable hidden" id="insertContactDiv">
        <span class="checktitle hidden" id="showtitle">添加客户联系信息</span>
        <tbody>
            <tr>
                <td class="doublename">联系人:</td>
                <td class="doubleinput" style="border-bottom-width: 0px; border-bottom-style: solid; border-bottom-color: rgb(45, 116, 198);"><label><input name="contact0" value=""></label></td>
                <td class="doublename">传真:</td>
                <td class="doubleinput" style="border-bottom-width: 0px; border-bottom-style: solid; border-bottom-color: rgb(45, 116, 198);"><label><input name="contact1" value=""></label></td>
            </tr>
            <tr>
                <td class="doublename">电话:</td>
                <td class="doubleinput" style="border-bottom-width: 0px; border-bottom-style: solid; border-bottom-color: rgb(45, 116, 198);"><label><input name="contact2" value=""></label></td>
                <td class="doublename">手机:</td>
                <td class="doubleinput" style="border-bottom-width: 0px; border-bottom-style: solid; border-bottom-color: rgb(45, 116, 198);"><label><input name="contact3" value=""></label></td>
            </tr>
            <tr>
                <td class="doublename">电子邮件:</td>
                <td class="doubleinput" style="border-bottom-width: 0px; border-bottom-style: solid; border-bottom-color: rgb(45, 116, 198);"><label><input name="contact5" value=""></label></td>
                <td class="doublename">其他:</td>
                <td class="doubleinput" style="border-bottom-width: 0px; border-bottom-style: solid; border-bottom-color: rgb(45, 116, 198);"><label><input name="contact7" value=""></label></td>
            </tr> 
            <tr>
                <td class="doublename" colspan="4" style="text-align:center"><input value="保存联系信息" id="insertcontact" class="" type="button" onclick="insertContactContent('insertContactDiv','supplier','<?php echo $customerId ?>')"></td>
            </tr> 
        </tbody>
    </table>

    <span class="checktitle">主联系人信息</span>
    <table class="checktable" id="mainContact">
        <tr>
            <td class="doublename">主联系人:</td>
            <td class="doubleinput"><label><?php echo $supplierArray['supplier_name']; ?></label></td>
            <td class="doublename">传真:</td>
            <td class="doubleinput"><label><?php echo $supplierArray['supplier_contact_fax']; ?></label></td>
        </tr>
        <tr>
            <td class="doublename">电话:</td>
            <td class="doubleinput"><label><?php echo $supplierArray['supplier_contact_tel']; ?></label></td>
            <td class="doublename">手机:</td>
            <td class="doubleinput"><label><?php echo $supplierArray['supplier_contact_phone']; ?></label></td>
        </tr>
        <tr>
            <td class="doublename">电子邮件:</td>
            <td class="doubleinput"><label><?php echo $supplierArray['supplier_contact_email']; ?></label></td>
            <td class="doublename">其他:</td>
            <td class="doubleinput"><label><?php echo $supplierArray['supplier_contact_other']; ?></label></td>
        </tr> 
        <tr>
            <td class="doublename" colspan=4 style="text-align:left">修改联系信息：<input value="修改联系信息" type="button" onclick="changeContactContent('mainContact','<?php echo $custoemrArray['customer_first_contacter'] ?>')" class="" id="changecontact"><input value="保存联系信息" id="savecontact" class="hidden" type="button" onclick="saveContactContent('mainContact','<?php echo $custoemrArray['customer_first_contacter'] ?>')"></td>
        </tr>
    </table>
    <?php
    $supplierContactArray = contactHandler::getContactByCustomerId($supplierId, "","supplier");
    $otherContactHtml = '<span class="checktitle">其他联系人</span>';
    $num = 0;
    foreach ($supplierContactArray as $value) {
        $num++;
        $template = htmlTemplate::supplierContactShowHtml();
        $otherContactHtml.= str_replace(array('{contact_name}', '{contact_fax}', '{contact_email}', '{contact_tel}', '{contact_phone}', '{contact_other}', '{id}', '{contact_id}','{customer_id}')
                , array($value['contact_name'], $value['contact_fax'], $value['contact_email'], $value['contact_tel'], $value['contact_phone'], $value['contact_other'], $value['contact_id'], $value['contact_id'], $customerId)
                , $template);
        if (count($supplierContactArray) != $num) {
            $otherContactHtml.='<hr style="border:1 dashed #999999;width:60%;text-align:center;margin-top:10px;"  color="#000000" size="1">';
        }
    }
    if(count($supplierContactArray)>0){
        echo $otherContactHtml;
    }
    
    ?>
</div>