<?php
$customerid = Tools::getValue('id', '');
$remindContentArr = array();
$remind = customerHandler::getCustomerOnlyById($customerid);
if (!empty($remind)) {
    $remindId = $remind['customer_remind_id'];
    $remindContentArr = remindsHandler::getRemindById($remindId);
}

if (empty($remindContentArr)) {
    echo '<div class="addNotice">';
    echo '<h4>您还没有添加提醒。如要添加提醒请<a href="popShow.php?who=addRemind&id=' . $customerid . '" style="color:red">点击此处</a></h4>';
    echo '</div><div class="bottom_button">
    <input type="button" value="关闭" class="close">
</div>';
    exit;
}
?>
<div class="addNotice">
    <table class="add">
        <tr style="height: 30px;line-height: 30px;">
            <td valign="top">提醒标题<span style="color:red">[*]</span>:</td>
            <td><?php echo $remindContentArr['remind_title']; ?></td>
        </tr>
        <tr>
            <td valign="top">开始时间:</td>
            <td><?php echo $remindContentArr['remind_start_time']; ?></td>
        </tr>
        <tr>
            <td valign="top">结束时间:</td>
            <td><?php echo $remindContentArr['remind_end_time']; ?></td>
        </tr>
        <tr>
            <td valign="top">主要内容:</td>
            <td><textarea style="height: 80px" readonly><?php echo $remindContentArr['remind_content']; ?></textarea></td>
        </tr>
    </table>
</div>
<div class="bottom_button">
    <input type="button" value="关闭" class="close">
</div>