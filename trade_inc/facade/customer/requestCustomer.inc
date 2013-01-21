<?php

class requestCustomer {

    public static $customers = array();
    public static $allcount = '';

    public static function init() {
        $who = Tools::getValue('who', '');
        $page = Tools::getValue('page', '');
        $start = 0;
        $userId = $_COOKIE['userId'];
        if(!empty($page)){
            $start = $page * Conf::$numlist;
        }
        if ($who == 'customer') {
            $permission = userPermissionHandler::getCustomerPermissionByUserId($userId);
            self::$customers = customerHandler::getCustomersList($permission,$start,Conf::$numlist);
            self::$allcount = customerHandler::getCustomersCount($permission);
        }elseif ($who == 'suppliers') {
            $permission = userPermissionHandler::getSuppliersPermissionByUserId($userId);
            self::$customers = supplierHandler::getSuppliersList($permission,$start,Conf::$numlist);
            self::$allcount = supplierHandler::getSuppliersCount($permission);
        }
    }
    
    public static function getRemindHtml($id,$remind){
        $html = '';
        if($remind != 0){
            $html = '<a href="javascript:void(0)" onclick="remind('.$id.')"><img src="../../images/button/favorite_love.png" width="16px" height="16px"></a>';
        }
        return $html;
    }

    public static function getCustomerIsWhohave($userId){
        return userHandler::getUserNameById($userId);
    }
    
}

?>
