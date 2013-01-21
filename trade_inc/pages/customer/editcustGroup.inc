<?php
$customerid = Tools::getValue('id', '');
$customerContent = customerHandler::getCustomerOnlyById($customerid);
$allGroups =  customerGroupHandler::getGroups("customer");
$groupsHtml = "";
foreach ($allGroups as $value) {
    $groupsHtml .= '<option value="'.$value["id"].'"';
    if($value["id"] == $customerContent["customer_group"]){
        $groupsHtml .=" selected";
    }
    $groupsHtml .=">";
    $groupsHtml .= $value["customer_group_name"];
    $groupsHtml .= "</option>";
}
?>

<form id="pop_form">
    <div class="addNotice">
        <h5>修改客户分组</h5>
        <table class="add">
            <tr>
                <td valign="top">修改客户分组为<span style="color:red">[*]</span>:</td>
                <td>
                    <select style="width:155px;" name="selectedWho">
                       <?php echo $groupsHtml;?>
                    </select>
                </td>
            </tr>

        </table>
    </div>
    <div class="bottom_button">
        <input type="submit" value="保存" class="save" flagwho="sharecustomerGroup">
        <input type="button" value="关闭" class="close">
        <input type="hidden" value="sharecustomerGroup" name="subwho">
        <input type="hidden" value="<?php echo $customerid;?>" name="customerid">
    </div>
</form>