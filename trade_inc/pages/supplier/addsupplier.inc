<?php
$supplierId = Tools::getValue('id', '');
$supplierArray = array();
if (!empty($supplierId)) {
    $permission = userPermissionHandler::getSuppliersPermissionByUserId($_COOKIE["userId"]);
    $supplierArray = supplierHandler::getSupplierById($permission, $supplierId);
}
$supplierArray = supplierBean::setSupplierData($supplierArray);

?>

<form id="pop_form" action="" method="post">
    <div class="addNotice divwidth">

        <h3 class="toptitle title">新建供应商</h3>
        <table class="addCustomer">
            <tr>
                <td class="doublename">供应商编码:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="supplierCode" id="supplierCode" class="supplierCode" value="<?php echo $supplierArray['supplier_id']; ?>"></td>
                <td colspan="2">为了方便查找客户，建议输入客户编码</td>
            </tr>
            <tr>
                <td class="doublename">供应商名称<span style="color:red">[*]</span>:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="supplierName" id="supplierName" class="supplierName" value="<?php echo $supplierArray['supplier_name']; ?>"></td>
                <td class="doublename">所属分组<span style="color:red">[*]</span>:</td>
                <td class="doubleinput">
                    <select style="width: 200px;" name="suppliergroup" id="suppliergroup" class="suppliergroup">
                        <?php
                        $groups = customerGroupHandler::getGroups("suppliers");
                        $groupSelectHtml = '';
                        foreach ($groups as $value) {
                            $groupSelectHtml.='<option value="' . $value['id'] . '"';
                            if ($supplierArray['supplier_group'] == $value['id']) {
                                $groupSelectHtml.=' selected ';
                            }
                            $groupSelectHtml.='>' . $value['customer_group_name'] . '</option>';
                        }
                        echo $groupSelectHtml;
                        ?>
                    </select>
            </tr>
            <tr>
                <td class="doublename">主联系人<span style="color:red">[*]</span>:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="supplierContactName" id="supplierContactName" class="supplierContactName" value="<?php echo $supplierArray['supplier_contact_name']; ?>"></td>
                <td class="doublename">电话:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="supplierContactTel" id="supplierContactTel" class="supplierContactTel" value="<?php echo $supplierArray['supplier_contact_tel']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">手机:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="supplierContactPhone" id="supplierContactPhone" class="supplierContactPhone" value="<?php echo $supplierArray['supplier_contact_phone']; ?>"></td>
                <td class="doublename">电子邮件:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="supplierContactEmail" id="supplierContactEmail" class="supplierContactEmail" value="<?php echo $supplierArray['supplier_contact_postal']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">传真:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="supplierContactFax" id="supplierContactFax" class="supplierContactFax" value="<?php echo $supplierArray['supplier_contact_fax']; ?>"></td>
                <td class="doublename">邮编:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="supplierContactpostal" id="supplierContactpostal" class="supplierContactpostal" value="<?php echo $supplierArray['supplier_contact_email']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">主营产品:</td>
                <td colspan="3">
                    <textarea style="width: 92%;height: 40px;" name="products" id="products" class="products"><?php echo $supplierArray['supplier_products']; ?></textarea>
                </td>
            </tr>
            <tr>
                <td class="doublename">地址:</td>
                <td colspan="3"><input type="text" style="width: 92%"name="address" id="address" class="address" value="<?php echo $supplierArray['supplier_addr'];?>"></td>
            </tr>
            <tr>
                <td class="doublename">开户银行:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="bankname" id="bankname" class="bankname" value="<?php echo $supplierArray['supplier_bank_name']; ?>"></td>
                <td class="doublename">开户名:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="openbankname" id="openbankname" class="openbankname" value="<?php echo $supplierArray['supplier_bank_username']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">银行账户:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="banknum" id="banknum" class="banknum" value="<?php echo $supplierArray['supplier_bank_num']; ?>"></td>
                <td class="doublename">企业法人:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="companyRepresentative" id="companyRepresentative" class="companyRepresentative" value="<?php echo $supplierArray['supplier_company_representative']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">税务登记号:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="companyTaxnum" id="companyTaxnum" class="companyTaxnum" value="<?php echo $supplierArray['supplier_company_taxnum']; ?>"></td>
                <td class="doublename">星级:</td>
                <td class="doubleinput">
                    <select style="width: 200px;" name="suppliergrade" id="suppliergrade" class="suppliergrade">
                            <?php
                            $grades = configHandler::getConfigValueByKey("customer_grade_images");
                            $grades = explode("|", $grades['config_value']);
                            $gradesSelectHtml = '';
                            foreach ($grades as $key => $value) {
                                $gradesSelectHtml.='<option value="' . ($key + 1) . '"';
                                if ($supplierArray['supplier_grade'] == ($key + 1)) {
                                    $gradesSelectHtml.=' selected ';
                                }
                                $gradesSelectHtml.='>' . $value . '</option>';
                            }
                            echo $gradesSelectHtml;
                            ?>
                        </select>
                    
                </td>
            </tr>
            <tr>
                <td class="doublename">备注:</td>
                <td colspan="3">
                    <textarea style="width: 92%;height: 40px;" name="supplierRemind" id="supplierRemind" class="supplierRemind">
<?php echo $supplierArray['supplier_remind']; ?>
                    </textarea>
                </td>
            </tr>
        </table>

    </div>
    <div class="bottom_button">
        <input type="submit" value="保存" class="save" flagwho="addsupplier">
        <input type="button" value="关闭" class="close">
    </div>
    <input type="hidden" value="addsupplier" name="subwho">
    <input type="hidden" value="<?php echo $customerId; ?>" name="supplierid">
</form>