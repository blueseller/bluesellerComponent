<?php
/**
 * class Cookie
 *
 * Description for Cookie
 *
 * @author:blueseller
 */
class Cookie {

   static function MakeMD5($strArray) {
        $sb = md5($strArray);
        $sb = pack('H*',$sb);
        return $sb;
    }

   static function encryptNET3DES($key,$iv,$text) {
        if(empty($text)) return "";
        $td = mcrypt_module_open(MCRYPT_3DES, '', MCRYPT_MODE_ECB, '');
        // Complete the key
        $key_add = 24-strlen($key);
        $key .= substr($key,0,$key_add);
        // Padding the text
        $block = mcrypt_get_block_size('tripledes', 'ecb');
        $len = strlen($text);
        $padding = $block - ($len % $block);
        $text .= str_repeat(chr($padding),$padding);

        mcrypt_generic_init ($td, $key, $iv);
        $encrypt_text = mcrypt_generic ($td, $text);
        mcrypt_generic_deinit($td);
        mcrypt_module_close($td);
        return $encrypt_text;
    }


  static  function decryptNET3DES($key,$iv,$text) {
        if(empty($text)) return "";
        $td = mcrypt_module_open(MCRYPT_3DES, '', MCRYPT_MODE_ECB, '');

        $key_add = 24-strlen($key);
        $key .= substr($key,0,$key_add);

        mcrypt_generic_init($td, $key, $iv);
        $decrypt_text = mdecrypt_generic($td, $text);
        mcrypt_generic_deinit($td);
        mcrypt_module_close($td);

        $block = mcrypt_get_block_size('tripledes', 'ecb');
        $packing = ord($decrypt_text{strlen($decrypt_text)-1});
        if($packing and ($packing < $block)) {
            for($P=strlen($decrypt_text)-1; $P>=strlen($decrypt_text)-$packing; $P--) {
                if(ord($decrypt_text{$P}) != $packing) {
                    $packing = 0;
                }
            }
        }
        $decrypt_text = substr($decrypt_text,0,strlen($decrypt_text) - $packing);
        return $decrypt_text;
    }

   static function is_pass_emailcheck() {
        if(!isset($_COOKIE["validatedflag"])) return true;
        $flag = trim($_COOKIE["validatedflag"]);
        if($flag == "1" || $flag == "2" ||$flag == "3" ) {        return false;    }
        return true;
    }

  static  function get_login_user() {
        $email = "";
        $customer_id="";
        $authKey = "";
        $nick_name="";
        $customerid = "";
        $display_id ="";

        if(!isset($_COOKIE["dangdang_com"])) return false;
        $cookie_dangdang_com = $_COOKIE["dangdang_com"];
        if(empty($cookie_dangdang_com)) {
            return false;
        }

        if(!isset($_COOKIE["login_dangdang_com"])) return false;
        $cookie_login_dangdang_com = $_COOKIE["login_dangdang_com"];
        if(empty($cookie_login_dangdang_com)) {
            return false;
        }
        $cookie_dangdang_com_array = explode("&", $cookie_dangdang_com);

        foreach($cookie_dangdang_com_array as $cookie_str) {
            $key = "email=";
            $len = strlen($key);
            if($key==substr($cookie_str,0,$len)) {
                $email = base64_decode(str_replace(" ","+",substr($cookie_str,$len)));
            }
            $key = "customerid=";
            $len = strlen($key);
            if($key==substr($cookie_str,0,$len)) {
                $customerid = str_replace(" ","+",substr($cookie_str,$len));
            }
            $key = "nickname=";
            $len = strlen($key);
            if($key==substr($cookie_str,0,$len)) {
                $nick_name = base64_decode(str_replace(" ","+",substr($cookie_str,$len)));
            }

            $key = "display_id=";
            $len = strlen($key);
            if($key==substr($cookie_str,0,$len)) {
                $display_id = str_replace(" ","+",substr($cookie_str,$len));
            }


        }
        $cookie_login_dangdang_com_array = explode("&", $cookie_login_dangdang_com);
        foreach($cookie_login_dangdang_com_array as $cookie_str) {
            $key = ".ASPXAUTH=";
            $len = strlen($key);
            if($key==substr($cookie_str,0,$len)) {
                $authKey = str_replace(" ","+",substr($cookie_str,$len));
            }
        }

        if(empty($email) or empty($customerid) or empty($authKey)) {
            return false;
        }

        $strArray = COOKIE_CRYPTO_KEY.$email;
        $iv = mcrypt_create_iv(mcrypt_get_iv_size(MCRYPT_3DES,MCRYPT_MODE_ECB),MCRYPT_RAND);

        $key_string = self::MakeMD5(base64_encode(self::MakeMD5($strArray)));
        $encry_string = base64_decode($customerid);
        $customer_id = self::decryptNET3DES($key_string,$iv,$encry_string);

        $strArray = COOKIE_CRYPTO_KEY.$customer_id;
        $key_string = self::MakeMD5(base64_encode(self::MakeMD5($strArray)));
        $encry_string = base64_decode($authKey);
        $e_mail = self::decryptNET3DES($key_string,$iv,$encry_string);
        if($e_mail==$email) {
            return array("email"=>$email,"custid"=>$customer_id,"nickname"=>$nick_name,"display_id"=>$display_id);
        }
        return false;
    }

  static  function checkLogin() {
    $userinfo = self::get_login_user();
    if($userinfo === false) {
        $url = "https://login.dangdang.com/Signin.aspx?ReturnUrl=";
        $url.= Tools::getCurrentPageUrl();
        Tools::redirectLink($url);
    }
    return $userinfo;
}


}

?>
