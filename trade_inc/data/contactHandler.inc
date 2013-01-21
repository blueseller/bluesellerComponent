<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of contactHandler
 *
 * @author liukai
 */
class contactHandler {

    public static function contactInsert($content) {
        $valfields = $params = array();
        foreach ($content as $key => $val) {
            $valfields[] = ":$key";
            $params[":$key"] = $val;
        }
        $sql = 'insert into contact (' . implode(',', array_keys($content)) . ',contact_create_time,contact_lastcontacttime)values(' . implode(',', $valfields) . ',now(),now())';
        $result = DB::tradeDB()->insertPrepare($sql, $params);
        if ($result->data > 0) {
            return $result->data;
        }
        return 0;
    }

    public static function getContactByCustomerId($customerId, $firstContacter,$contact_flag) {
        $sql = 'select * from contact where is_delete=0 and contact_coustomer_id=:id and contact_id !=:mainContact and contact_flag=:contact_flag';
        $params[':id'] = $customerId;
        $params[':mainContact'] = $firstContacter;
        $params[':contact_flag'] = $contact_flag;
        $result = DB::tradeDB()->allPrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function updateMainContacterById($id, $contid) {
        $sql = 'update customer set customer_first_contacter=:contid where id=:id';
        $params[':id'] = $id;
        $params[':contid'] = $contid;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function updateContacterContentById($id, $contactBean) {
        $temp = '';
        $i = 0;
        foreach ($contactBean as $key => $value) {
            $i++;
            if ($i != 1) {
                $temp .=',';
            }
            $temp .=$key . "='" . $value . "'";
        }
        $sql = 'update contact set ' . $temp . ' where contact_id=:id';
        $params[':id'] = $id;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function deleteContacterContentById($contactid) {
        $sql = 'update contact set is_delete=1 where contact_id=:id';
        $params[':id'] = $contactid;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function updateCustomerUserId($customerid, $userid) {
        $sql = 'update customer set customer_whohave=:userid where id=:id';
        $params[':userid'] = $userid;
        $params[':id'] =$customerid;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function updateCustomerGroupId($customerid, $groupid) {
        $sql = 'update customer set customer_group=:group where id=:id';
        $params[':group'] = $groupid;
        $params[':id'] =$customerid;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

}

?>
