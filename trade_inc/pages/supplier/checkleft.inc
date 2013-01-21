<?php 
    $customerId = Tools::getValue("id", '')
?>
<div class="leftSelectes">
    <table class="leftSelectesTable">
        <tr>
            <td><a href="?who=checkSupplier&id=<?php echo $customerId;?>"><span><img src="../../images/button/user_friend.png" class="flag"></span>供应商基本信息</a></td>
        </tr>
        <tr>
            <td><a href="?who=checkSupplierContacter&id=<?php echo $customerId;?>"><span><img src="../../images/button/smartphone_iphone.png" class="flag"></span>联系人</a></td>
        </tr>
        <tr>
            <td><a href="#"><span><img src="../../images/button/star_3.png" class="flag"></span>相关采购信息</a></td>
        </tr>
    </table>
    
</div>