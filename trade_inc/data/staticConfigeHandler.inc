<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


class staticConfigeHandler {

    public static function getStaricConfigByName($name) {
        $sql = 'select * from static_confige where static_confige_name=:static_confige_name';
        $params[':static_confige_name'] = $name;
        $result = DB::tradeDB()->rowPrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }


}
?>
