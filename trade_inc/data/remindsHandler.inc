<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of tradeHandler
 *
 * @author liukai
 */
class remindsHandler {

    public static function insertRemind($remindArr) {
        $valfields = $params = array();
        foreach ($remindArr as $key => $val) {
            $valfields[] = ":$key";
            $params[":$key"] = $val;
        }
        $sql = 'insert into reminds (' . implode(',', array_keys($remindArr)) . ')values(' . implode(',', $valfields) . ')';
        $result = DB::tradeDB()->insertPrepare($sql, $params);
        if ($result->data > 0) {
            return $result->data;
        }
        return 0;
    }

    public static function getRemindById($remindId) {
        $sql = 'select * from reminds where is_delete=0 and remind_id=:id';
        $params[':id'] = $remindId;
        $result = DB::tradeDB()->rowPrepare($sql, $params);
        if ($result->data > 0) {
            return $result->data;
        }
        return 0;
    }

    public static function updateRemindByid($remindArr, $remindid) {
        $temp = '';
        $i = 0;
        foreach ($remindArr as $key => $value) {
            $i++;
            if ($i != 1) {
                $temp .=',';
            }
            $temp .=$key . "='" . $value . "'";
        }
        $sql = 'update reminds set ' . $temp . ' where remind_id=:id';
        $params[':id'] = $remindid;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function deleteRemindById($id) {
        $sql = 'update reminds set is_delete=1 where remind_id=:id';
        $params[':id'] = $id;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    

}

?>
