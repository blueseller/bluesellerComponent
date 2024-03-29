<?php

/**
 * class myAccessPdo
 *
 * Description for class myAccessPdo
 *
 * @author:blueseller
 */
class myPDO extends PDO {

    private $enableError = true;
    public $result; //last query result
    public $lastQuery;
    private $loger;

    public function __destruct() {
        if ($this->loger)
            $this->loger->logfile_close();
    }

    public function __construct($host, $dbname, $user, $pass, $dbType = 'mysql') {
        try {
            if ($dbType == 'oci') {
                $oracle_home_path = "/usr/lib/oracle/11.1/client64/lib";
                if (is_dir($oracle_home_path))
                    putenv("ORACLE_HOME=" . $oracle_home_path);
                parent::__construct("$dbType:dbname=//$host/$dbname;charset=ZHS16GBK", $user, $pass);
                $this->setAttribute(PDO::ATTR_CASE, PDO::CASE_LOWER);
            }elseif ($dbType == 'dblib') {
                parent::__construct("$dbType:host=$host;dbname=$dbname;charset=GBK", $user, $pass);
            } else {
                $charset = array(PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES 'utf8';");
                parent::__construct("$dbType:host=$host;dbname=$dbname", $user, $pass, $charset);
            }
            if ($this->enableError) {
                $this->loger = new pdoLoger();
                $this->loger->logfile_init();
                $this->displayError();
            }
        } catch (PDOException $e) {
            $loger = new pdoLoger();
            $loger->logfile_init();
            $loger->logErr(__FUNCTION__ . " Error!: " . $e->getMessage() . "\n", $e);
            $loger->logfile_close();
        }
    }

    private function bindParams($sth, $bindArrParams) {
        if (count($bindArrParams) > 0) {
            $key = array_keys($bindArrParams);
            if (!is_numeric($key[0]) && (substr($key[0], 0, 1) == ':')) {
                foreach ($bindArrParams as $keyParams => $valueParams) {
                    $sth->bindValue($keyParams, $valueParams,PDO::PARAM_STR);
                }
                $this->result = $sth->execute();
            } else {

                $this->result = $sth->execute($bindArrParams);
            }
        } else {
            $this->result = $sth->execute();
        }
        return $sth;
    }

    public function simplePrepare($query, $bindArrParams = array()) {
        try {
            $this->lastQuery = $query;
            $sth = parent::prepare($query);
            $sth = $this->bindParams($sth, $bindArrParams);
            $sth->closeCursor();
            return resultData::set($this->result, $this->lastQuery, $bindArrParams);
        } catch (PDOException $e) {
            $this->logErr(__FUNCTION__ . " Error!: " . $e->getMessage() . "\n", $e);
            $result = new resultData(array(), $query, $bindArrParams);
            $result->set_error($e);
            return $result;
        }
    }

    public function changePrepare($query, $bindArrParams = array()) {
        try {
            $this->lastQuery = $query;
            $sth = parent::prepare($query);
            $sth = $this->bindParams($sth, $bindArrParams);
            $rowCount = $sth->rowCount();
            $sth->closeCursor(); 
            return resultData::set($rowCount, $this->lastQuery, $bindArrParams);
        } catch (PDOException $e) {
            $this->logErr(__FUNCTION__ . " Error!: " . $e->getMessage() . "\n", $e);
            $result = new resultData(-1, $query, $bindArrParams);
            $result->set_error($e);
            return $result;
        }
    }

    //  $myDb->prepare('SELECT * from programmattori WHERE nome = ?',array('giggighe'));
    //  $myDb->prepare('SELECT * from programmattori WHERE nome = :cccc',array(':cccc'=>'giggighe'));

    public function insertPrepare($query, $bindArrParams = array()) {
        try {
            $this->lastQuery = $query;
            $sth = parent::prepare($query);
            $sth = $this->bindParams($sth, $bindArrParams);
            $sth->closeCursor();
            return resultData::set($this->lastInsertId(), $this->lastQuery, $bindArrParams);
        } catch (PDOException $e) {
            $this->logErr(__FUNCTION__ . " Error!: " . $e->getMessage() . "\n", $e);
            $result = new resultData(-1, $query, $bindArrParams);
            $result->set_error($e);
            return $result;
        }
    }

    public function allPrepare($query, $bindArrParams = array()) {
        try {
            $this->lastQuery = $query;
            $sth = parent::prepare($query);
            $sth = $this->bindParams($sth, $bindArrParams);
            $this->result = $sth->fetchAll(PDO::FETCH_ASSOC);
            $sth->closeCursor();
            return resultData::set($this->result, $this->lastQuery, $bindArrParams);
        } catch (PDOException $e) {
            $this->logErr(__FUNCTION__ . " Error!: " . $e->getMessage() . "\n", $e);
            $result = new resultData(array(), $query, $bindArrParams);
            $result->set_error($e);
            return $result;
        }
    }

    public function rowPrepare($query, $bindArrParams = array()) {
        try {
            $this->lastQuery = $query;
            $sth = parent::prepare($query);
            $sth = $this->bindParams($sth, $bindArrParams);
            $this->result = $sth->fetch(PDO::FETCH_ASSOC);
            $sth->closeCursor();
            return resultData::set($this->result, $this->lastQuery, $bindArrParams);
        } catch (PDOException $e) {
            $this->logErr(__FUNCTION__ . " Error!: " . $e->getMessage() . "\n", $e);
            $result = new resultData(array(), $query, $bindArrParams);
            $result->set_error($e);
            return $result;
        }
    }

    public function simpleQuery($query) {
        try {
            $this->lastQuery = $query;
            $count = parent::exec($query);
            return $count;
        } catch (PDOException $e) {
            $this->logErr(__FUNCTION__ . " Error!: " . $e->getMessage() . "\n", $e);
        }
    }

    public function lastInsertId($name = '') {
        try {
            $id = 0;
            if (parent::getAttribute(PDO::ATTR_DRIVER_NAME) == 'dblib') {
                $sth = parent::prepare("SELECT @@IDENTITY AS ID");
                $sth->execute();
                $result = $sth->fetch(PDO::FETCH_ASSOC);
                $sth->closeCursor();
                return $result;
            }


            $id = parent::lastInsertId($name);
            return $id;
        } catch (PDOException $e) {
            $this->logErr(__FUNCTION__ . " Error!: " . $e->getMessage() . "\n", $e);
        }
    }

    public function closeConnection() {
        try {
            $this->dbh = null;
        } catch (PDOException $e) {
            $this->logErr(__FUNCTION__ . " Error!: " . $e->getMessage() . "\n", $e);
        }
    }

    public function allPrepareLimit($query, $bindArrParams = array(), $limitArrParams = array()) {
        try {
            $this->lastQuery = $query;
            $sth = parent::prepare($query);
            $sth = $this->bindLimitParams($sth, $limitArrParams);
            $sth = $this->bindParams($sth, $bindArrParams);
            $this->result = $sth->fetchAll(PDO::FETCH_ASSOC);
            $sth->closeCursor();
            return resultData::set($this->result, $this->lastQuery, $bindArrParams);
        } catch (PDOException $e) {
            $this->logErr(__FUNCTION__ . " Error!: " . $e->getMessage() . "\n", $e);
            $result = new resultData(array(), $query, $bindArrParams);
            $result->set_error($e);
            return $result;
        }
    }

    public function displayError() {
        try {
            parent::setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        } catch (PDOException $e) {
            $this->logErr(__FUNCTION__ . " Error!: " . $e->getMessage() . "\n", $e);
        }
    }

    public function getErrorCode() {
        return parent::errorCode();
    }

    public function getErrorInfo() {
        return parent::errorInfo();
    }

    public function logErr($str, $e) {
        $this->loger->logErr($str, $e);
    }

    public function bindLimitParams($sth, $limitArrParams) {
        if (count($limitArrParams) > 0) {
            $key = array_keys($limitArrParams);
            if (!is_numeric($key[0]) && (substr($key[0], 0, 1) == ':')) {
                foreach ($limitArrParams as $keyParams => $valueParams) {
                    $sth->bindValue($keyParams, $valueParams, PDO::PARAM_INT);
                }
            }
        }
        return $sth;
    }

}

class pdoLoger {

