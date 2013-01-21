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
<div class="ckecksContent toppadding">
    <h3 class="toptitle title">供应商信息</h3>
    <table class="checktable">
        <tr>
            <td class="doublename">供应商编码:</td>
            <td class="doubleinput"><?php echo $supplierArray['supplier_id']; ?></td>
            <td colspan="2"></td>
        </tr>
        <tr>
            <td class="doublename">供应商名称<span style="color:red">[*]</span>:</td>
            <td class="doubleinput"><?php echo $supplierArray['supplier_name']; ?>
            <td class="doublename">所属分组<span style="color:red">[*]</span>:</td>
            <td class="doubleinput">

                <?php
                $groups = customerGroupHandler::getGroupById($supplierArray['supplier_group']);
                if(isset($groups['customer_group_name'])){
                    echo $groups['customer_group_name'];
                }
                
                ?> 
        </tr>
        <tr>
            <td class="doublename">主联系人<span style="color:red">[*]</span>:</td>
            <td class="doubleinput"><?php echo $supplierArray['supplier_contact_name']; ?></td>
            <td class="doublename">电话:</td>
            <td class="doubleinput"><?php echo $supplierArray['supplier_contact_tel']; ?></td>
        </tr>
        <tr>
            <td class="doublename">手机:</td>
            <td class="doubleinput"><?php echo $supplierArray['supplier_contact_phone']; ?></td>
            <td class="doublename">电子邮件:</td>
            <td class="doubleinput"><?php echo $supplierArray['supplier_contact_postal']; ?></td>
        </tr>
        <tr>
            <td class="doublename">传真:</td>
            <td class="doubleinput"><?php echo $supplierArray['supplier_contact_fax']; ?></td>
            <td class="doublename">邮编:</td>
            <td class="doubleinput"><?php echo $supplierArray['supplier_contact_email']; ?></td>
        </tr>
        <tr>
            <td class="doublename">主营产品:</td>
            <td class="doubleinput" colspan="3">
                <?php
                if (isset($supplierArray['supplier_products'])) {
                    echo $supplierArray['supplier_products'];
                }
                ?>
            </td>
        </tr>
        <tr>
            <td class="doublename">地址:</td>
            <td class="doubleinput" colspan="3"><?php echo $supplierArray['supplier_addr']; ?>
        </tr>
        <tr>
            <td class="doublename">开户银行:</td>
            <td class="doubleinput"><?php echo $supplierArray['supplier_bank_name']; ?></td>
            <td class="doublename">开户名:</td>
            <td class="doubleinput"><?php echo $supplierArray['supplier_bank_username']; ?></td>
        </tr>
        <tr>
            <td class="doublename">银行账户:</td>
            <td class="doubleinput"><?php echo $supplierArray['supplier_bank_num']; ?></td>
            <td class="doublename">企业法人:</td>
            <td class="doubleinput"><?php echo $supplierArray['supplier_company_representative']; ?></td>
        </tr>
        <tr>
            <td class="doublename">税务登记号:</td>
            <td class="doubleinput"><?php echo $supplierArray['supplier_company_taxnum']; ?></td>
            <td class="doublename">星级:</td>
            <td class="doubleinput">
                <?php
                $grades = configHandler::getConfigValueByKey("customer_grade_images");
                $grades = explode("|", $grades['config_value']);
                echo $grades[($supplierArray['supplier_grade']-1)];
                ?>
            </td>
        </tr>
        <tr>
            <td class="doublename">备注:</td>
            <td class="doubleinput" colspan="3"><?php echo $supplierArray['supplier_remind']; ?></td>
        </tr>
    </table>

</div>