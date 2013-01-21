<?php
if (!defined("ROOT"))
    define("ROOT", dirname(__FILE__) . "/../../../");
include (ROOT . "/trade_inc/lib/tools.inc");
include (ROOT . "/trade_inc/conf.inc");
include (ROOT . "/trade_inc/facade/show_who/popCharStaticSelect.inc"); //选择要显示哪个页面
include(ROOT . "/trade_inc/lib/myPDO.inc");
include(ROOT . "/trade_inc/data/db.inc");
include(ROOT . "/trade_inc/data/staticConfigeHandler.inc");
include(ROOT . "/trade_inc/data/companyStaticMonthHandler.inc");
$content = popCharStaticSelect::init();
?>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
        <link rel="stylesheet" href="../../css/pop.css" type="text/css" media="all">
        <script type="text/javascript" src="../../js/jquery.js"></script>
        <script type="text/javascript" src="../../js/highcharts.js"></script>

        <script type="text/javascript" src="../../js/common/popcommon.js"></script>
        <!--[if IE]>
              <script type="text/javascript" src="../../js/excanvas.compiled.js"></script>
        <![endif]-->
        <?php
        echo $content['script'];
        ?>

        <title>历史业务数据统计信息---<?php echo $content['title'];?></title>
    </head>
    <body>
        <div class="addNotice">
            <div class="charTop">
                <table>
                    <tr class="header">
                        <td  colspan="13">历史业务数据统计信息</td>
                        <td>统计单位：<?php echo $content['statistical_units']; ?></td>
                    </tr>
                    <tr>
                        <td>统计项</td>
                        <?php
                        echo $content['tableMonths'];
                        ?>
                        <td>合计</td>
                    </tr>
                    <tr>
                        <td>新增客户数</td>
                        <?php
                        echo $content['tablestaticNums'];
                        ?>
                    </tr>
                </table>
            </div>
            <div id="container" style="width: 800px; height: 400px; margin: 0 auto"></div>
        </div>
        <div class="bottom_button">
            <input type="button" value="关闭" class="close">
        </div>
    </body>
</html>
<script type="text/javascript" src="../../js/charToimage.js"></script>