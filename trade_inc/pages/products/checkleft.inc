<?php 
    $customerId = Tools::getValue("id", '')
?>
<div class="leftSelectes">
    <table class="leftSelectesTable">
        <tr>
            <td><a href="?who=checkCustomer&id=<?php echo $customerId;?>"><span><img src="../../images/button/user_friend.png" class="flag"></span>产品基本信息</a></td>
        </tr>
        <tr>
            <td><a href="?who=checkContact&id=<?php echo $customerId;?>"><span><img src="../../images/button/smartphone_iphone.png" class="flag"></span>联系人</a></td>
        </tr>
        <tr>
            <td><a href="#"><span><img src="../../images/button/star_3.png" class="flag"></span>相关样品信息</a></td>
        </tr>
        <tr>
            <td><a href="#"><span><img src="../../images/button/calculator.png" class="flag"></span>相关报价信息</a></td>
        </tr>
        <tr>
            <td><a href="#"><span><img src="../../images/button/shopping_cart.png" class="flag"></span>相关销售信息</a></td>
        </tr>
        <tr>
            <td><a href="#"><span><img src="../../images/button/vote_yes.png" class="flag"></span>相关收款信息</a></td>
        </tr>
        <tr>
            <td><a href="#"><span><img src="../../images/button/wizard.png" class="flag"></span>相关发货信息</a></td>
        </tr>
    </table>
</div>