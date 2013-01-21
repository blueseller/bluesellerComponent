<form id="pop_form">
    <div class="addNotice" >
        <span>分配之后，你将看不到此条信息，但可在设置中进行权限配置，来获取查看此条数据的全新</br></br></span>
        <table class="add">
            <tr>
                <td valign="top">分配给谁:</td>
                <td>
                    <select style="width: 220px;" id="selectedName" name="selectedName">
                        <option value=""></option>
                        <?php
                            $optionHtml = "";
                            $users = userHandler::getAllUsers();
                            foreach ($users as $value) {
                                $optionHtml.="<option value=\"".$value["id"]."\">".$value['user_nickname']."</option>";
                            }
                            echo $optionHtml;
                        ?>
                </select>
            </td>
            </tr>
        </table>
    </div>
    <div class="bottom_button">
        <input type="hidden" value="shareSample" name="subwho">
        <input type="button" value="保存" class="save" flagwho="shareSample">
        <input type="button" value="关闭" class="close">
        <input type="hidden" value="<?php echo Tools::getValue("id","");?>" name="sampleid">
    </div>
</form>