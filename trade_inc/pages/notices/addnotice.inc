<form id="pop_form">
    <div class="addNotice">
        <table class="add">
            <tr>
                <td valign="top">标题<span style="color:red">[*]</span>:</td>
                <td><input type="text" value="" name="addnoticetitle" id="noticetitle"></td>
            </tr>
            <tr>
                <td valign="top">内容<span style="color:red">[*]</span>:</td>
                <td><textarea name="addnoticeContent" value="" id="noticeContent"></textarea></td>
            </tr>
        </table>
    </div>
    <div class="bottom_button">
        <input type="hidden" value="addnotice" name="subwho">
        <input type="hidden" value="通知" class="noticecategory" name="noticecategory" class="noticecategory">
        <input type="button" value="保存" class="save" flagwho="addNotice">
        <input type="button" value="关闭" class="close">
    </div>
</form>