<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of supplierHandler
 *
 * @author liukai
 */
class supplierHandler {

    public static function getSuppliersCount($permission) {
        $sql = 'select count(id) as sum from supplier where is_delete=0 and supplier_permission in (' . $permission . ')';
        $result = DB::tradeDB()->rowPrepare($sql);
        if (!$result->isEmpty()) {
            return $result->data['sum'];
        }
        return array();
    }

    public static function getSuppliersList($permission, $start, $listnum=14) {
        $sql = 'select * from supplier where is_delete=0 and supplier_permission in (' . $permission . ') order by id desc limit :start,:listnum';
        $paramsLimit[':start'] = $start;
        $paramsLimit[':listnum'] = $listnum;
        $result = DB::tradeDB()->allPrepareLimit($sql, array(), $paramsLimit);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getSupplierById($permission,$supplierId) {
        $params = array();
        $sql = 'select * from supplier where is_delete=0 and supplier_permission in (' . $permission . ') and id=:supplierid';
        $params[':supplierid'] = $supplierId;
        $result = DB::tradeDB()->rowPrepare($sql,$params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function supplierInsert($supplier) {
        $valfields = $params = array();
        foreach ($supplier as $key => $val) {
            $valfields[] = ":$key";
            $params[":$key"] = $val;
        }
        $sql = 'insert into supplier (' . implode(',', array_keys($supplier)) . ',create_time)values(' . implode(',', $valfields) . ',now())';
        $result = DB::tradeDB()->insertPrepare($sql, $params);
        if ($result->data > 0) {
            return $result->data;
        }
        return 0;
    }

    public static function getSupplierByGroupId($permission, $option, $start, $listnum=14) {
        $sql = 'select * from supplier where is_delete=0 ' . $option . ' and supplier_permission in (' . $permission . ') order by id desc limit :start,:listnum';
        $paramsLimit[':start'] = $start;
        $paramsLimit[':listnum'] = $listnum;
        $result = DB::tradeDB()->allPrepareLimit($sql, array(), $paramsLimit);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getSupplierCountByOptions($permission,$option) {
        $sql = 'select count(*) as sum from supplier where is_delete=0 '. $option .' and supplier_permission in (' . $permission . ')';
        $result = DB::tradeDB()->rowPrepare($sql);
        if (!$result->isEmpty()) {
            return $result->data['sum'];
        }
        return array();
    }
    
}

?>
