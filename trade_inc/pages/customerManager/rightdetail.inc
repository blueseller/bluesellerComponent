<?php
$customerLists = requestCustomer::$customers;
$allcountnum = requestCustomer::$allcount;
$listHtml = '';
foreach ($customerLists as $value) {
    $listHtml.='<tr id="' . $value['id'] . '" class="' . $value['customer_name'] . '">';
    $listHtml.='<td>' . $value['customer_id'] . '</td>';
    $listHtml.='<td>' . requestCustomer::getRemindHtml($value['id'],$value['customer_remind_id']) . '</td>';
    $listHtml.='<td>' . $value['customer_name'] . '</td>';
    $listHtml.='<td>' . $value['contact_name'] . '</td>';
    $listHtml.='<td>' . $value['contact_email'] . '</td>';
    $listHtml.='<td>' . $value['contact_tel'] . '</td>';
    $listHtml.='<td>' . $value['customer_country'] . '</td>';
    $listHtml.='<td>' . $value['customer_province'] . '</td>';
    $listHtml.='<td>' . requestCustomer::getCustomerIsWhohave($value['customer_whohave']) . '</td>';
    $listHtml.='<td>' . $value['contact_lastcontacttime'] . '</td>';
    $listHtml.='<td>' . $value['customer_from'] . '</td>';
    $listHtml.='<td>' . $value['contact_fax'] . '</td>';
    $listHtml.='<td>' . $value['customer_attention'] . '</td>';
    $listHtml.='</tr>';
}
?>

<div class="listcontentRight">
    <div class="detailRight">
        <table class="customerdetailContent">
            <?php
            echo htmlTemplate::customerlistHTML();
            echo $listHtml;
            ?>
        </table>

    </div>
    <div class="detailPageOptions">
        <div class="bottom" id="bottompaging">
            <?php
            $sumpage = ceil($allcountnum / Conf::$numlist);
            $pageHtml = commonFun::paging(1, $sumpage, count($customerLists), $allcountnum,"getcustomer"); //第一次进来都是第一页1
            echo $pageHtml;
            ?>
        </div>
        <input type="hidden" value="" id="selectedID">
        <input type="hidden" value="" id="pageoptions">
        <input type="hidden" value="" id="thisid">
    </div>
</div>
<div class="contextMenu" id="customerTableListRightMenu">
    <ul>
        <li id="add"><img src="../../images/button/plus.png" width="14px" height="14px">新建客户</li>
        <li id="edit"><img src="../../images/button/pencil_edit.png" width="14px" height="14px">修改客户</li>
        <li id="check"><img src="../../images/button/comment.png" width="14px" height="14px">查看客户</li>
        <li id="delete"><img src="../../images/button/close_delete.png" width="14px" height="14px">删除客户</li>
        <HR style="border:1 dashed #999999" width="80%" color=#987cb9 SIZE=1>
        <li id="tocustGroup"><img src="../../images/button/friends_group.png" width="14px" height="14px">分配客户</li>
        <li id="editcustGroup"><img src="../../images/button/tag_blue.png" width="14px" height="14px">修改客户分组</li>
        <HR style="border:1 dashed #999999" width="80%" color=#987cb9 SIZE=1>
        <li id="writemail"><img src="../../images/button/new_email.png" width="14px" height="14px">写信</li>
        <li id="addContacter"><img src="../../images/button/pencil_edit.png" width="14px" height="14px">新建联系人</li>
        <li id="addContacteLog"><img src="../../images/button/mobile_phone.png" width="14px" height="14px">新建联系记录</li>
        <HR style="border:1 dashed #999999" width="80%" color=#987cb9 SIZE=1>
        <li id="addremind"><img src="../../images/button/lamp_active.png" width="14px" height="14px">添加/修改提醒</li>
        <li id="checkremind"><img src="../../images/button/lamp_active.png" width="14px" height="14px">查看提醒</li>
        <li id="deleteremind"><img src="../../images/button/close_delete.png" width="14px" height="14px">取消提醒</li>
        <li id="addbusinessorder"><img src="../../images/button/shield_protect_on.png" width="14px" height="14px">新建业务单据</li>
    </ul>
</div>