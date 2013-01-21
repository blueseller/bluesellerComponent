<?php
if (!defined("ROOT"))
    define("ROOT", dirname(__FILE__));
include(ROOT . "/../trade_inc/conf.inc");
include(ROOT . "/../trade_inc/lib/tools.inc");
include(ROOT . "/../trade_inc/lib/myPDO.inc");
include(ROOT . "/../trade_inc/data/db.inc");
include(ROOT . "/../trade_inc/data/userHandler.inc");
include(ROOT . "/../trade_inc/facade/cookieManager.inc");

$username = isset($_POST['username']) ? $_POST['username'] : '';
$password = isset($_POST['password']) ? $_POST['password'] : '';
if ($username != '' && $password != '') {
    $return = userHandler::getUserLoginMsg($username, md5($password));
    if (!empty($return)&&$username == $return['user_name'] && md5($password) == $return['user_password']) {
        cookieManager::setLoginCookie($return['id'],$return['user_name'], $return['user_nickname'], $return['user_depart'],$return['last_modified_date']);
        userHandler::updateLoginTime($return['id']);
        $url = HOME_PAGE . 'main.php';
        header('Location: ' . $url);
    } else {
        echo Tools::alert("用户名和密码错误");
        Tools::redirectLogin(Conf::$urlSet["loginurl"]);
    }
}
?>
<!DOCTYPE HTML>
<html>
    <head>
        <meta charset="UTF-8">
        <title>外贸管理软件</title>
        <script type="text/javascript" src="js/jquery.js"></script>
        <script type="text/javascript" src="js/login.js"></script>
        <link rel="stylesheet" href="css/login.css" type="text/css" media="all" />
    </head>
    <body class="sso">
        <div class="login_wrap">
            <div class="rbac_cont">
                <div class="c_top">
                    <a href="javascript:void()" title=""><img class="logo" src="images/loginPics/login_logo_sso.png" alt=""></a>
                    <h1>ͳһȨ�� ����ϵͳ</h1>
                    <span class="c_top_radius"></span>
                </div>
                <form id="fm1" class="fm-v clearfix" method="post">
                    <div class="c_middle">
                        <p><label for="username">请输入您的用户名</label>
                            <input type="text" id="username" name="username" placeholder="请输入您的用户名"/><span id ="error" ></span>
                            <span class="mail"></span></p>
                        <p class="p_special" ><label for="password">密&nbsp;&nbsp;码</label><input type="password" id="password" name="password" placeholder="请输入您的密码"/>   
                        

                        </p>     
                    </div>
                    <div class="c_bottom">
                        <p><input class="login" type="submit" value="&nbsp;&nbsp;" /></p>
                        <span class="c_bottom_radius"></span>
                    </div>
                    <span class="rbac_cont_shadow"></span>
            </div>
        </form>
        <div class="info">
            <p>安全提示：访问过提供凭证信息的应用时，操作完成后需关闭浏览器</p>
            <p>密码丢失：请联系技术网站运维部门的桌面组或者域账户管理员</p>
        </div> 
    </div>
    <div class="footer">Copyright &copy; blseller, All Rights Reserved</div>
</body>
</html>