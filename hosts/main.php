<?php
if (!defined("ROOT"))
    define("ROOT", dirname(__FILE__));
include(ROOT . "/../trade_inc/conf.inc");
include(ROOT . "/../trade_inc/lib/tools.inc");
include(ROOT . "/../trade_inc/lib/cookie.inc");
include(ROOT . "/../trade_inc/lib/myPDO.inc");
include(ROOT . "/../trade_inc/data/db.inc");
include(ROOT . "/../trade_inc/data/userHandler.inc");
include(ROOT . "/../trade_inc/data/companyNoticeHandler.inc");
include(ROOT . "/../trade_inc/data/permissionDataHandler.inc");
include(ROOT . "/../trade_inc/facade/cookieManager.inc");

cookieManager::checkLogin();
?>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
        <link rel="stylesheet" href="css/headbottom.css" type="text/css" media="all">
        <link rel="stylesheet" href="css/main.css" type="text/css" media="all">
        <link rel="stylesheet" href="css/buttons.css" type="text/css" media="all">
        <script type="text/javascript" src="js/jquery.js"></script>
        <script type="text/javascript" src="js/main.js"></script>
        <title><?php echo Conf::$title ?></title>
    </head>
    <body>

        <?php include ROOT . "/../trade_inc/pages/common/pageHeader.inc"; ?>
        <!--页头部分结束-->
        <div class="midcontent">
            <div class="contentleft">

                <div class="firstButtons">
                    <a class="button big blue rounded">客户</a>
                    <a class="button big blue rounded">产品</a>
                    <a class="button big blue rounded">产品销售</a>
                    <a class="button big blue rounded">报价单</a>
                    <a class="button big blue rounded">报表分析</a>
                    <a class="button big blue rounded">核销单管理</a>
                    <a class="button big blue rounded">收款管理</a>
                    <a class="button big blue rounded">分票结算</a>
                    <a class="button big blue rounded">分票结算</a>
                </div>

            </div>
            <div class="contentright">
                <div class="notice">
                    <div class="contentright_top">
                        <span>通知栏</span>
                        <a href="javascript:void(0)" onclick="showPage('pages/common/popShow.php?who=addnotice',550,400)" ><span class="noticeadd"><img src="images/button/plus.png" width="14px" height="14px">新建</span></a>
                    </div>

                    <div class="noticecontent">
                        <ul>
                            <?php
                            $noticArr = companyNoticeHandler::getNoticesByCate("通知");
                            $noticHtml = '';
                            foreach ($noticArr as $value) {
                                $noticHtml.='<li><img src="images/button/new_email.png" width="17px" height="17x">' . $value['notice_title'] . '</li>';
                            }
                            echo $noticHtml;
                            ?>
                        </ul>
                        <span class="more"><a href="javascript:void(0)" onclick="showPage('pages/common/popShow.php?who=morenotice',800,450)" >更多</a></span>
                    </div>
                </div>
                <div class="worklog">
                    <div class="contentright_top">
                        <span>工作日志</span>
                        <a href="javascript:void(0)" onclick="showPage('pages/common/popShow.php?who=addshare',600,400)"><span class="noticeadd"><img src="images/button/plus.png" width="14px" height="14px">新建</span></a>
                    </div>
                    <div class="worklogcontent">
                        <ul>
                            <?php
                            $shareArr = companyNoticeHandler::getNoticesBySelfId($_COOKIE['userId']);
                            $shareHtml = '';
                            foreach ($shareArr as $value) {
                                $shareHtml.='<li><img src="images/button/tag_gray.png" width="17px" height="17x">' . $value['notice_title'] . '</li>';
                            }
                            echo $shareHtml;
                            ?>
                        </ul>
                        <span class="more"><a href="javascript:void(0)" onclick="showPage('pages/common/popShow.php?who=moreshare',800,450)" >更多</a></span>
                    </div>
                </div>
            </div>
        </div>

        <!--中间部分结束-->
        <div class="indexbottom">
            <div class="bottomleft">
                <div class="contentright_top">
                    <span>公司业务统计数据</span>
                    <span class="subtitle">  统计数据延迟30分钟</span>
                </div>
                <div class="indexbottomTable">
                    <table class="mytable" cellspacing="0"> 
                        <tr> 
                            <th scope="col">数据项</th> 
                            <th scope="col">单位</th> 
                            <th scope="col">上月</th> 
                            <th scope="col">本月</th>
                            <th scope="col">增/降幅</th> 
                            <th scope="col">操作</th>
                        </tr> 
                        <tr> 
                            <td class="row">新增客户数</td> 
                            <td class="row">个</td> 
                            <td class="row"></td> 
                            <td class="row">2</td> 
                            <td class="row">1</td> 
                            <td class="row"><a href="javascript:void(0)" onclick="showPage('pages/common/popStatic.php?who=addCustomerNum',1100,700)">查看历史</a></td> 
                        </tr>
                        <tr> 
                            <td class="row">签单额</td> 
                            <td class="row">万美元</td> 
                            <td class="row"></td> 
                            <td class="row"></td> 
                            <td class="row"></td> 
                            <td class="row"><a href="javascript:void(0)" onclick="showPage('pages/common/popStatic.php?who=signingMoney',1100,700)">查看历史</a></td> 
                        </tr>
                        <tr> 
                            <td class="row">收汇款</td> 
                            <td class="row">万美元</td> 
                            <td class="row"></td> 
                            <td class="row"></td> 
                            <td class="row"></td> 
                            <td class="row"><a href="javascript:void(0)" onclick="showPage('pages/common/popStatic.php?who=remittancesReceived',1100,700)">查看历史</a></td> 
                        </tr>
                        <tr> 
                            <td class="row">应收款余额</td> 
                            <td class="row">万美元</td> 
                            <td class="row"></td> 
                            <td class="row"></td> 
                            <td class="row"></td> 
                            <td class="row"><a href="javascript:void(0)" onclick="showPage('pages/common/popStatic.php?who=receivableBalances',1100,700)">查看历史</a></td> 
                        </tr>
                        <tr> 
                            <td class="row">逾期应收款</td> 
                            <td class="row">万美元</td> 
                            <td class="row"></td> 
                            <td class="row"></td> 
                            <td class="row"></td> 
                            <td class="row"><a href="javascript:void(0)" onclick="showPage('pages/common/popStatic.php?who=overdueReceivables',1100,700)">查看历史</a></td> 
                        </tr>
                    </table>
                </div>
            </div>
            <div class="bottomright">
                <div class="contentright_top">
                    <span>个人业务统计数据</span>
                    <span class="subtitle">  统计数据延迟30分钟</span>
                    <span class="noticeadd">查看更多员工信息</span>
                </div>
                <div class="indexbottomTable">
                    <table class="mytable" cellspacing="0"> 
                        <tr> 
                            <th scope="col">员工</th> 
                            <th scope="col">登陆次数</th> 
                            <th scope="col">客户数</th> 
                            <th scope="col">签单额</th>
                            <th scope="col">收汇额</th> 
                            <th scope="col">操作</th>
                        </tr> 
                        <tr> 
                            <td class="row">badwolf</td> 
                            <td class="row">100</td> 
                            <td class="row">010-110</td> 
                            <td class="row">中国北京</td> 
                            <td class="row">010-110</td> 
                            <td class="row">中国北京</td> 
                        </tr> 
                        <tr> 
                            <td class="row">badwolf</td> 
                            <td class="row">100</td> 
                            <td class="row">010-110</td> 
                            <td class="row">中国北京</td> 
                            <td class="row">010-110</td> 
                            <td class="row">中国北京</td> 
                        </tr>
                        <tr> 
                            <td class="row">badwolf</td> 
                            <td class="row">100</td> 
                            <td class="row">010-110</td> 
                            <td class="row">中国北京</td> 
                            <td class="row">010-110</td> 
                            <td class="row">中国北京</td> 
                        </tr>
                        <tr> 
                            <td class="row">badwolf</td> 
                            <td class="row">100</td> 
                            <td class="row">010-110</td> 
                            <td class="row" alt="中国北京中国北京^O^" title="中国北京中国北京^O^">中国北京中国北京</td> 
                            <td class="row">010-110</td> 
                            <td class="row">中国北京</td> 
                        </tr>
                        <tr> 
                            <td class="row">badwolf</td> 
                            <td class="row">100</td> 
                            <td class="row">010-110</td> 
                            <td class="row" alt="中国北京中国北京^O^" title="中国北京中国北京^O^">中国北京中国北京</td> 
                            <td class="row">010-110</td> 
                            <td class="row">中国北京</td> 
                        </tr>
                    </table>
                </div>
            </div>
        </div>

        <?php include ROOT . "/../trade_inc/pages/common/pageBottom.inc"; ?>
    </body>
</html>
