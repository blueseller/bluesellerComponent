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
class permissionDataHandler {

    public static function select_all_user_group_map($userid) {
        $sql = "SELECT user_id , group_id FROM user_group_map
				WHERE user_id=:user_id AND is_delete=0";
        $row = DB::tradeDB()->allPrepare($sql, array(':user_id' => $userid));
        return $row;
    }

    public static function getGroupById($group_id) {
        $sql = 'SELECT group_id,group_name,group_permission,is_delete FROM groups WHERE group_id=:group_id';
        $row = DB::tradeDB()->rowPrepare($sql, array(':group_id' => $group_id));
        return $row;
    }

}

?>
