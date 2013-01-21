<?php
if (!defined("ROOT"))
    define("ROOT", dirname(__FILE__));
include(ROOT . "/../trade_inc/conf.inc");
include(ROOT . "/../trade_inc/lib/tools.inc");
include(ROOT . "/../trade_inc/lib/cookie.inc");
include(ROOT . "/../trade_inc/lib/myPDO.inc");
include(ROOT . "/../trade_inc/lib/commonFun.inc");
include(ROOT . "/../trade_inc/data/db.inc");
include(ROOT . "/../trade_inc/data/userHandler.inc");
include(ROOT . "/../trade_inc/data/permissionDataHandler.inc");
include(ROOT . "/../trade_inc/facade/cookieManager.inc");
include (ROOT . "/../trade_inc/data/contactHandler.inc");
include (ROOT . "/../trade_inc/data/userPermissionHandler.inc");
include (ROOT . "/../trade_inc/data/customerHandler.inc");
include (ROOT . "/../trade_inc/facade/customer/requestCustomer.inc");
include (ROOT . "/../trade_inc/data/customerGroupHandler.inc");
include (ROOT . "/../trade_inc/data/configHandler.inc");
include (ROOT . "/../trade_inc/data/productHandler.inc");
include (ROOT . "/../trade_inc/template/htmlTemplate.inc");
include (ROOT . "/../trade_inc/data/sampleHandler.inc");

cookieManager::checkLogin();
?>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
        <link rel="stylesheet" href="css/headbottom.css" type="text/css" media="all">
        <link rel="stylesheet" href="css/customer.css" type="text/css" media="all">
        <link rel="stylesheet" href="css/buttons.css" type="text/css" media="all">
        <link rel="stylesheet" href="css/SimpleTree.css" type="text/css" media="all">
        <link rel="stylesheet" href="css/popup_layer.css" type="text/css" media="all">
        <script type="text/javascript" src="js/jquery.js"></script>
        <script type="text/javascript" src="js/contentMenu.mini.js"></script>
        <script type="text/javascript" src="js/main.js"></script>
        <script type="text/javascript" src="js/pop.js"></script>
        <script type="text/javascript" src="js/common/rightmenu.js"></script>
        <script type="text/javascript" src="js/customer.js"></script>
        <script type="text/javascript" src="js/SimpleTree.js"></script>
        <script type="text/javascript" src="js/popup_layer.js"></script>
        <script type="text/javascript" src="js/common/checkValue.js"></script>
        <title><?php echo Conf::$title ?></title>
    </head>
    <body>

        <?php include ROOT . "/../trade_inc/pages/common/pageHeader.inc"; ?>

        <div class="mainBody">
            <?php
            include ROOT . "/../trade_inc/pages/common/search.inc";
            ?>

            <div class="mainBodyList">

                <?php
                include ROOT . "/../trade_inc/pages/sample/topoptions.inc";
                ?>

                <div class="listcontent">

                    <?php
                    if (Tools::getValue('who', '') == "quotation") {
                        include ROOT . "/../trade_inc/pages/quotation/quotationdetail.inc";
                    } elseif (Tools::getValue('who', '') == "sample") {
                        include ROOT . "/../trade_inc/pages/sample/sampledetail.inc";
                    }
                    ?>

                </div>

            </div>

        </div>

        <?php include ROOT . "/../trade_inc/pages/common/pageBottom.inc"; ?>
    </body>

    <div class="contextMenu" id="TreeRightMenu">
        <ul>
            <li id="checkGroup"><img src="../../images/button/comment.png" width="14px" height="14px">查看分组</li>
            <li id="addGroup"><img src="../../images/button/plus.png" width="14px" height="14px">新建分组</li>
            <li id="editGroup"><img src="../../images/button/pencil_edit.png" width="14px" height="14px">修改分组</li>
            <li id="deleteGroup"><img src="../../images/button/close_delete.png" width="14px" height="14px">删除分组</li>
            <li id="addCustomer"><img src="../../images/button/plus.png" width="14px" height="14px">新建客户</li>
        </ul>
    </div>

    <div id="blk9" class="blk" style="display:none;">
        <div class="pop_main">
            <a href="javascript:void(0)" id="closeButton" class="closeBtn closeButton">关闭</a>
            <div style="text-align: center;padding: 40px 0 20px 0;" id="popdiv">
                <p id="poplaye_title">您是否要删除此条数据？</p>
                <input type="button" value="是" id="deleteYesButton"> <input type="button" value="否" class="closeButton closeInput"> 
            </div>
        </div>
    </div>

</html>
