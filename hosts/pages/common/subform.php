<?php

if (!defined("ROOT"))
    define("ROOT", dirname(__FILE__) . "/../../../");
include (ROOT . "/trade_inc/lib/tools.inc");
include (ROOT . "/trade_inc/facade/show_who/whoSubFormSelect.inc"); //判断谁提交的表单
include (ROOT . "/trade_inc/data/dataBean/customerBean.inc");
include (ROOT . "/trade_inc/data/dataBean/contactBean.inc");
include (ROOT . "/trade_inc/data/db.inc");
include (ROOT . "/trade_inc/conf.inc");
include (ROOT . "/trade_inc/lib/myPDO.inc");
include (ROOT . "/trade_inc/data/configHandler.inc");
include (ROOT . "/trade_inc/data/contactHandler.inc");
include (ROOT . "/trade_inc/data/customerHandler.inc");
include (ROOT . "/trade_inc/data/companyNoticeHandler.inc");
include (ROOT . "/trade_inc/data/customerGroupHandler.inc");
include(ROOT . "/trade_inc/data/dataBean/supplierBean.inc");
include(ROOT . "/trade_inc/data/supplierHandler.inc");
include(ROOT . "/trade_inc/data/remindsHandler.inc");
include(ROOT . "/trade_inc/data/productHandler.inc");
include(ROOT . "/trade_inc/data/sampleHandler.inc");
include(ROOT . "/trade_inc/data/dataBean/productBean.inc");
include(ROOT . "/trade_inc/data/dataBean/productPriceBean.inc");
include(ROOT . "/trade_inc/data/dataBean/sampleBean.inc");


$who = Tools::getValue('subwho', '');
if (!empty($who)) {
    switch ($who) {
        case 'addcustomer':
            $customerid = Tools::getValue('customerid', '');
            $contactid = Tools::getValue('contactid', '');
            if (empty($customerid)) {
                echo whoSubFormSelect::insertCustomer($who);
            } else {
                echo whoSubFormSelect::editorCustomer($customerid, $contactid);
            }
            break;
        case 'addcustomergroup':
            $groupid = Tools::getValue('groupid', '');
            echo whoSubFormSelect::editorCustomerGroup($groupid);
            break;
        case 'addnotice':
            echo whoSubFormSelect::addNoticeContent();
            break;
        case 'addsupplier':
            echo whoSubFormSelect::addSupplier();
            break;
        case 'sharecustomer':
            echo whoSubFormSelect::shareCustomer();
            break;
        case 'sharecustomerGroup':
            echo whoSubFormSelect::shareCustomerGroup();
            break;
        case 'addRemind':
            echo whoSubFormSelect::addRemind();
            break;
        case 'updateRemind':
            echo whoSubFormSelect::updateRemind();
            break;
        case 'addproduct':
            echo whoSubFormSelect::addProduct();
            break;
        case 'updateproduct':
            echo whoSubFormSelect::updateProduct();
            break;
        case 'addsample':
            echo whoSubFormSelect::addSample();
            break;
        case 'updatesample':
            echo whoSubFormSelect::updateSample();
            break;
        case 'shareSample':
            echo whoSubFormSelect::shareSample();
            break;
    }
} else {
    echo 'nodoit';
}
?>
