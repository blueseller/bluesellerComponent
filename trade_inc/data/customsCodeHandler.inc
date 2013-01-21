<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of customsCodeHandler
 *
 * @author liukai
 */
class customsCodeHandler {
    
    public static function getCustomsCodeList($start, $listnum = 14) {
        $sql = 'select * from customs_code where is_delete = 0 limit :start,:listnum';
        $paramsLimit[':start'] = $start;
        $paramsLimit[':listnum'] = $listnum;
        $result = DB::tradeDB()->allPrepareLimit($sql, array(), $paramsLimit);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }
    
    public static function getCustomsCodeSumNum() {
        $sql = 'select count(*) as sum from customs_code where is_delete = 0';
        $result = DB::tradeDB()->rowPrepare($sql);
        if (!$result->isEmpty()) {
            return $result->data['sum'];
        }
        return array();
    }
    
}

?>
