<?php

if (!defined("ROOT"))
    define("ROOT", dirname(__FILE__) . "/../../");
include(ROOT . "/../trade_inc/conf.inc");
include(ROOT . "/../trade_inc/lib/tools.inc");
include(ROOT . "/../trade_inc/lib/cookie.inc");
include(ROOT . "/../trade_inc/lib/myPDO.inc");
include(ROOT . "/../trade_inc/lib/commonFun.inc");
include(ROOT . "/../trade_inc/data/db.inc");
include(ROOT . "/../trade_inc/data/userHandler.inc");
include(ROOT . "/../trade_inc/data/permissionDataHandler.inc");
include(ROOT . "/../trade_inc/facade/cookieManager.inc");
include (ROOT . "/../trade_inc/data/contactHandler.inc");
include (ROOT . "/../trade_inc/data/userPermissionHandler.inc");
include (ROOT . "/../trade_inc/data/customerHandler.inc");
include (ROOT . "/../trade_inc/facade/customer/requestCustomer.inc");
include(ROOT . "/../trade_inc/pages/common/ajaxHtml.inc");
include(ROOT . "/../trade_inc/template/htmlTemplate.inc");
include (ROOT . "/../trade_inc/data/supplierHandler.inc");
include (ROOT . "/../trade_inc/data/configHandler.inc");
include (ROOT . "/../trade_inc/data/productHandler.inc");
include (ROOT . "/../trade_inc/data/customerGroupHandler.inc");
include (ROOT . "/../trade_inc/data/customsCodeHandler.inc");
include (ROOT . "/../trade_inc/data/sampleHandler.inc");
cookieManager::checkLogin();

$who = Tools::getValue('who', '');
if (!empty($who)) {

    switch ($who) {
        case "getcustomer":
            $htmlArray = array();
            $id = Tools::getValue('id', '');
            $option = Tools::getValue('option', '');
            $pagenum = Tools::getValue('pagenum', '');
            $htmlArray['customer'] = ajaxHtml::getCustomerHtmlByGroup($id, $option, $pagenum);
            $htmlArray['paging'] = ajaxHtml::getCustomerPagingHtmlByGroup($pagenum, $who);
            echo json_encode($htmlArray);
            exit;
        case "getsupplier":
            $htmlArray = array();
            $id = Tools::getValue('id', '');
            $option = Tools::getValue('option', '');
            $pagenum = Tools::getValue('pagenum', '');
            $htmlArray['customer'] = ajaxHtml::getSupplierHtmlByGroup($id, $option, $pagenum);
            $htmlArray['paging'] = ajaxHtml::getSupplierPagingHtmlByGroup($pagenum, $who);
            echo json_encode($htmlArray);
            exit;
        case "getproduct":
            $htmlArray = array();
            $id = Tools::getValue('id', '');
            $option = Tools::getValue('option', '');
            $pagenum = Tools::getValue('pagenum', '');
            $htmlArray['customer'] = ajaxHtml::getProductHtmlByGroup($id, $option, $pagenum);
            $htmlArray['paging'] = ajaxHtml::getProductPagingHtmlByGroup($pagenum, $id, $who);
            echo json_encode($htmlArray);
            exit;
        case "getcustomscode":
            $htmlArray = array();
            $pagenum = Tools::getValue('pagenum', '');
            $htmlArray['customer'] = ajaxHtml::getCustomsCodeHtmlByGroup($pagenum);
            $htmlArray['paging'] = ajaxHtml::getCustomsCodePagingHtmlByGroup($pagenum, $who);
            echo json_encode($htmlArray);
            exit;
        case "getsample":
            $htmlArray = array();
            $pagenum = Tools::getValue('pagenum', '');
            $option = Tools::getValue('option', '');
            $htmlArray['customer'] = ajaxHtml::getSampleHtmlByStatus($pagenum,$option);
            $htmlArray['paging'] = ajaxHtml::getSamplePagingHtmlByStatus($pagenum, $option,$who);
            echo json_encode($htmlArray);
            exit;
        default:
            break;
    }
}
?>
