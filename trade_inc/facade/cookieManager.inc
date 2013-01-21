<?php

class cookieManager {


	public static function setLoginCookie($userId,$user, $nickname, $depart,$lasttime) {
		$cookieSet = Conf::$cookieSet;
                $_COOKIE['userId'] = $userId;
		$_COOKIE['Tuser'] = $user;
		$_COOKIE['Tnickname'] = $nickname;
		$_COOKIE['Tdepart'] = $depart;
                $_COOKIE['Tlastlogintime'] = $lasttime;
		$_COOKIE['ltime'] = time() + $cookieSet["numlifetime"];
		$secure = $_SERVER['SERVER_PORT'] == 443 ? 1 : 0;
                setcookie("userId", $_COOKIE['userId'], 0, $cookieSet["path"], $cookieSet["domain"], $secure);
		setcookie("Tuser", $_COOKIE['Tuser'], 0, $cookieSet["path"], $cookieSet["domain"], $secure);
		setcookie("Tnickname", $_COOKIE['Tnickname'], 0, $cookieSet["path"], $cookieSet["domain"], $secure);
		setcookie("Tdepart", $_COOKIE['Tdepart'], 0, $cookieSet["path"], $cookieSet["domain"], $secure);
		setcookie("ltime", $_COOKIE['ltime'], 0, $cookieSet["path"], $cookieSet["domain"], $secure);
                setcookie("Tlastlogintime", $_COOKIE['Tlastlogintime'], 0, $cookieSet["path"], $cookieSet["domain"], $secure);
	}

	

	private static function clearCookie() {
		setcookie("axdata", "", time() - 3600, $cookieSet["path"], $cookieSet["domain"], $secure);
		setcookie("ltime", "", -1, $cookieSet["path"], $cookieSet["domain"], $secure);
	}


	public static function checkLogin() {
		$ui = array();
		$cookieSet = Conf::$cookieSet;
		$LOGIN_URL = Conf::$urlSet["loginurl"];

		if (!empty($_COOKIE['Tuser']) && !empty($_COOKIE['Tnickname'])) {
			$ui['username'] = $_COOKIE['Tuser'];
			$ui['nickname'] = $_COOKIE['Tnickname'];
                        $ui['depart'] = $_COOKIE['Tdepart'];
		} else {
			Tools::redirectLogin($LOGIN_URL);
			exit;
		}


		$secure = $_SERVER['SERVER_PORT'] == 443 ? 1 : 0;
		if (isset($_COOKIE['ltime'])) {
			if ($_COOKIE['ltime'] >= time()) {
				setcookie("ltime", time() + $cookieSet["numlifetime"], 0, $cookieSet["path"], $cookieSet["domain"], $secure);
			} else {
				self::clearCookie();
				Tools::redirectLogin($LOGIN_URL);
				exit;
			}
		} else {
			self::clearCookie();
			Tools::redirectLogin($LOGIN_URL);
			exit;
		}

		

		$row_user = userHandler::getUserByName($ui['username']);
		if (!$row_user->isEmpty()) {
			$ui['id'] = $row_user->data["id"];
			$row_user_groups = permissionDataHandler::select_all_user_group_map($ui['id']);
			if (!$row_user_groups->isEmpty()) {
				foreach($row_user_groups->data as $v) {
					$ui['group_ids'][] =  $v["group_id"];
				}
			}
		}
		

		$user_permission = self::getUserGroupsPermission($ui['group_ids']) ;
                
		$iv = mcrypt_create_iv(mcrypt_get_iv_size(MCRYPT_3DES, MCRYPT_MODE_ECB), MCRYPT_RAND);
                
		if (!empty($_COOKIE['permission']) and !empty($_COOKIE['axdata'])) {
			$key = Cookie::MakeMD5(base64_encode(Cookie::MakeMD5($ui['username'] . COOKIE_CRYPTO_KEY)));
			$axdata = base64_decode($_COOKIE['axdata']);
			$axdata = Cookie::decryptNET3DES($key, $iv, $axdata);
			if ($axdata == $ui['username'] . "_" . $user_permission) {
				$ui['permission'] = $_COOKIE['permission'];
				if (empty($user_permission)) {
					echo Tools::alert('��û�е�¼��̨��Ȩ�ޣ�', "top.location.href='" . $LOGIN_URL. "';");
					exit;
				}
			} else {
				$expire = time() - 3600;
				setcookie("Tuser", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
				setcookie("Tnickname", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
				setcookie("Tnickname", 0, $expire, $cookieSet["path"], '.dangdang.com', $secure);
				setcookie("ltime", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
				setcookie("axdata", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
				setcookie("permission", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
				echo Tools::alert('Ȩ���б�������µ�¼��', "top.location.href='" . $LOGIN_URL . "';");
				exit;
			}
		} else {
			if (empty($user_permission)) {
				echo Tools::alert('��û�е�¼��̨��Ȩ�ޣ�', "top.history.back(-1);");
				exit;
			}
			$_COOKIE['permission'] = $user_permission;
			$key = Cookie::MakeMD5(base64_encode(Cookie::MakeMD5($ui['username'] . COOKIE_CRYPTO_KEY)));
			$text = $ui['username'] . "_" . $_COOKIE['permission'];
			$axdata = base64_encode(Cookie::encryptNET3DES($key, $iv, $text));
			$_COOKIE['axdata'] = $axdata;

			setcookie("permission", $_COOKIE['permission'], 0, $cookieSet["path"], $cookieSet["domain"], $secure);
			setcookie("axdata", $_COOKIE['axdata'], 0, $cookieSet["path"], $cookieSet["domain"], $secure);

			$ui['permission'] = $_COOKIE['permission'];
		}
		return $ui;
	}
	
	public static function getUserGroupsPermission($user_groups) {
		$user_permission = '';
		if (!empty($user_groups)) {
			$permission_list = array();
			foreach ($user_groups as $group_id) {
				$group_permission = '';
				$row_group = permissionDataHandler::getGroupById($group_id);
				if (!$row_group->isEmpty()) {
					$group_permission = $row_group->data;
					if ($group_permission['is_delete'] == 0) {
						$user_permision_array = explode('_', $group_permission['group_permission']) ;
						if (!empty($user_permision_array)) {
							$permission_list = array_merge($permission_list ,$user_permision_array );
						}
					}
				}
			}
			
			$permission_list = array_unique($permission_list);
			sort($permission_list);
			if (!empty($permission_list)) {
				if (empty($permission_list[0])) {
					array_shift($permission_list);
				}
				$user_permission = '_'.implode('_',$permission_list).'_';
			}
		}
		return $user_permission;
	}

}

?>
