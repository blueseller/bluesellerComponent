<div class="listtitle">
    <span class="title">
        <?php
        $who = Tools::getValue('who', '');
        if ($who == "customer") {
            echo "客户列表";
            $addUrl = "pages/common/popShow.php?who=addcustomer";
            $checkUrl = "pages/common/popShow.php?who=checkCustomer";
            $typename= "customer";
        } else {
            echo "供应商列表";
            $addUrl = "pages/common/popShow.php?who=addsupplier";
            $checkUrl = "pages/common/popShow.php?who=checkSupplier";
            $typename= "supplier";
        }
        ?>
    </span>
    <span class="options">
        <input type="hidden" value="<?php echo $typename; ?>" id="typename">
        <a href="javascript:void(0)" onclick="showPage('<?php echo $addUrl; ?>',850,700)"><span class="noticeadd"><img src="../../images/button/plus.png" width="14px" height="14px">新建</span></a>
        <a href="javascript:void(0)" onclick="editContentPage('<?php echo $addUrl; ?>',850,700)"><span class="noticeadd"><img src="../../images/button/pencil_edit.png" width="14px" height="14px">修改</span></a>
        <a href="javascript:void(0)" id="deleteCustomer" class="tigger"><span class="noticeadd"><img src="../../images/button/close_delete.png" width="14px" height="14px">删除</span></a>
        <a href="javascript:void(0)" onclick="editContentPage('<?php echo $checkUrl; ?>',950,630)"><span class="noticeadd"><img src="../../images/button/comment.png" width="14px" height="14px">查看</span></a>
    </span>
</div>