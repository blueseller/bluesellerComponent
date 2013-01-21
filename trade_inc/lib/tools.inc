<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of tools
 *
 * @author liukai
 */
class Tools {

    public static function alert($value, $JSCode = "") {
        if (!headers_sent())
            header('Content-Type: text/html; charset=gb2312');
        $Js = "<script language=javascript encode='gbk'>";
        $value = $value;
        if (!empty($value))
            $Js.="alert('" . $value . "');\r\n";
        $Js.=$JSCode . "\r\n";
        $Js.="</script>";
        return $Js;
    }

    static public function redirectLogin($url) {
        $js = "<script>top.location.href='" . $url . "'</script>";
        echo $js;
    }
    
    static public function getValue($key, $defaultValue = false) {
        if (!isset($key) OR empty($key) OR !is_string($key))
            return false;
        $ret = (isset($_POST[$key]) ? $_POST[$key] : (isset($_GET[$key]) ? $_GET[$key] : $defaultValue));
        if (is_string($ret) === true)
            $ret = urldecode(preg_replace('/((\%5C0+)|(\%00+))/i', '', urlencode($ret)));
        return!is_string($ret) ? $ret : stripslashes($ret);
    }

}

?>
