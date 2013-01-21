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
$id = Tools::getValue('customerid', '');
$who = Tools::getValue('who', '');
$datatablename = Tools::getValue('type', '');
if (!empty($who)) {

    switch ($who) {
        case "deleteCustomer":
            deleteCustomer($id,$datatablename);
            exit;    
        default:
            break;
    }
}

function deleteCustomer($id,$datatablename) {
    $return = customerHandler::deleteCustomerById($id,$datatablename);
    if ($return > 0) {
        echo 'success';
    } else {
        echo 'false';
    }
}

?>