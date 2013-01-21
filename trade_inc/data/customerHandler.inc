<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of customerHandler
 *
 * @author liukai
 */
class customerHandler {

    public static function customerInsert($content) {
        $valfields = $params = array();
        foreach ($content as $key => $val) {
            $valfields[] = ":$key";
            $params[":$key"] = $val;
        }
        $sql = 'insert into customer (' . implode(',', array_keys($content)) . ')values(' . implode(',', $valfields) . ')';
        $result = DB::tradeDB()->insertPrepare($sql, $params);
        if ($result->data > 0) {
            return $result->data;
        }
        return 0;
    }

    public static function getCustomersList($permission, $start, $listnum = 14) {
        $sql = 'select cust.*,cont.contact_email,cont.contact_name,cont.contact_tel,cont.contact_fax,cont.contact_lastcontacttime from customer as cust LEFT JOIN contact as cont on cust.customer_first_contacter = cont.contact_id where cust.is_delete=0 and cust.customer_whohave in (' . $permission . ') order by id desc limit :start,:listnum';
        $paramsLimit[':start'] = $start;
        $paramsLimit[':listnum'] = $listnum;
        $result = DB::tradeDB()->allPrepareLimit($sql, array(), $paramsLimit);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getCustomerById($customerId) {
        $sql = 'select cust.*,cont.* from customer as cust LEFT JOIN contact as cont on cust.customer_first_contacter = cont.contact_id where cust.is_delete=0 and cust.id=:id';
        $params[':id'] = $customerId;
        $result = DB::tradeDB()->rowPrepare($sql, $params);
        if (!$result->isEmpty()) {
            return array_reverse($result->data);
        }
        return array();
    }

    public static function deleteCustomerById($customerId,$datatablename) {
        $sql = 'update '.$datatablename.' set is_delete=1 where id=:id';
        $params[':id'] = $customerId;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function customerUpdate($customerId, $customerbean) {
        $temp = '';
        $i = 0;
        foreach ($customerbean as $key => $value) {
            $i++;
            if ($i != 1) {
                $temp .=',';
            }
            $temp .=$key . "='" . $value . "'";
        }

        $sql = 'update customer set ' . $temp . ' where id=:id';
        $params[':id'] = $customerId;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getCustomerByGroupId($permission, $option, $start, $listnum) {
        $sql = 'select cust.*,cont.contact_email,cont.contact_name,cont.contact_tel,cont.contact_fax,cont.contact_lastcontacttime from customer as cust LEFT JOIN contact as cont on cust.customer_first_contacter = cont.contact_id where cust.is_delete=0 ' . $option . ' and cust.customer_whohave in (' . $permission . ') order by id desc limit :start,:listnum';
        $paramsLimit[':start'] = $start;
        $paramsLimit[':listnum'] = $listnum;
        $result = DB::tradeDB()->allPrepareLimit($sql, array(), $paramsLimit);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getCustomersCount($permission) {
        $sql = 'select count(id) as sum from customer where is_delete=0 and customer_whohave in (' . $permission . ')';
        $result = DB::tradeDB()->rowPrepare($sql);
        if (!$result->isEmpty()) {
            return $result->data['sum'];
        }
        return array();
    }

    public static function getCustomersCountByOptions($permission, $option) {
        $sql = 'select count(*) as sum from customer where is_delete=0 '. $option .' and customer_whohave in (' . $permission . ')';
        $result = DB::tradeDB()->rowPrepare($sql);
        if (!$result->isEmpty()) {
            return $result->data['sum'];
        }
        return array();
    }

    public static function getCustomerIsHaveWho($customer) {
        $sql = 'select customer_whohave from customer where is_delete=0 and id=:id';
        $params = array();
        $params[":id"] =$customer;
        $result = DB::tradeDB()->rowPrepare($sql,$params);
        if (!$result->isEmpty()) {
            return $result->data['customer_whohave'];
        }
        return array();
    }

    public static function getCustomerOnlyById($customerId) {
        $sql = 'select * from customer where is_delete=0 and id=:id';
        $params = array();
        $params[":id"] =$customerId;
        $result = DB::tradeDB()->rowPrepare($sql,$params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function updateRemindIdByCustomerId($remindid, $customerid) {
        $sql = 'update customer set customer_remind_id=:remindid  where id=:id';
        $params[':id'] = $customerid;
        $params[':remindid'] = $remindid;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function updateCustomerRemindById($id) {
        $sql = 'update customer set customer_remind_id=0 where id=:id';
        $params[':id'] = $id;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getCustomersListBypermission($permission) {
        $sql = 'select id,customer_name from customer where is_delete=0 and customer_whohave in (' . $permission . ')';
        $result = DB::tradeDB()->allPrepare($sql);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

}

?>
