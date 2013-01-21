<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of remindBean
 *
 * @author liukai
 */
class remindBean {

    public static function setRemindData($param) {
        $remindArray = array();
        $remindArray['remind_id'] = isset($param['remind_id']) ? $param['remind_id'] : '';
        $remindArray['remind_start_time'] = isset($param['remind_start_time']) ? $param['remind_start_time'] : '';
        $remindArray['remind_end_time'] = isset($param['remind_end_time']) ? $param['remind_end_time'] : '';
        $remindArray['remind_title'] = isset($param['remind_title']) ? $param['remind_title'] : '';
        $remindArray['remind_content'] = isset($param['remind_content']) ? $param['remind_content'] : '';
        return $remindArray;
    }

}

?>
