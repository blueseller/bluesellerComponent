<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of companyNotice
 *
 * @author liukai
 */
class companyNoticeHandler {

    public static function insertNotice($contentArr) {
        $valfields = $params = array();
        foreach ($contentArr as $key => $val) {
            $valfields[] = ":$key";
            $params[":$key"] = $val;
        }
        $sql = 'insert into company_notice ('. implode(',', array_keys($contentArr)) .',creat_time)values(' . implode(',', $valfields) . ',now())';
        $result = DB::tradeDB()->allPrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getNoticesByCate($catename) {
        $params = array();
        $sql = 'select * from company_notice where customer_category=:catename and customer_category!="" and is_delete=0 order by creat_time desc limit 0,6';
        $params[":catename"]= $catename;
        $result = DB::tradeDB()->allPrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getNoticesBySelfId($userid) {
        $params = array();
        $sql = 'select * from company_notice where editor_people=:userid and customer_category!="" and customer_category!=:customer_category and is_delete=0 order by creat_time desc limit 0,6';
        $params[":userid"]= $userid;
        $params[":customer_category"]= "通知";
        $result = DB::tradeDB()->allPrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

}

?>
