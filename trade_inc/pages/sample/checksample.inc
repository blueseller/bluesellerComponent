<?php
$sampleId = Tools::getValue('id', '');
$sampleArray = array();
if (!empty($sampleId)) {
    $sampleArray = sampleHandler::getSampleById($sampleId);
}

$sampleArray = sampleBean::setSampleData($sampleArray);

$guonei = "";
$guowai = "";
$jichu = "";
$jiru = "";

if ($sampleArray['sample_status'] == "寄出") {
    $jichu = "checked";
} else {
    $jiru = "checked";
}

if ($sampleArray['sample_isto_oversea'] == "国外") {
    $guonei = "checked";
} else {
    $guowai = "checked";
}
?>

<form id="pop_form" action="" method="post">
    <div class="addNotice divwidth2">

        <h3 class="toptitle title">查看样品</h3>
        <table class="addCustomer">
            <tr>
                <td class="doublename">样品编号:</td>
                <td class="doubleinput" style="border-bottom: 1px solid #113236;width: 200px"><span ><?php echo $sampleArray['sample_code']; ?></span></td>
                <td class="doublename">寄入或寄出:</td>
                <td class="doubleinput"><input style="width: 10px;line-height: 20px;" type="radio" value="寄出" name="sample_status" <?php echo $jichu;?> >寄出<input style="width: 10px;" type="radio" value="寄入" name="sample_status" <?php echo $jiru;?>>寄入</td>
            </tr>
            <tr>
                <td class="doublename">国内或国外:</td>
                <td class="doubleinput"><input style="width: 10px;line-height: 20px;" type="radio" value="国外" name="sample_isto_oversea" <?php echo $guowai;?>>国外<input style="width: 10px;" type="radio" value="国内" name="sample_isto_oversea" <?php echo $guonei;?>>国内</td>
                <td class="doublename">寄样日期:</td>
                <td class="doubleinput" style="border-bottom: 1px solid #113236;width: 200px"><span><?php echo $sampleArray['sample_to_date']; ?></span></td>
            </tr>
            <tr>
                <td class="doublename">快递公司<span style="color:red">[*]</span>:</td>
                <td class="doubleinput" style="border-bottom: 1px solid #113236;width: 200px"><span><?php echo $sampleArray['sample_express_company']; ?></span></td>
                <td class="doublename">快递公司电话:</td>
                <td class="doubleinput" style="border-bottom: 1px solid #113236;width: 200px"><span><?php echo $sampleArray['sample_express_company_phone']; ?></span></td>
            </tr>
            <tr>
                <td class="doublename">快件单号<span style="color:red">[*]</span>:</td>
                <td class="doubleinput" style="border-bottom: 1px solid #113236;width: 200px"><span><?php echo $sampleArray['sample_express_num']; ?></span></td>
                <td class="doublename">客户名称:<span style="color:red">[*]</span>:</td>
                <td class="doubleinput" style="border-bottom: 1px solid #113236;width: 200px"><span><?php echo $sampleArray['sample_express_num']; ?></span></td>
            </tr>
            <tr>
                <td class="doublename">寄件国家:</td>
                <td class="doubleinput" style="border-bottom: 1px solid #113236;width: 200px"><span><?php echo $sampleArray['toaddress_country']; ?></span></td>
                <td class="doublename">寄件城市:</td>
                <td class="doubleinput" style="border-bottom: 1px solid #113236;width: 200px"><span><?php echo $sampleArray['toaddress_city']; ?></span></td>
            </tr>
            <tr>
                <td class="doublename">寄件地址:</td>
                <td colspan="3" style="border-bottom: 1px solid #113236;width: 200px"><span><?php echo $sampleArray['toaddress_address']; ?></span></td>
            </tr>
            <tr>
                <td class="doublename">寄件状态:</td>
                <td class="doubleinput" style="border-bottom: 1px solid #113236;width: 200px"><span><?php echo $sampleArray['sample_express_status']; ?></span></td>
                <td class="doublename">付费方式:</td>
                <td class="doubleinput" style="border-bottom: 1px solid #113236;width: 200px"><span><?php echo $sampleArray['sample_express_price_type']; ?></span></td>
            </tr>
            <tr>
                <td class="doublename">快递费币种:</td>
                <td class="doubleinput" style="border-bottom: 1px solid #113236;width: 200px"><span>人民币</span></td>
                <td class="doublename">运费(人民币):</td>
                <td class="doubleinput" style="border-bottom: 1px solid #113236;width: 200px"><span><?php echo $sampleArray['sample_express_price']; ?></span></td>
            </tr>
            <tr>
                <td class="doublename">样品费(人民币):</td>
                <td class="doubleinput" style="border-bottom: 1px solid #113236;width: 200px"><span><?php echo $sampleArray['sample_price_rmb']; ?></span></td>
                <td class="doublename">样品费(美元):</td>
                <td class="doubleinput" style="border-bottom: 1px solid #113236;width: 200px"><span><?php echo $sampleArray['sample_price_usd']; ?></span></td>
            </tr>
        </table>

    </div>
    <div class="bottom_button">
        <input type="button" value="关闭" class="close">
    </div>

</form>