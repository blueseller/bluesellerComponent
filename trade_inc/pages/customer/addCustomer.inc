<?php
$customerId = Tools::getValue('id', '');
$custoemrArray = array();
if (!empty($customerId)) {
    $custoemrArray = customerHandler::getCustomerById($customerId);
}
$custoemrArray = customerBean::setCustomerData($custoemrArray);
?>

<form id="pop_form" action="" method="post">
    <div class="addNotice divwidth">

        <h3 class="toptitle title">客户信息</h3>

        <table class="addCustomer">
            <tr class="tableFirstTR">
                <td class="name">客户编码:</td>
                <td><input type="text" name="customerCode" id="customerCode" class="customerCode" style="width: 300px;" value="<?php echo $custoemrArray['customer_id']; ?>"><span class="tab">为了方便查找客户，建议输入客户编码</span></td>
            </tr>
            <tr>
                <td class="name">客户名称<span style="color:red">[*]</span>:</td>
                <td><input type="text" name="customerName" id="customerName" class="customerName" style="width: 500px;" value="<?php echo $custoemrArray['customer_name']; ?>"></td>
            </tr>
            <tr>
                <td class="name">地址:</td>
                <td><input type="text" name="customerAddr" id="customerAddr" class="customerAddr"  style="width: 500px;" value="<?php echo $custoemrArray['customer_addr']; ?>"></td>
            </tr>
            <tr>
                <td class="name">邮编:</td>
                <td><input type="text" name="PostalCode" id="PostalCode" class="PostalCode" style="width: 300px;" value="<?php echo $custoemrArray['customer_postal_code']; ?>"></td>
            </tr>
            <tr>
                <td class="name">所属分组<span style="color:red">[*]</span>:</td>
                <td>
                    <select style="width: 250px;" name="customergroup" id="customergroup" class="customergroup">
                        <?php
                        $groups = customerGroupHandler::getGroups("customer");
                        $groupSelectHtml = '';
                        foreach ($groups as $value) {
                            $groupSelectHtml.='<option value="' . $value['id'] . '"';
                            if ($custoemrArray['customer_group'] == $value['id']) {
                                $groupSelectHtml.=' selected ';
                            }
                            $groupSelectHtml.='>' . $value['customer_group_name'] . '</option>';
                        }
                        echo $groupSelectHtml;
                        ?>
                    </select>
                    <div style="width: 330px;float: right">
                        客户等级:
                        <select style="width: 250px;" name="customergrade" id="customergrade" class="customergrade">
                            <?php
                            $grades = configHandler::getConfigValueByKey("customer_grade_images");
                            $grades = explode("|", $grades['config_value']);
                            $gradesSelectHtml = '';
                            foreach ($grades as $key => $value) {
                                $gradesSelectHtml.='<option value="' . ($key + 1) . '"';
                                if ($custoemrArray['customer_grade'] == ($key + 1)) {
                                    $gradesSelectHtml.=' selected ';
                                }
                                $gradesSelectHtml.='>' . $value . '</option>';
                            }
                            echo $gradesSelectHtml;
                            ?>
                        </select>
                    </div>
                </td>
            </tr>
            <tr>
                <td class="name">所属国家:</td>
                <td>
                    <input type="text" name="customercountry" id="customercountry" class="customercountry" style="width: 230px;" value="<?php echo $custoemrArray['customer_country']; ?>">
                    <div style="width: 330px;float: right">
                        所属地区:
                        <input type="text" name="customerprovince" id="customerprovince" class="customerprovince" style="width: 230px;" value="<?php echo $custoemrArray['customer_province']; ?>">
                    </div>
                </td>
            </tr>
            <tr>
                <td class="name">客户来源:</td>
                <td>
                    <input type="text"  style="width: 300px;" name="customerfrom" id="customerfrom" class="customerfrom"  value="<?php echo $custoemrArray['customer_from']; ?>">
                </td>
            </tr>
            <tr>
                <td class="name">网站:</td>
                <td><input type="text" style="width: 500px;" name="customerwebsite" id="customerwebsite" class="customerwebsite"  value="<?php echo $custoemrArray['customer_website']; ?>"></td>
            </tr>
            <tr>
                <td valign="top" class="name">关注产品:</td>
                <td><textarea class="textareaCom" style="width: 500px;" name="customerattention" id="customerattention" class="customerattention" value="<?php echo $custoemrArray['customer_attention']; ?>"></textarea></td>
            </tr>
            <tr>
                <td valign="top" class="name">备注:</td>
                <td><textarea class="textareaCom" style="width: 500px;" name="customerremarks" id="customerremarks" class="customerremarks" value="<?php echo $custoemrArray['customer_remarks']; ?>"></textarea></td>
            </tr>
        </table>
        <h3 class="title">主联系人信息</h3>
        <table class="bottomTable">
            <tr>
                <td class="doublename">主联系人<span style="color:red">[*]</span>:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="custcontactName" id="custcontactName" class="custcontactName" value="<?php echo $custoemrArray['contact_name']; ?>"></td>
                <td class="doublename">电子邮箱<span style="color:red">[*]</span>:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="custcontactEmail" id="custcontactEmail" class="custcontactEmail" value="<?php echo $custoemrArray['contact_email']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">电话:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="custcontactTel" id="custcontactTel" class="custcontactTel" value="<?php echo $custoemrArray['contact_tel']; ?>"></td>
                <td class="doublename">传真:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="custcontactFax" id="custcontactFax" class="custcontactFax" value="<?php echo $custoemrArray['contact_fax']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">MSN:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="custcontactMSN" id="custcontactMSN" class="custcontactMSN" value="<?php echo $custoemrArray['contact_msn']; ?>"></td>
                <td class="doublename">手机:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="custcontactPhone" id="custcontactPhone" class="custcontactPhone" value="<?php echo $custoemrArray['contact_phone']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">Skype:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="custcontactSkype" id="custcontactSkype" class="custcontactSkype" value="<?php echo $custoemrArray['contact_skype']; ?>"></td>
                <td class="doublename">其他联系方式:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="custcontactOther" id="custcontactOther" class="custcontactOther" value="<?php echo $custoemrArray['contact_other']; ?>"></td>
            </tr>
        </table>

    </div>
    <div class="bottom_button">
        <input type="submit" value="保存" class="save" flagwho="addcustomer">
        <input type="button" value="关闭" class="close">
    </div>
    <input type="hidden" value="addcustomer" name="subwho">
    <input type="hidden" value="<?php echo $customerId; ?>" name="customerid">
    <input type="hidden" value="<?php echo $custoemrArray['customer_first_contacter']; ?>" name="contactid">
</form>