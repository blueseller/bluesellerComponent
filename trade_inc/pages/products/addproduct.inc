<?php
$productId = Tools::getValue('id', '');
$productArray = array();
$typewho = 'addproduct'; 
if (!empty($productId)) {
    $productArray = productHandler::getProductById($productId);
    $typewho = 'updateproduct'; 
}
$productArray = productBean::setProductData($productArray);
?>

<form id="pop_form" action="" method="post">
    <div class="addNotice divwidth2">

        <h3 class="toptitle title">新建产品</h3>
        <table class="addCustomer">
            <tr>
                <td class="doublename">产品编码:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="productCode" id="productCode" class="productCode" value="<?php echo $productArray['product_id']; ?>"></td>
                <td class="doublename">公司货号:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="companyproducrcode" id="companyproducrcode" class="companyproducrcode" value="<?php echo $productArray['company_productcode']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">产品类型:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="producttype" id="producttype" class="producttype" value="<?php echo $productArray['product_type']; ?>"></td>
                <td class="doublename">所属分组<span style="color:red">[*]</span>:</td>
                <td class="doubleinput">
                    <select style="width: 200px;" name="productgroup" id="productgroup" class="productgroup">
                        <?php
                        $groups = customerGroupHandler::getGroups("product");
                        $groupSelectHtml = '';
                        foreach ($groups as $value) {
                            $groupSelectHtml.='<option value="' . $value['id'] . '"';
                            if ($productArray['product_group'] == $value['id']) {
                                $groupSelectHtml.=' selected ';
                            }
                            $groupSelectHtml.='>' . $value['customer_group_name'] . '</option>';
                        }
                        echo $groupSelectHtml;
                        ?>
                    </select>
            </tr>
            <tr>
                <td class="doublename">产品中文名<span style="color:red">[*]</span>:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="productnamecn" id="productnamecn" class="productnamecn" value="<?php echo $productArray['product_chinaname']; ?>"></td>
                <td class="doublename">中文描述:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="productcontentcn" id="productcontentcn" class="productcontentcn" value="<?php echo $productArray['product_chinacontent']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">产品英文名<span style="color:red">[*]</span>:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="productnameen" id="productnameen" class="productnameen" value="<?php echo $productArray['product_englishname']; ?>"></td>
                <td class="doublename">英文描述:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="productcontenten" id="productcontenten" class="productcontenten" value="<?php echo $productArray['product_englishcontent']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">产品简称:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="productshortname" id="productshortname" class="productshortname" value="<?php echo $productArray['product_shortname']; ?>"></td>
                <td class="doublename">海关编码:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="productcustomscode" id="productcustomscode" class="productcustomscode" value="<?php echo $productArray['product_customscode']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">中文型号:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="productmodelcn" id="productmodelcn" class="productmodelcn" value="<?php echo $productArray['product_model_cn']; ?>"></td>
                <td class="doublename">中文规格:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="productformatcn" id="productformatcn" class="productformatcn" value="<?php echo $productArray['product_format_cn']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">英文型号:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="productmodelen" id="productmodelen" class="productmodelen" value="<?php echo $productArray['product_model_en']; ?>"></td>
                <td class="doublename">英文规格:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="productformaten" id="productformaten" class="productformaten" value="<?php echo $productArray['product_format_en']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">计量单位:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="productunit" id="productunit" class="productunit" value="<?php echo $productArray['product_unit']; ?>"></td>
                <td colspan="2"></td>
            </tr>
        </table>
        
        <table class="addCustomer secondetable" style="margin-top: 30px;">
            <tr>
                <td class="doublename">成本单价(人民币):</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="pricecostcn" id="pricecostcn" class="pricecostcn" value="<?php echo $productArray['price_cost_cn']; ?>"></td>
                <td class="doublename">含税销售指导价（人民币）:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="pricesalecn" id="pricesalecn" class="pricesalecn" value="<?php echo $productArray['price_sale_cn']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">成本单价(美元):<span style="color:red">[*]</span>:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="pricecosten" id="pricecosten" class="pricecosten" value="<?php echo $productArray['price_cost_en']; ?>"></td>
                <td class="doublename">含税销售指导价（美元）:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="pricesaleen" id="pricesaleen" class="pricesaleen" value="<?php echo $productArray['price_sale_en']; ?>"></td>
            </tr>
            <tr>
                <td class="doublename">其他币种:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="pricecostother" id="pricecostother" class="pricecostother" value="<?php echo $productArray['price_cost_other']; ?>"></td>
                <td class="doublename">外币销售指导价:</td>
                <td class="doubleinput"><input type="text" style="width: 200px;" name="pricesaleother" id="pricesaleother" class="pricesaleother" value="<?php echo $productArray['price_sale_other']; ?>"></td>
            </tr>
        </table>

    </div>
    <div class="bottom_button">
        <input type="submit" value="保存" class="save" flagwho="addproduct">
        <input type="button" value="关闭" class="close">
    </div>
    <input type="hidden" value="<?php echo $typewho; ?>" name="subwho">
    <input type="hidden" value="<?php echo $productId; ?>" name="productid">
    <input type="hidden" value="<?php echo $productArray['price_id']; ?>" name="price_productid">
</form>