<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of productPriceBean
 *
 * @author liukai
 */
class productPriceBean {
    private static $productPriceArray = array();

    public function __construct() {

        self::$productPriceArray['price_cost_cn'] = Tools::getValue('pricecostcn', '');
        self::$productPriceArray['price_sale_cn'] = Tools::getValue('pricesalecn', '');
        self::$productPriceArray['price_cost_en'] = Tools::getValue('pricecosten', '');
        self::$productPriceArray['price_sale_en'] = Tools::getValue('pricesaleen', '');
        self::$productPriceArray['price_cost_other'] = Tools::getValue('pricecostother', '');
        self::$productPriceArray['price_sale_other'] = Tools::getValue('pricesaleother', '');
    }
    
    public static function getProductPriceArray(){
        return self::$productPriceArray;
    }
}

?>
