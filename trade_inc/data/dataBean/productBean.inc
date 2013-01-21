<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of productBean
 *
 * @author liukai
 */
class productBean {

    
    private static $productArray = array();

    public function __construct() {
        
        self::$productArray['product_id'] = Tools::getValue('productCode', '');
        self::$productArray['company_productcode'] = Tools::getValue('companyproducrcode', '');
        self::$productArray['product_type'] = Tools::getValue('producttype', '');
        self::$productArray['product_group'] = Tools::getValue('productgroup', '');
        self::$productArray['product_chinaname'] = Tools::getValue('productnamecn', '');
        self::$productArray['product_chinacontent'] = Tools::getValue('productcontentcn', '');
        self::$productArray['product_englishname'] = Tools::getValue('productnameen', '');
        self::$productArray['product_englishcontent'] = Tools::getValue('productcontenten', '');
        self::$productArray['product_shortname'] = Tools::getValue('productshortname', '');
        self::$productArray['product_customscode'] = Tools::getValue('productcustomscode', '');
        self::$productArray['product_model_cn'] = Tools::getValue('productmodelcn', '');
        self::$productArray['product_format_cn'] = Tools::getValue('productformatcn', '');
        self::$productArray['product_model_en'] = Tools::getValue('productmodelen', '');
        self::$productArray['product_format_en'] = Tools::getValue('productformaten', '');
        self::$productArray['product_unit'] = Tools::getValue('productunit', '');
    }
    
    public static function getProductArray(){
        return self::$productArray;
    }

    public static function setProductData($param) {
        $customerArray = array();
        $customerArray['product_id'] = isset($param['product_id']) ? $param['product_id'] : '';
        $customerArray['company_productcode'] = isset($param['company_productcode']) ? $param['company_productcode'] : '';
        $customerArray['product_type'] = isset($param['product_type']) ? $param['product_type'] : '';
        $customerArray['product_group'] = isset($param['product_group']) ? $param['product_group'] : '';
        $customerArray['product_chinaname'] = isset($param['product_chinaname']) ? $param['product_chinaname'] : '';
        $customerArray['product_chinacontent'] = isset($param['product_chinacontent']) ? $param['product_chinacontent'] : '';
        $customerArray['product_englishname'] = isset($param['product_englishname']) ? $param['product_englishname'] : '';
        $customerArray['product_englishcontent'] = isset($param['product_englishcontent']) ? $param['product_englishcontent'] : '';
        $customerArray['product_shortname'] = isset($param['product_shortname']) ? $param['product_shortname'] : '';
        $customerArray['product_customscode'] = isset($param['product_customscode']) ? $param['product_customscode'] : '';
        $customerArray['product_model_cn'] = isset($param['product_model_cn']) ? $param['product_model_cn'] : '';
        $customerArray['product_format_cn'] = isset($param['product_format_cn']) ? $param['product_format_cn'] : '';
        $customerArray['product_model_en'] = isset($param['product_model_en']) ? $param['product_model_en'] : '';
        $customerArray['product_format_en'] = isset($param['product_format_en']) ? $param['product_format_en'] : '';
        $customerArray['product_unit'] = isset($param['product_unit']) ? $param['product_unit'] : '';
        $customerArray['price_cost_cn'] = isset($param['price_cost_cn']) ? $param['price_cost_cn'] : '';
        $customerArray['price_sale_cn'] = isset($param['price_sale_cn']) ? $param['price_sale_cn'] : '';
        $customerArray['price_cost_en'] = isset($param['price_cost_en']) ? $param['price_cost_en'] : '';
        $customerArray['price_sale_en'] = isset($param['price_sale_en']) ? $param['price_sale_en'] : '';
        $customerArray['price_cost_other'] = isset($param['price_cost_other']) ? $param['price_cost_other'] : '';
        $customerArray['price_sale_other'] = isset($param['price_sale_other']) ? $param['price_sale_other'] : '';
        $customerArray['price_id'] = isset($param['product_price_id']) ? $param['product_price_id'] : '';
        return $customerArray;
    }

}

?>
