<?php

/**
 * class conf
 *
 * ������
 * @author blueseller
 */
define('PAGE404', 'http://www.dangdang.com/404.php');
define('HOME_PAGE', 'http://skliukai.dangdang.com/');
define('COOKIE_CRYPTO_KEY', "cookie_crypto_trade_key_initial");
class Conf {
    public static $title = "外贸管理软件";
    public static $log_path = "/var/www/skliukaifront/log/";
    public static $numlist = 14;//右侧每页显示多少条信息
    public static $log = array("log_enabled" => true, "log_path" => "/var/www/skliukaifront/log/", "log_file" => "sk_log", "log_levels" => E_NOTICE, "log_file_maxsize" => 1024);
    public static $memCacheHost = array(array('127.0.0.1', 11211));
    public static $tradeDataBase = array("dbtype" => "mysql", "database" => "trade", "username" => "root", "password" => "root", "server" => "192.168.85.12");
    public static $cookieSet = array('domain' => 'skliukai.dangdang.com', 'path' => '/', 'lifetime' => 36000, 'numlifetime' => 3600);
    public static $urlSet = array('loginurl' => 'http://skliukai.dangdang.com/index.php', 'homepage' => 'http://skliukai.dangdang.com/');
    public static $months = array(
        '01'=>"一月",
        '02'=>"二月",
        '03'=>"三月",
        '04'=>"四月",
        '05'=>"五月",
        '06'=>"六月",
        '07'=>"七月",
        '08'=>"八月",
        '09'=>"九月",
        '10'=>"十月",
        '11'=>"十一月",
        '12'=>"十二月"
    );
    
}

?>