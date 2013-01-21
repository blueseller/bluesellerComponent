<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

class companyStaticMonthHandler {

    public static function getStaricConfigByName($static_name) {
        $sql = 'select '.$static_name." as staticnum,DATE_FORMAT(static_date,'%m') as month,DATE_FORMAT(static_date,'%Y') as year from company_static_month where static_date<:curdate order by static_date desc limit 0,12";
        $params[':curdate'] = date('Y-m-d');
        $result = DB::tradeDB()->allPrepare($sql, $params);
        if (!$result->isEmpty()) {
            return array_reverse($result->data);
        }
        return array();
    }


}
?>
