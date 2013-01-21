<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of ajaxHtml
 *
 * @author liukai
 */
class ajaxHtml {

    private static $nowlists = '';
    private static $pressions = '';
    private static $options = '';

    public static function getCustomerHtmlByGroup($id, $option, $pagenum) {
        $userId = $_COOKIE['userId'];
        $permission = userPermissionHandler::getCustomerPermissionByUserId($userId);
        if ($option == "user") {
            $permission = $id;
            $option = '';
        } else if ($option == "grade") {
            $option = 'and customer_grade=' . $id;
        } else if ($option == "group") {
            $option = 'and customer_group=' . $id;
        }
        self::$pressions = $permission;
        self::$options = $option;
        $start = ($pagenum - 1) * Conf::$numlist;
        $customerArray = customerHandler::getCustomerByGroupId($permission, $option, $start, Conf::$numlist);
        self::$nowlists = count($customerArray);
        return self::getCustomerHtml($customerArray);
    }

    private static function getCustomerHtml($customerArray) {
        $listHtml = htmlTemplate::customerlistHTML();
        foreach ($customerArray as $value) {
            $listHtml.='<tr id="' . $value['id'] . '" class="' . $value['customer_name'] . '">';
            $listHtml.='<td>' . $value['customer_id'] . '</td>';
            $listHtml.='<td>' . requestCustomer::getRemindHtml($value['id'], $value['customer_remind_id']) . '</td>';
            $listHtml.='<td>' . $value['customer_name'] . '</td>';
            $listHtml.='<td>' . $value['contact_name'] . '</td>';
            $listHtml.='<td>' . $value['contact_email'] . '</td>';
            $listHtml.='<td>' . $value['contact_tel'] . '</td>';
            $listHtml.='<td>' . $value['customer_country'] . '</td>';
            $listHtml.='<td>' . $value['customer_province'] . '</td>';
            $listHtml.='<td>' . requestCustomer::getCustomerIsWhohave($value['customer_whohave']) . '</td>';
            $listHtml.='<td>' . $value['contact_lastcontacttime'] . '</td>';
            $listHtml.='<td>' . $value['customer_from'] . '</td>';
            $listHtml.='<td>' . $value['contact_fax'] . '</td>';
            $listHtml.='<td>' . $value['customer_attention'] . '</td>';
            $listHtml.='</tr>';
        }
        return $listHtml;
    }

    public static function getCustomerPagingHtmlByGroup($pagenum, $who) {
        $sums = customerHandler::getCustomersCountByOptions(self::$pressions, self::$options);
        $sumpages = ceil($sums / Conf::$numlist);
        return commonFun::paging($pagenum, $sumpages, self::$nowlists, $sums, $who);
    }

    public static function getSupplierHtmlByGroup($id, $option, $pagenum) {
        $userId = $_COOKIE['userId'];
        $permission = userPermissionHandler::getCustomerPermissionByUserId($userId);
        if ($option == "user") {
            $permission = $id;
            $option = '';
        } else if ($option == "grade") {
            $option = 'and supplier_grade=' . $id;
        } else if ($option == "group") {
            $option = 'and supplier_group=' . $id;
        }
        self::$pressions = $permission;
        self::$options = $option;
        $start = ($pagenum - 1) * Conf::$numlist;
        $supplierArray = supplierHandler::getSupplierByGroupId($permission, $option, $start, Conf::$numlist);
        self::$nowlists = count($supplierArray);
        return self::getSupplierHtml($supplierArray);
    }

    private static function getSupplierHtml($supplierArray) {
        $listHtml = htmlTemplate::supplierListHTML();
        $grades = configHandler::getConfigValueByKey('customer_grade_images');
        $grades = explode("|", $grades['config_value']);
        foreach ($supplierArray as $value) {
            $listHtml.='<tr id="' . $value['id'] . '" class="' . $value['supplier_name'] . '">';
            $listHtml.='<td>' . $value['supplier_id'] . '</td>';
            $listHtml.='<td>' . $value['supplier_name'] . '</td>';
            $listHtml.='<td>' . $value['supplier_addr'] . '</td>';
            $listHtml.='<td>' . $value['supplier_contact_name'] . '</td>';
            $listHtml.='<td>' . $value['supplier_contact_email'] . '</td>';
            $listHtml.='<td>' . $value['supplier_contact_tel'] . '</td>';
            $listHtml.='<td>' . $value['supplier_contact_phone'] . '</td>';
            $listHtml.='<td>' . $grades[$value['supplier_grade'] - 1] . '</td>';
            $listHtml.='<td>' . $value['supplier_group'] . '</td>';
            $listHtml.='</tr>';
        }
        return $listHtml;
    }

    public static function getSupplierPagingHtmlByGroup($pagenum, $who) {
        $sums = supplierHandler::getSupplierCountByOptions(self::$pressions, self::$options);
        $sumpages = ceil($sums / Conf::$numlist);
        return commonFun::paging($pagenum, $sumpages, self::$nowlists, $sums, $who);
    }

