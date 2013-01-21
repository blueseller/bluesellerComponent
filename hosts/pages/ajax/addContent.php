<?php

if (!defined("ROOT"))
    define("ROOT", dirname(__FILE__) . "/../../");
include(ROOT . "/../trade_inc/conf.inc");
include(ROOT . "/../trade_inc/lib/tools.inc");
include(ROOT . "/../trade_inc/lib/cookie.inc");
include(ROOT . "/../trade_inc/lib/myPDO.inc");
include(ROOT . "/../trade_inc/data/db.inc");
include(ROOT . "/../trade_inc/data/userHandler.inc");
include(ROOT . "/../trade_inc/data/permissionDataHandler.inc");
include(ROOT . "/../trade_inc/facade/cookieManager.inc");
include (ROOT . "/../trade_inc/data/contactHandler.inc");
include (ROOT . "/../trade_inc/data/userPermissionHandler.inc");
include (ROOT . "/../trade_inc/data/customerHandler.inc");
include (ROOT . "/../trade_inc/facade/customer/requestCustomer.inc");
cookieManager::checkLogin();
$customerid = Tools::getValue('customerid', '');

$who = Tools::getValue('who', '');

if (!empty($who)) {

    switch ($who) {
        case "addContactContent":
            addContactContent($customerid);
            exit;
        default:
            break;
    }
}


function addContactContent($customerid) {
    $contactBean = array();
    $contactBean['contact_name'] = Tools::getValue('contact0', '');
    $contactBean['contact_fax'] = Tools::getValue('contact1', '');
    $contactBean['contact_tel'] = Tools::getValue('contact2', '');
    $contactBean['contact_phone'] = Tools::getValue('contact3', '');
    $contactBean['contact_msn'] = Tools::getValue('contact4', '');
    $contactBean['contact_email'] = Tools::getValue('contact5', '');
    $contactBean['contact_skype'] = Tools::getValue('contact6', '');
    $contactBean['contact_other'] = Tools::getValue('contact7', '');
    $contactBean['contact_coustomer_id'] = $customerid;
    $contactBean['contact_flag'] = Tools::getValue('contactflag', '');
    $return = contactHandler::contactInsert($contactBean);
    if ($return > 0) {
        echo 'success';
    } else {
        echo 'false';
    }
}

?>
