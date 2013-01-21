<?php
$customerid = Tools::getValue('id', '');
$userid = customerHandler::getCustomerIsHaveWho($customerid);
$allusers = userHandler::getAllUsers();
$userlistHtml = "";
foreach ($allusers as $value) {
    $userlistHtml .= '<option value="'.$value["id"].'"';
    if($value["id"] == $userid){
        $userlistHtml .=" selected";
    }
    $userlistHtml .=">";
    $userlistHtml .= $value["user_nickname"];
    $userlistHtml .= "</option>";
}
?>

<form id="pop_form">
    <div class="addNotice">
        <h5>分配客户</h5>
        <table class="add">
            <tr>
                <td valign="top">将客户分配给<span style="color:red">[*]</span>:</td>
                <td>
                    <select style="width:155px;" name="selectedWho">
                       <?php echo $userlistHtml;?>
                    </select>
                </td>
            </tr>
            <tr>
                <td valign="top" colspan="2">分配该客户的同时会将该客户的所有信息都分配给此账户</td>
            </tr>
        </table>
    </div>
    <div class="bottom_button">
        <input type="submit" value="保存" class="save" flagwho="sharecustomer">
        <input type="button" value="关闭" class="close">
        <input type="hidden" value="sharecustomer" name="subwho">
        <input type="hidden" value="<?php echo $customerid;?>" name="customerid">
    </div>
</form>