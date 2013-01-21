<?php
$supplierid = Tools::getValue('id', '');
?>
<form id="pop_form">
    <div class="addNotice">
        <table class="add" id="insertContactDiv">
        <span class="checktitle" id="showtitle">添加客户联系信息</span>
        <tbody>
            <tr>
                <td class="" style="width:100px;">联系人<span style="color:red">[*]</span>:</td>
                <td class=""><input name="contact0" value="" style="width:155px;" id="contactername"></td>
                <td class="" style="width:100px;">传真:</td>
                <td class=""><input name="contact1" value="" style="width:155px;"></td>
            </tr>
            <tr>
                <td class="" style="width:100px;">电话:</td>
                <td class=""><input name="contact2" value="" style="width:155px;"></td>
                <td class="" style="width:100px;">手机:</td>
                <td class=""><input name="contact3" value="" style="width:155px;"></td>
            </tr>
            <tr>
                <td class="" style="width:100px;">电子邮件<span style="color:red">[*]</span>:</td>
                <td class=""><input name="contact5" value="" style="width:155px;"></td>
                <td class="" style="width:100px;">其他:</td>
                <td class=""><input name="contact7" value="" style="width:155px;" id="contacteremail"></td>
            </tr>
        </tbody>
    </table>
    </div>
    <div class="bottom_button">
        <input type="submit" value="保存" class="save" flagwho="addContactContent">
        <input type="button" value="关闭" class="close">
        <input type="hidden" value="addContactContent" name="who">
        <input type="hidden" value="<?php echo $supplierid;?>" name="customerid">
        <input type="hidden" value="supplier" name="contactflag">
    </div>
</form>