    public static function getProductHtmlByGroup($id, $option, $pagenum) {
        $listHtml = htmlTemplate::productListHTML();
        self::$nowlists = Conf::$numlist;
        $start = ($pagenum - 1) * Conf::$numlist;
        $productArray = productHandler::getProductsByGroupId($id, $start, Conf::$numlist);
        foreach ($productArray as $value) {
            $listHtml.='<tr id="' . $value['id'] . '" class="">';
            $listHtml.='<td>' . $value['product_id'] . '</td>';
            $listHtml.='<td>' . $value['company_productcode'] . '</td>';
            $listHtml.='<td>' . $value['product_chinaname'] . '</td>';
            $listHtml.='<td>' . $value['product_englishname'] . '</td>';
            $listHtml.='<td>' . customerGroupHandler::getGroupNameById($value['product_group']) . '</td>';
            $listHtml.='<td>' . $value['product_model_cn'] . '</td>';
            $listHtml.='<td>' . $value['product_format_cn'] . '</td>';
            $listHtml.='<td>' . $value['product_model_en'] . '</td>';
            $listHtml.='<td>' . $value['product_format_en'] . '</td>';
            $listHtml.='<td>' . $value['price_cost_cn'] . '</td>';
            $listHtml.='<td>' . $value['price_sale_cn'] . '</td>';
            $listHtml.='<td>' . $value['create_time'] . '</td>';
            $listHtml.='</tr>';
        }
        return $listHtml;
    }

    public static function getProductPagingHtmlByGroup($pagenum, $id, $who) {
        $sums = productHandler::getProductCountByOptions($id);
        $sumpages = ceil($sums / Conf::$numlist);
        return commonFun::paging($pagenum, $sumpages, self::$nowlists, $sums, $who);
    }

    public static function getCustomsCodeHtmlByGroup($pagenum) {
        $listHtml = htmlTemplate::customercodeListHTML();
        self::$nowlists = Conf::$numlist;
        $start = ($pagenum - 1) * Conf::$numlist;
        $productArray = customsCodeHandler::getCustomsCodeList($start, Conf::$numlist);
        foreach ($productArray as $value) {
            $listHtml.='<tr>';
            $listHtml.='<td>' . $value['customs_code_id'] . '</td>';
            $listHtml.='<td>' . $value['customs_code_name'] . '</td>';
            $listHtml.='<td>' . $value['customs_code_mark'] . '</td>';
            $listHtml.='<td>' . $value['customs_code_unit1'] . '</td>';
            $listHtml.='<td>' . $value['customs_code_unit2'] . '</td>';
            $listHtml.='<td>' . $value['customs_code_benefit_tax'] . '</td>';
            $listHtml.='<td>' . $value['customs_code_general_tax'] . '</td>';
            $listHtml.='<td>' . $value['customs_code_value_added_tax'] . '</td>';
            $listHtml.='<td>' . $value['customs_code_regulatory_conditions'] . '</td>';
            $listHtml.='<td>' . $value['customs_code_commodity_inspection'] . '</td>';
            $listHtml.='</tr>';
        }
        return $listHtml;
    }

    public static function getCustomsCodePagingHtmlByGroup($pagenum, $who) {
        $sums = customsCodeHandler::getCustomsCodeSumNum();
        $sumpages = ceil($sums / Conf::$numlist);
        return commonFun::paging($pagenum, $sumpages, self::$nowlists, $sums, $who);
    }

    public static function getSampleHtmlByStatus($pagenum, $option) {
        $listHtml = htmlTemplate::sampleListHTML();
        self::$nowlists = Conf::$numlist;
        $start = ($pagenum - 1) * Conf::$numlist;
        $sampleArray = sampleHandler::getSamplesListByStatus($option, $start, Conf::$numlist);
        foreach ($sampleArray as $value) {
            $customer = customerHandler::getCustomerOnlyById($value['toaddress_customerid']);
            $listHtml.='<tr id="' . $value['id'] . '">';
            $listHtml.='<td>' . $value['sample_code'] . '</td>';
            $listHtml.='<td>' . $value['sample_express_num'] . '</td>';
            $listHtml.='<td>' . $value['sample_status'] . '</td>';
            $listHtml.='<td>' . $customer['customer_name'] . '</td>';
            $listHtml.='<td>' . $value['sample_express_company'] . '</td>';
            $listHtml.='<td>' . $value['sample_express_price_type'] . '</td>';
            $listHtml.='<td>' . $value['sample_express_price'] . '</td>';
            $listHtml.='<td>' . $value['sample_price_rmb'] . '</td>';
            $listHtml.='<td>' . $value['sample_price_usd'] . '</td>';
            $listHtml.='<td>' . userHandler::getUserNameById($value['whosend']) . '</td>';
            $listHtml.='<td>' . $value['sample_to_date'] . '</td>';
            $listHtml.='<td>' . $value['toaddress_country'] . '</td>';
            $listHtml.='<td>' . $value['toaddress_city'] . '</td>';
            $listHtml.='<td>' . $value['toaddress_address'] . '</td>';
            $listHtml.='<td>' . $value['sample_express_status'] . '</td>';
            $listHtml.='</tr>';
        }
        return $listHtml;
    }

    public static function getSamplePagingHtmlByStatus($pagenum, $option, $who) {
        $sums = sampleHandler::getSamplesSumNumByStatus($option);
        $sumpages = ceil($sums / Conf::$numlist);
        return commonFun::paging($pagenum, $sumpages, self::$nowlists, $sums, $who);
    }

}

?>
