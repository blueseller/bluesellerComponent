<?php
$sampleId = Tools::getValue('id', '');
$sampleArray = array();
$typewho = 'addsample';
if (!empty($sampleId)) {
    $sampleArray = sampleHandler::getSampleById($sampleId);
    $typewho = 'updatesample';
}

$sampleArray = sampleBean::setSampleData($sampleArray);
$userId = $_COOKIE['userId'];
$customerpermission = userPermissionHandler::getCustomerPermissionByUserId($userId);
$customers = customerHandler::getCustomersListBypermission($customerpermission);
$selectCustomerHtml = '<option value=""></option>';

foreach ($customers as $value) {
    $selectCustomerHtml .='<option value="' . $value["id"] . '"';
    if ($sampleArray['toaddress_customerid'] == $value["id"]) {
        $selectCustomerHtml .=' selected';
    }
    $selectCustomerHtml .= '>' . $value['customer_name'];
    $selectCustomerHtml .= '</option>';
}
?>

<form id="pop_form" action="" method="post">
    <div class="addNotice divwidth2">

        <h3 class="toptitle title">新建样品</h3>
        <table class="addCustomer">
            <tr>
                <td class="doublename">样品编号:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="sample_code" id="sample_code" class="sample_code" value="<?php echo $sampleArray['sample_code']; ?>"></td>
                <td class="doublename">寄入或寄出:</td>
                <td class="doubleinput"><input style="width: 10px;line-height: 20px;" type="radio" value="寄出" name="sample_status" checked>寄出<input style="width: 10px;" type="radio" value="寄入" name="sample_status">寄入</td>
            </tr>
            <tr>
                <td class="doublename">国内或国外:</td>
                <td class="doubleinput"><input style="width: 10px;line-height: 20px;" type="radio" value="国外" name="sample_isto_oversea" checked>国外<input style="width: 10px;" type="radio" value="国内" name="sample_isto_oversea">国内</td>
                <td class="doublename">寄样日期:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="sample_to_date" id="sample_to_date" class="sample_to_date" value="<?php echo $sampleArray['sample_to_date']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">快递公司<span style="color:red">[*]</span>:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="sample_express_company" id="sample_express_company" class="sample_express_company" value="<?php echo $sampleArray['sample_express_company']; ?>"></td>
                <td class="doublename">快递公司电话:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="sample_express_company_phone" id="sample_express_company_phone" class="sample_express_company_phone" value="<?php echo $sampleArray['sample_express_company_phone']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">快件单号<span style="color:red">[*]</span>:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="sample_express_num" id="sample_express_num" class="sample_express_num" value="<?php echo $sampleArray['sample_express_num']; ?>"></td>
                <td class="doublename">客户名称:<span style="color:red">[*]</span>:</td>
                <td class="doubleinput">
                    <select name="toaddress_customerid" id="toaddress_customerid" class="toaddress_customerid" style="width: 200px;">
                        <?php echo $selectCustomerHtml; ?>">
                    </select>
            </tr>
            <tr>
                <td class="doublename">寄件国家:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="toaddress_country" id="toaddress_country" class="toaddress_country" value="<?php echo $sampleArray['toaddress_country']; ?>"></td>
                <td class="doublename">寄件城市:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="toaddress_city" id="toaddress_city" class="toaddress_city" value="<?php echo $sampleArray['toaddress_city']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">寄件地址:</td>
                <td colspan="3"><input type="text" style="width: 570px" name="toaddress_address" id="toaddress_address" class="toaddress_address" value="<?php echo $sampleArray['toaddress_address']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">寄件状态:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="sample_express_status" id="sample_express_status" class="sample_express_status" value="<?php echo $sampleArray['sample_express_status']; ?>"></td>
                <td class="doublename">付费方式:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="sample_express_price_type" id="sample_express_price_type" class="sample_express_price_type" value="<?php echo $sampleArray['sample_express_price_type']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">快递费币种:</td>
                <td class="doubleinput"><input type="text" readonly style="width: 200px;" name="sample_express_price_bizhong" id="sample_express_price_bizhong" class="sample_express_price_bizhong" value="人民币"></td>
                <td class="doublename">运费(人民币):</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="sample_express_price" id="sample_express_price" class="sample_express_price" value="<?php echo $sampleArray['sample_express_price']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">样品费(人民币):</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="sample_price_rmb" id="sample_price_rmb" class="sample_price_rmb" value="<?php echo $sampleArray['sample_price_rmb']; ?>"></td>
                <td class="doublename">样品费(美元):</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="sample_price_usd" id="sample_price_usd" class="sample_price_usd" value="<?php echo $sampleArray['sample_price_usd']; ?>"></td>
            </tr>
        </table>

    </div>
    <div class="bottom_button">
        <input type="submit" value="保存" class="save" flagwho="addsample">
        <input type="button" value="关闭" class="close">
    </div>
    <input type="hidden" value="<?php echo $typewho; ?>" name="subwho">
    <input type="hidden" value="<?php echo $sampleId; ?>" name="sampleid">
</form>