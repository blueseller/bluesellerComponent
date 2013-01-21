<?php
if (!defined("ROOT"))
    define("ROOT", dirname(__FILE__) . "/../../../");
include (ROOT . "/trade_inc/lib/tools.inc");
include (ROOT . "/trade_inc/facade/show_who/popContentSelect.inc"); //选择要显示哪个页面
include (ROOT . "/trade_inc/conf.inc");
include(ROOT . "/trade_inc/lib/myPDO.inc");
include(ROOT . "/trade_inc/data/db.inc");
include(ROOT . "/trade_inc/data/permissionDataHandler.inc");
include(ROOT . "/trade_inc/data/userHandler.inc");
include(ROOT . "/trade_inc/data/customerHandler.inc");
include(ROOT . "/trade_inc/data/contactHandler.inc");
include(ROOT . "/trade_inc/data/supplierHandler.inc");
include(ROOT . "/trade_inc/data/userPermissionHandler.inc");
include(ROOT . "/trade_inc/data/dataBean/productBean.inc");
include(ROOT . "/trade_inc/data/dataBean/customerBean.inc");
include(ROOT . "/trade_inc/data/dataBean/sampleBean.inc");
include (ROOT . "/trade_inc/data/remindsHandler.inc");
include(ROOT . "/trade_inc/lib/cookie.inc");
include(ROOT . "/trade_inc/facade/cookieManager.inc");
include(ROOT . "/trade_inc/template/htmlTemplate.inc");
include (ROOT . "/trade_inc/facade/customer/requestCustomer.inc");
include (ROOT . "/trade_inc/data/configHandler.inc");
include (ROOT . "/trade_inc/data/productHandler.inc");
include (ROOT . "/trade_inc/data/customerGroupHandler.inc");
include (ROOT . "/trade_inc/data/sampleHandler.inc");
cookieManager::checkLogin();
$pagename = popContentSelect::init();
?>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
        <link rel="stylesheet" href="../../css/pop.css" type="text/css" media="all">
        <script type="text/javascript" src="../../js/jquery.js"></script>
        <script type="text/javascript" src="../../js/common/popcommon.js"></script>     
        <script type="text/javascript" src="../../js/jquery.form.js"></script>
        <script type="text/javascript" src="../../js/contentMenu.mini.js"></script>
        <script type="text/javascript" src="../../js/pop.js"></script>
        <script type="text/javascript" src="../../js/main.js"></script>
        <script type="text/javascript" src="../../js/common/checkValue.js"></script>
        <title></title>
    </head>
    <body>
        <?php
        if ($pagename != "") {
            include_once ROOT . $pagename;
        }
        ?>
    </body>
</html>

<div class="contextMenu" id="myMenu1">
    <ul>
        <li id="addnew"><img src="../../images/button/plus.png" width="14px" height="14px">新建</li>
        <li id="edit"><img src="../../images/button/pencil_edit.png" width="14px" height="14px">修改</li>
        <li id="check"><img src="../../images/button/comment.png" width="14px" height="14px">查看</li>
        <li id="delete"><img src="../../images/button/close_delete.png" width="14px" height="14px">删除</li>
    </ul>
</div>
<input type="hidden" value="" id="contentid">
