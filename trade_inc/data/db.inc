<?php

class DB {

    public static function tradeDB() {
        return self::getDbInstrance(Conf::$tradeDataBase);
    }

    public static function getDbInstrance($data) {
        static $instance;
        $key = $data["server"] . "_" . $data["database"] . "_" . $data["username"];
        if (!isset($instance[$key]) || !is_object($instance[$key])) {
            $instance[$key] = new myPDO($data["server"], $data["database"], $data["username"], $data["password"], $data['dbtype']);
        }
        return !empty($instance[$key]) ? $instance[$key] : new nullPDO();
    }

}

?>
