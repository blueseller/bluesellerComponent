<?php
$customerid = Tools::getValue('id', '');
$remind = customerHandler::getCustomerOnlyById($customerid);
$remindId = $remind['customer_remind_id'];
$remindContentArr = remindsHandler::getRemindById($remindId);
if(empty($remindContentArr)){
    $type = "addRemind";
}else{
    $type = "updateRemind";
}
$remindContentArr = remindBean::setRemindData($remindContentArr);

?>
<form id="pop_form">
    <div class="addNotice">
        <table class="add">
            <tr style="height: 30px;line-height: 30px;">
                <td valign="top">提醒标题<span style="color:red">[*]</span>:</td>
                <td><input type="text" name="remindtitle" id="remindtitle" class="remindtitle" style="width: 300px;" value="<?php echo $remindContentArr['remind_title'];?>"></td>
            </tr>
            <tr>
                <td valign="top">开始时间:</td>
                <td><input type="text" name="starttime" id="starttime" class="starttime" value="<?php echo $remindContentArr['remind_start_time'];?>">
                    <br><span>如何不设置开始时间，默认为现在时间
                </td>
            </tr>
            <tr>
                <td valign="top">结束时间:</td>
                <td><input type="text" name="endtime" id="endtime" class="endtime" value="<?php echo $remindContentArr['remind_end_time'];?>">
                    <br><span>如何不设置结束时间，默认为不结束</span>
                </td>
            </tr>
            <tr>
                <td valign="top">主要内容:</td>
                <td>
                    <textarea name="remindcontent" id="remindcontent" class="remindcontent" style="height: 80px"><?php echo $remindContentArr['remind_content'];?></textarea>
                </td>
            </tr>
        </table>
    </div>
    <div class="bottom_button">
        <input type="submit" value="保存" class="save" flagwho="<?php echo $type;?>">
        <input type="button" value="关闭" class="close">
        <input type="hidden" value="<?php echo $type;?>" name="subwho">
        <input type="hidden" value="<?php echo $remindContentArr['remind_id'];?>" name="remindId">
        <input type="hidden" value="<?php echo $customerid; ?>" name="customerid">
    </div>
</form>