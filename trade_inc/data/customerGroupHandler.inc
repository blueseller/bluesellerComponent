<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of customerGroupHandler
 *
 * @author liukai
 */
class customerGroupHandler {

    public static function customerGroupInsert($content) {
        $valfields = $params = array();
        foreach ($content as $key => $val) {
            $valfields[] = ":$key";
            $params[":$key"] = $val;
        }
        $sql = 'insert into customer_group (' . implode(',', array_keys($content)) . ')values(' . implode(',', $valfields) . ')';
        $result = DB::tradeDB()->insertPrepare($sql, $params);
        if ($result->data > 0) {
            return $result->data;
        }
        return 0;
    }

    public static function customerGroupUpdate($groupid, $content) {
        $temp = '';
        $i = 0;
        foreach ($content as $key => $value) {
            $i++;
            if ($i != 1) {
                $temp .=',';
            }
            $temp .=$key . "='" . $value . "'";
        }
        $sql = 'update customer_group set ' . $temp . ' where id=:id';
        $params[':id'] = $groupid;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getGroupById($groupId) {
        $sql = 'select * from customer_group where is_delete=0 and id=:id';
        $params[':id'] = $groupId;
        $result = DB::tradeDB()->rowPrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getGroupNameById($groupId){
         $arr =self::getGroupById($groupId);
         if(isset($arr['customer_group_name'])){
             return $arr['customer_group_name'];
         }else{
             return "";
         }
         
    }

    public static function deleteGroupContacterById($id) {
        $sql = 'update customer_group set is_delete=1 where id=:id';
        $params[':id'] = $id;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getGroups($group_category) {
        $param = array();
        $sql = 'select * from customer_group where is_delete=0 and group_category=:group_category';
        $param[':group_category'] =$group_category;
        $result = DB::tradeDB()->allPrepare($sql,$param);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

}

?>
