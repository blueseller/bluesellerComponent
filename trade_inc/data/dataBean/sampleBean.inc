<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of sampleBean
 *
 * @author liukai
 */
class sampleBean {

    private static $sampleArray = array();

    public function __construct() {

        self::$sampleArray['sample_code'] = Tools::getValue('sample_code', '');
        self::$sampleArray['sample_status'] = Tools::getValue('sample_status', '');
        self::$sampleArray['sample_isto_oversea'] = Tools::getValue('sample_isto_oversea', '');
        self::$sampleArray['sample_to_date'] = Tools::getValue('sample_to_date', '');
        self::$sampleArray['sample_express_company'] = Tools::getValue('sample_express_company', '');
        self::$sampleArray['sample_express_company_phone'] = Tools::getValue('sample_express_company_phone', '');
        self::$sampleArray['sample_express_num'] = Tools::getValue('sample_express_num', '');
        self::$sampleArray['toaddress_customerid'] = Tools::getValue('toaddress_customerid', '');
        self::$sampleArray['toaddress_country'] = Tools::getValue('toaddress_country', '');
        self::$sampleArray['toaddress_city'] = Tools::getValue('toaddress_city', '');
        self::$sampleArray['toaddress_address'] = Tools::getValue('toaddress_address', '');
        self::$sampleArray['sample_express_status'] = Tools::getValue('sample_express_status', '');
        self::$sampleArray['sample_express_price_type'] = Tools::getValue('sample_express_price_type', '');
        self::$sampleArray['sample_express_price_bizhong'] = Tools::getValue('sample_express_price_bizhong', '');
        self::$sampleArray['sample_express_price'] = Tools::getValue('sample_express_price', '');
        self::$sampleArray['sample_price_rmb'] = Tools::getValue('sample_price_rmb', '');
        self::$sampleArray['sample_price_usd'] = Tools::getValue('sample_price_usd', '');
    }

    public function getSampleArray() {
        return self::$sampleArray;
    }

    public static function setSampleData($param) {
        
        $sampleArray = array();
        $sampleArray['sample_code'] = isset($param['sample_code']) ? $param['sample_code'] : '';
        $sampleArray['sample_status'] = isset($param['sample_status']) ? $param['sample_status'] : '';
        $sampleArray['whosend'] = isset($param['whosend']) ? $param['whosend'] : '';
        $sampleArray['sample_isto_oversea'] = isset($param['sample_isto_oversea']) ? $param['sample_isto_oversea'] : '';
        $sampleArray['sample_to_date'] = isset($param['sample_to_date']) ? $param['sample_to_date'] : '';
        $sampleArray['sample_express_company'] = isset($param['sample_express_company']) ? $param['sample_express_company'] : '';
        $sampleArray['sample_express_company_phone'] = isset($param['sample_express_company_phone']) ? $param['sample_express_company_phone'] : '';
        $sampleArray['sample_express_num'] = isset($param['sample_express_num']) ? $param['sample_express_num'] : '';
        $sampleArray['sample_express_type'] = isset($param['sample_express_type']) ? $param['sample_express_type'] : '';
        $sampleArray['sample_express_price_type'] = isset($param['sample_express_price_type']) ? $param['sample_express_price_type'] : '';
        $sampleArray['sample_express_price_bizhong'] = isset($param['sample_express_price_bizhong']) ? $param['sample_express_price_bizhong'] : '';
        $sampleArray['sample_express_price'] = isset($param['sample_express_price']) ? $param['sample_express_price'] : '';
        $sampleArray['sample_express_status'] = isset($param['sample_express_status']) ? $param['sample_express_status'] : '';
        $sampleArray['sample_price_rmb'] = isset($param['sample_price_rmb']) ? $param['sample_price_rmb'] : '';
        $sampleArray['sample_price_usd'] = isset($param['sample_price_usd']) ? $param['sample_price_usd'] : '';
        $sampleArray['toaddress_country'] = isset($param['toaddress_country']) ? $param['toaddress_country'] : '';
        $sampleArray['toaddress_city'] = isset($param['toaddress_city']) ? $param['toaddress_city'] : '';
        $sampleArray['toaddress_address'] = isset($param['toaddress_address']) ? $param['toaddress_address'] : '';
        $sampleArray['toaddress_who'] = isset($param['toaddress_who']) ? $param['toaddress_who'] : '';
        $sampleArray['toaddress_customerid'] = isset($param['toaddress_customerid']) ? $param['toaddress_customerid'] : '';
        return $sampleArray;
    }

}

?>
