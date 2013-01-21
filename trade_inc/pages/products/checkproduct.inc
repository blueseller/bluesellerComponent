<?php
include(ROOT . "trade_inc/pages/products/checkleft.inc");

$productId = Tools::getValue('id', '');
$productArray = array();
$typewho = 'addproduct';
if (!empty($productId)) {
    $productArray = productHandler::getProductById($productId);
    $typewho = 'updateproduct';
}
$productArray = productBean::setProductData($productArray);
?>
<div class="ckecksContent">
    <div class="checkoptions">

    </div>
    <table class="checktable">
        <span class="checktitle">基础信息</span>
        <tr>
            <td class="doublename">产品编码:</td>
            <td class="doubleinput"><label><?php echo $productArray['product_id']; ?></label></td>
            <td class="doublename">公司货号:</td>
            <td class="doubleinput"><label><?php echo $productArray['company_productcode']; ?></label></td>
        </tr>
        <tr>
            <td class="doublename">产品类型:</td>
            <td class="doubleinput"><label><?php echo $productArray['product_type']; ?></label></td>
            <td class="doublename">产品所属分组:</td>
            <td class="doubleinput"><label><?php echo customerGroupHandler::getGroupNameById($productArray['product_group']); ?></label></td>
        </tr>
        <tr>
            <td class="doublename">产品中文名:</td>
            <td class="doubleinput"><label><?php echo $productArray['product_chinaname']; ?></label></td>
            <td class="doublename">中文描述:</td>
            <td class="doubleinput"><label><?php echo $productArray['product_chinacontent']; ?></label></td>
        </tr>
        <tr>
            <td class="doublename">产品英文名:</td>
            <td class="doubleinput"><label><?php echo $productArray['product_englishname']; ?></label></td>
            <td class="doublename">英文描述:</td>
            <td class="doubleinput"><label><?php echo $productArray['product_englishcontent']; ?></label></td>
        </tr>
        <tr>
            <td class="doublename">产品简称:</td>
            <td class="doubleinput"><label><?php echo $productArray['product_shortname']; ?></label></td>
            <td class="doublename">海关编码:</td>
            <td class="doubleinput"><label><?php echo $productArray['product_customscode']; ?></label></td>
        </tr>
        <tr>
            <td class="doublename">中文型号:</td>
            <td class="doubleinput"><label><?php echo $productArray['product_model_cn']; ?></label></td>
            <td class="doublename">中文规格:</td>
            <td class="doubleinput"><label><?php echo $productArray['product_format_cn']; ?></label></td>
        </tr>
        <tr>
            <td class="doublename">英文型号:</td>
            <td class="doubleinput"><label><?php echo $productArray['product_model_en']; ?></label></td>
            <td class="doublename">英文规格:</td>
            <td class="doubleinput"><label><?php echo $productArray['product_format_en']; ?></label></td>
        </tr>
        <tr>
            <td class="doublename">计量单位:</td>
            <td class="doubleinput"><label><?php echo $productArray['product_unit']; ?></label></td>
            <td colspan="2"></td>
        </tr>
    </table>

    <table class="checktable checkmiddle">
        <span class="checktitle">价格信息</span>
        <tr>
            <td class="doublename">成本单价(人民币):</td>
            <td class="doubleinput"><label><?php echo $productArray['price_cost_cn']; ?></label></td>
            <td class="doublename">含税销售指导价格(人民币):</td>
            <td class="doubleinput"><label><?php echo $productArray['price_sale_cn']; ?></label></td>
        </tr>
        <tr>
            <td class="doublename">成本单价(美元):</td>
            <td class="doubleinput"><label><?php echo $productArray['price_cost_en']; ?></label></td>
            <td class="doublename">含税销售指导价格(美元):</td>
            <td class="doubleinput"><label><?php echo $productArray['price_sale_en']; ?></label></td>
        </tr>
        <tr>
            <td class="doublename">其他币种:</td>
            <td class="doubleinput"><label><?php echo $productArray['price_cost_other']; ?></label></td>
            <td class="doublename">外币销售指导价:</td>
            <td class="doubleinput"><label><?php echo $productArray['price_sale_other']; ?></label></td>
        </tr>  
    </table>
</div>