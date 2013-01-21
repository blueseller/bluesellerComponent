<?php
    $usercontent = userHandler::getUserByName($_COOKIE['Tuser'])->data;
?>
<script type="text/javascript" src="js/login.js"></script>
<div class="top clearfix">

    <div class="headerCon">
        <div class="tradeLogo">
            <img src="images/loginPics/login_logo_sso.png" alt="外贸通" width="200" height="80">
        </div>

        <div class="tipMessage">
            <span><img src="images/button/lamp_active.png" width="19px" height="19px"><?php echo $_COOKIE['Tnickname'] ?>,欢迎您登陆外贸管理系统</span>
        </div>

        <div class="userLoginMsg">
            <a><span><img src="images/button/user_friend.png" width="19px" height="19px"><?php echo $_COOKIE['Tnickname'] ?></span></a><br>
            <a><span><img src="images/button/help.png" width="19px" height="19px">帮助</span></a><a><span><img src="images/button/options.png" width="19px" height="19px">设置</span></a><a href="javascript:void(0)" onclick="loginout()"><span><img src="images/button/help_ring-buoy.png" width="19px" height="19px">退出</span></a><br>
            <span>您上次登陆的时间：<?php echo $_COOKIE['Tlastlogintime'] ?></span>

        </div>
    </div>

    <div class="tabnav clearfix">
        <div class="mainMenuBst">
            <ul class="mainMenu" id="mainMenu">
                <li class ="connn"><a href="main.php" title="首页"><span>首页</span></a></li>
                <li><a href="customerManager.php?who=customer" title="客户/供应商"><span>客户/供应商</span></a></li>
                <li><a href="product.php?who=product" title="产品"><span>产品</span></a></li>
                <li><a href="sample.php?who=sample" title="出口业务"><span>出口业务</span></a></li>
                <li><a href="list.php?cid=68" title="核算中心"><span>核算中心</span></a></li>
                <li><a href="live.php" title="决策支持"><span>决策支持</span></a></li>
                <li><a href="live.php" title="系统设置"><span>系统设置</span></a></li>
            </ul>
        </div>
        <div class="nav-bottom">
            <div class="nav-bottomtab">
                <div class="navcontent" id="con" style="text-indent: 60px; ">欢迎您使用外贸管理系统！</div>
                <div class="navcontent hidden" id="con1" style="text-indent: 60px; "><a href="/main.php" class="content">工作台</a> | <a href="/zuyong_sh.asp" class="content">日程安排</a></div>
                <div class="navcontent hidden" id="con2" style="text-indent: 180px; "><a href="customerManager.php?who=customer" class="content">客户</a> | <a href="customerManager.php?who=suppliers" class="content">供应商</a> </div>
                <div class="navcontent hidden" id="con3" style="text-indent: 310px;"><a href="product.php?who=product" class="content">产品管理</a> | <a href="product.php?who=customscode" class="content">海关编码</a></div>
                <div class="navcontent hidden" id="con4" style="text-indent: 440px;"><a href="sample.php?who=sample" class="content">样品</a> | <a href="sample.php?who=quotation" class="content">报价单</a> | <a href="/zuyong_yf.asp" class="content">销售订单</a> | <a href="/zuyong_yf.asp" class="content">采购/生产</a> | <a href="/zuyong_yf.asp" class="content">出运明细单</a> | <a href="/zuyong_yf.asp" class="content">单证制作</a> | <a href="/zuyong_yf.asp" class="content">验货单</a></div>
                <div class="navcontent hidden" id="con5" style="text-indent: 570px;"><a href="/zuyong_zq.asp" class="content">应收款</a> | <a href="/zuyong_sh.asp" class="content">收款单</a> | <a href="/zuyong_zq.asp" class="content">分票结算</a> | <a href="/zuyong_sh.asp" class="content">核销单</a></div>
                <div class="navcontent hidden" id="con6" style="text-indent: 690px;"><a href="/zuyong_zq.asp" class="content">客户分析</a> | <a href="/zuyong_sh.asp" class="content">业务分析</a> </div>
                <div class="navcontent hidden" id="con7" style="text-indent: 650px;"><a href="/zuyong_zq.asp" class="content">公司信息</a> |<a href="/zuyong_zq.asp" class="content">部分员工</a> |<a href="/zuyong_zq.asp" class="content">中国供应商</a> |<a href="/zuyong_zq.asp" class="content">审核设置</a> |<a href="/zuyong_zq.asp" class="content">基础信息</a> </div>
            </div>
        </div>

    </div>
</div>