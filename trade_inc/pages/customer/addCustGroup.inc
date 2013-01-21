<?php
$groupid = Tools::getValue('id', '');
$checkContent = Tools::getValue('check', '');
$catetype = Tools::getValue('catetype', '');
$name = '';
$detail = '';
$readonly = '';
$display = '';
if (!empty($groupid)) {
    $returnrow = customerGroupHandler::getGroupById($groupid);
    if (!empty($checkContent)) {
        $name = '<label>'. $returnrow['customer_group_name'].'</label>';
        $readonly = "readonly";
        $display = 'style="display:none"';
    }else{
        $name = '<input type="text" id="custgroupname" name="custgroupname" value="' . $returnrow['customer_group_name'].'">';
    }
    $detail = $returnrow['customer_group_detial'];
}else{
    $name = '<input type="text" id="custgroupname" name="custgroupname" value="">';
}
?>

<form id="pop_form">
    <div class="addNotice">
        <table class="add">
            <tr style="height: 30px;line-height: 30px;">
                <td valign="top">分组名称<span style="color:red">[*]</span>:</td>
                <td><?php echo $name; ?></td>
            </tr>
            <tr style="display: none">
                <td valign="top">所属分组<span style="color:red">[*]</span>:</td>
                <td><select style="width:325px;">
                        <option>全部客户</option>
                        <option>全部客户</option>
                    </select></td>
            </tr>
            <tr>
                <td valign="top">描述:</td>
                <td><textarea id="custgroupdetail" name="custgroupdetail" <?php echo $readonly; ?>><?php echo $detail; ?></textarea></td>
            </tr>
        </table>
    </div>
    <div class="bottom_button">
        <input type="submit" value="保存" class="save" flagwho="addCustomerGroup" <?php echo $display; ?>>
        <input type="button" value="关闭" class="close">
        <input type="hidden" value="addcustomergroup" name="subwho">
        <input type="hidden" value="<?php echo $groupid; ?>" name="groupid">
        <input type="hidden" value="<?php echo $catetype; ?>" name="catetype">
    </div>
</form>