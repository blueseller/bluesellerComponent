<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of configHandler
 *
 * @author liukai
 */
class configHandler {

    public static function getConfigValueByKey($key) {
        $sql = 'SELECT id,config_value FROM config WHERE config_key=:config_key';
        $row = DB::tradeDB()->rowPrepare($sql, array(':config_key' => $key));
        if (!$row->isEmpty()) {
            return $row->data;
        }
        return array();
    }

}

?>
