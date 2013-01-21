<div class="listtitle">
    <span class="title">
        <?php
        $who = Tools::getValue('who', '');
        $selectHtml = "";
        if ($who == "sample") {
            echo "样品";
            $addUrl = "pages/common/popShow.php?who=addsample";
            $checkUrl = "pages/common/popShow.php?who=checksample";
            $typename = "sample";
            $selectHtml = '<span class="topcate">
            分类
            <select id="samplestatusselect" onchange="selectSamplebyStatus()">
                <option value="寄出">寄出样品</option>
                <option value="寄入">寄入样品</option>
            </select>
        </span>';
        } else if ($who == "quotation") {
            echo "报价单";
            $addUrl = "pages/common/popShow.php?who=addquotation";
            $checkUrl = "pages/common/popShow.php?who=checkquotation";
            $typename = "quotation";
            $selectHtml = '<span class="topcate">
            分类
            <select id="samplestatusselect" onchange="selectQuotationbyStatus()">
                <option value="all">所有报价单</option>
                <option value="toaudit">待审查的报价单</option>
            </select>
        </span>';
        }
        
        echo $selectHtml;
        ?>
        

    </span>
    <span class="options">
        <input type="hidden" value="<?php echo $typename; ?>" id="typename">
        <a href="javascript:void(0)" onclick="showPage('<?php echo $addUrl; ?>',850,550)"><span class="noticeadd"><img src="../../images/button/plus.png" width="14px" height="14px">新建</span></a>
        <a href="javascript:void(0)" onclick="editContentPage('<?php echo $addUrl; ?>',850,550)"><span class="noticeadd"><img src="../../images/button/pencil_edit.png" width="14px" height="14px">修改</span></a>
        <a href="javascript:void(0)" id="deleteCustomer" class="tigger"><span class="noticeadd"><img src="../../images/button/close_delete.png" width="14px" height="14px">删除</span></a>
        <a href="javascript:void(0)" onclick="editContentPage('<?php echo $checkUrl; ?>',850,550)"><span class="noticeadd"><img src="../../images/button/comment.png" width="14px" height="14px">查看</span></a>
    </span>
</div>