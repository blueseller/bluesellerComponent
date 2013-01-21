<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of userPermissionHandler
 *
 * @author liukai
 */
class userPermissionHandler {

    public static function getCustomerPermissionByUserId($userId) {
        $sql = 'select customer_permission from user_permission where user_id=:user_id and is_delete=0';
        $params[':user_id'] = $userId;
        $result = DB::tradeDB()->rowPrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data['customer_permission'];
        }
        return array();
    }

    public static function getSuppliersPermissionByUserId($userId) {
        $sql = 'select supplier_permission from user_permission where user_id=:user_id and is_delete=0';
        $params[':user_id'] = $userId;
        $result = DB::tradeDB()->rowPrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data['supplier_permission'];
        }
        return array();
    }

}

?>
