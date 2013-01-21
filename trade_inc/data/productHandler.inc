<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of productHandler
 *
 * @author liukai
 */
class productHandler {

    public static function getProductById($productId) {
        $sql = 'select prod.*,price.* from products as prod LEFT JOIN product_price as price on prod.product_price_id = price.price_id where prod.is_delete=0 and prod.id=:id';
        $params[':id'] = $productId;
        $result = DB::tradeDB()->rowPrepare($sql, $params);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getProducts( $start, $listnum = 14) {
        $sql = 'select prod.*,price.* from products as prod LEFT JOIN product_price as price on prod.product_price_id = price.price_id where prod.is_delete=0 limit '.$start.','.$listnum;
        $result = DB::tradeDB()->allPrepare($sql);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getProductsSunNum() {
        $sql = 'select count(*) as sum from products where is_delete=0';
        $result = DB::tradeDB()->rowPrepare($sql);
        if (!$result->isEmpty()) {
            return $result->data['sum'];
        }
        return array();
    }

    public static function insertProductPrice($productpriceArr) {
        $valfields = $params = array();
        foreach ($productpriceArr as $key => $val) {
            $valfields[] = ":$key";
            $params[":$key"] = $val;
        }
        $sql = 'insert into product_price (' . implode(',', array_keys($productpriceArr)) . ',is_delete)values(' . implode(',', $valfields) . ',0)';
        $result = DB::tradeDB()->insertPrepare($sql, $params);
        if ($result->data > 0) {
            return $result->data;
        }
        return 0;
    }

    public static function insertProductContent($productArr) {
        $valfields = $params = array();
        foreach ($productArr as $key => $val) {
            $valfields[] = ":$key";
            $params[":$key"] = $val;
        }
        $sql = 'insert into products (' . implode(',', array_keys($productArr)) . ',create_time)values(' . implode(',', $valfields) . ',now())';
        $result = DB::tradeDB()->insertPrepare($sql, $params);
        if ($result->data > 0) {
            return $result->data;
        }
        return 0;
    }

    public static function updateProductPrice($productpriceArr,$priceid) {
        $temp = '';
        $i = 0;
        foreach ($productpriceArr as $key => $value) {
            $i++;
            if ($i != 1) {
                $temp .=',';
            }
            $temp .=$key . "='" . $value . "'";
        }

        $sql = 'update product_price set ' . $temp . ' where price_id=:id';
        $params[':id'] = $priceid;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if ($result->data > 0) {
            return $result->data;
        }
        return 0;
    }

    public static function updateProductContent($productArr,$productid) {
        $temp = '';
        $i = 0;
        foreach ($productArr as $key => $value) {
            $i++;
            if ($i != 1) {
                $temp .=',';
            }
            $temp .=$key . "='" . $value . "'";
        }

        $sql = 'update products set ' . $temp . ' where id=:id';
        $params[':id'] = $productid;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if ($result->data > 0) {
            return $result->data;
        }
        return 0;
    }

    public static function getProductsByGroupId($groupid, $start, $listnum = 14) {
        $sql = 'select prod.*,price.* from products as prod LEFT JOIN product_price as price on prod.product_price_id = price.price_id where prod.is_delete=0 and product_group=:groupid limit '.$start.','.$listnum;
        $param = array();
        $param[':groupid'] = $groupid;
        $result = DB::tradeDB()->allPrepare($sql,$param);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getProductCountByOptions($groupid) {
        $sql = 'select count(*) as sum from products where is_delete=0 and product_group=:groupid';
        $param = array();
        $param[':groupid'] = $groupid;
        $result = DB::tradeDB()->rowPrepare($sql,$param);
        if (!$result->isEmpty()) {
            return $result->data['sum'];
        }
        return array();
    }
    
    
    
}

?>
