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
include (ROOT . "/../trade_inc/data/customerGroupHandler.inc");
include (ROOT . "/../trade_inc/data/remindsHandler.inc");
include (ROOT . "/../trade_inc/facade/customer/requestCustomer.inc");
cookieManager::checkLogin();
$customerid = Tools::getValue('customerid', '');
$contactid = Tools::getValue('contactid', '');
$who = Tools::getValue('who', '');
$id = Tools::getValue('id', '');
if (!empty($who)) {

    switch ($who) {
        case "updateMainContact":
            updateCustomerMainContacter($customerid, $contactid);
            exit;
        case "updateContact":
            updateContacterById($contactid);
            exit;
        case "deleteContact":
            deleteContacterById($contactid);
            exit;
        case 'deleteGroupContact':
            deleteGroupContacterById($id);
            exit;
        case 'deleteRemind':
            deleteRemind($id);
        default:
            break;
    }
}

function updateCustomerMainContacter($id, $contid) {
    $return = contactHandler::updateMainContacterById($id, $contid);
    if ($return > 0) {
        echo 'success';
    } else {
        echo 'false';
    }
}

function updateContacterById($contactid) {
    $contactBean = array();
    $contactBean['contact_name'] = Tools::getValue('contact0', '');
    $contactBean['contact_fax'] = Tools::getValue('contact1', '');
    $contactBean['contact_tel'] = Tools::getValue('contact2', '');
    $contactBean['contact_phone'] = Tools::getValue('contact3', '');
    $contactBean['contact_msn'] = Tools::getValue('contact4', '');
    $contactBean['contact_email'] = Tools::getValue('contact5', '');
    $contactBean['contact_skype'] = Tools::getValue('contact6', '');
    $contactBean['contact_other'] = Tools::getValue('contact7', '');
    $return = contactHandler::updateContacterContentById($contactid, $contactBean);
    if ($return > 0) {
        echo 'success';
    } else {
        echo 'false';
    }
}

function deleteContacterById($contactid) {
    $return = contactHandler::deleteContacterContentById($contactid);
    if ($return > 0) {
        echo 'success';
    } else {
        echo 'false';
    }
}

function deleteGroupContacterById($id) {
    $return = customerGroupHandler::deleteGroupContacterById($id);
    if ($return > 0) {
        echo 'success';
    } else {
        echo 'false';
    }
}

function deleteRemind($id){
    $return = remindsHandler::deleteRemindById($id);
    if ($return > 0) {
        $return = customerHandler::updateCustomerRemindById($id);
        if ($return > 0) {
            echo 'success';
        }else{
            echo 'false';
        }
    } else {
        echo 'false';
    }
}

?>
