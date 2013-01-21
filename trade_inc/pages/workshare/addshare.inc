<form id="pop_form">
    <div class="addNotice">
        <table class="add">
            <tr>
                <td valign="top">标题<span style="color:red">[*]</span>:</td>
                <td><input type="text" value="" name="addnoticetitle" id="noticetitle"></td>
            </tr>
            <tr>
                <td valign="top">内容<span style="color:red">[*]</span>:</td>
                <td><textarea name="addnoticeContent" id="noticeContent"></textarea></td>
            </tr>
            <tr>
                <td valign="top">分享类型<span style="color:red">[*]</span>:</td>
                <td>
                    <select name="noticecategory">
                        <option>个人分享</option>
                        <option>工作分享</option>
                    </select>
                </td>
            </tr>
        </table>
    </div>
    <div class="bottom_button">
        <input type="hidden" value="addnotice" name="subwho">
        <input type="button" value="保存" class="save" flagwho="addNotice">
        <input type="button" value="关闭" class="close">
    </div>
</form>