    private $LOGFILE = "";
    var $FILE_HANDLER;

    static function forceDirectory($dir) { // force directory structure
        return is_dir($dir) or (pdoLoger::forceDirectory(dirname($dir)) and mkdir($dir, 0777));
    }

    function logfile_init() {
        if (empty($this->LOGFILE)) {
            $filename = Conf::$log_path . 'pdo' . date('Ymd') . '.log';
            $this->LOGFILE = $filename;
        } else {
            $filename = $this->LOGFILE;
        }
        pdoLoger::forceDirectory(Conf::$log_path);
        $this->FILE_HANDLER = fopen($filename, 'a');
    }

    public function logErr($str, $e) {
        $file_size = filesize($this->LOGFILE);
        if ($file_size > 1000000000)
            return;
        $err = "\n" . date(("Ymd H:i:s")) . "-->" . $str . ":::" . print_r($e, true) . "<--";
        substr($err, 0, 15000);
        if ($this->FILE_HANDLER) {
            fwrite($this->FILE_HANDLER, $err);
        }
    }

    public function logfile_close() {
        if ($this->FILE_HANDLER) {
            fclose($this->FILE_HANDLER);
        }
    }

}

class resultData {

    private $query = null;
    private $par = null;
    private $data = array();
    private $error = null;

    public function __construct($data, $query, $par) {
        $this->data = $data;
        $this->query = $query;
        $this->par = $par;
    }

    function __get($data) {
        return $this->$data;
    }

    public function get() {
        return $this->data;
    }

    public function debug() {
        echo "<pre>";
        print_r($this);
        echo "</pre>";
    }

    public function getQuery() {
        return $this->query;
    }

    public function count() {
        if (is_int($this->data))
            return $this->data;
        return count($this->data);
    }

    public function isEmpty() {
        return empty($this->data);
    }

    public function row($index = 0) {
        return $this->data[$index];
    }

    public static function set($data, $query, $par) {
        return new resultData($data, $query, $par);
    }

    public function set_error($e) {
        $this->error = $e;
    }

    public function resultId() {
        if (!is_array($this->data))
            return $this->data;
    }

}

class Info implements ArrayAccess {

    function offsetSet($key, $value) {
        if (array_key_exists($key, get_object_vars($this))) {
            $this->{$key} = $value;
        }
    }

    function offsetGet($key) {
        if (array_key_exists($key, get_object_vars($this))) {
            return $this->{$key};
        }
    }

    function offsetUnset($key) {
        if (array_key_exists($key, get_object_vars($this))) {
            unset($this->{$key});
        }
    }

    function offsetExists($offset) {
        return array_key_exists($offset, get_object_vars($this));
    }

}

?>