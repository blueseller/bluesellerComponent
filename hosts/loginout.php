<?php
if (!defined("ROOT"))
    define("ROOT", dirname(__FILE__));
include(ROOT . "/../trade_inc/conf.inc");
$cookieSet = Conf::$cookieSet;
$secure = $_SERVER['SERVER_PORT'] == 443 ? 1 : 0;
setcookie("Tuser", "", time() - 3600, $cookieSet["path"], $cookieSet["domain"], $secure);
setcookie("Tnickname", "", time() - 3600, $cookieSet["path"], $cookieSet["domain"], $secure);
$url = HOME_PAGE . 'index.php';
header('Location: ' . $url);
?>