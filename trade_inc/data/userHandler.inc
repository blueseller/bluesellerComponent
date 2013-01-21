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
class userHandler {

    public static function getUserLoginMsg($username, $passwd) {
        $sql = 'select * from user where user_name=:username and user_password=:password and is_delete=0';
        $params[':username'] = $username;
        $params[':password'] = $passwd;
        $result = DB::tradeDB()->rowPrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getUserByName($name) {
        $sql = 'select * from user where user_name=:username and is_delete=0';
        $params[':username'] = $name;
        $result = DB::tradeDB()->rowPrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result;
        }
        return array();
    }

    public static function getUserNameById($userId) {
        $sql = 'select user_nickname from user where id=:id and is_delete=0';
        $params[':id'] = $userId;
        $result = DB::tradeDB()->rowPrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data['user_nickname'];
        }
        return array();
    }

    public static function getUserNameByIds($userIds) {
        $sql = 'select * from user where id in (' . $userIds . ') and is_delete=0';
        $result = DB::tradeDB()->allPrepare($sql);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function updateLoginTime($id) {
        $sql = 'update user set last_modified_date=now() where id=:id';
        $params[':id'] = $id;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getAllUsers() {
        $sql = 'select * from user where is_delete=0';
        $result = DB::tradeDB()->allPrepare($sql);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

}

?>
