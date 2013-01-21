<?php
$who = Tools::getValue('who', '');
if ($who == "product") {
    $bindClassName = "productlist";
    $name = "产品分组";
}else if ($who == "customscode"){
    $bindClassName = "customscodelist";
    $name = "分组";
}

$groups = customerGroupHandler::getGroups($who);
$groupsHtml = '';
foreach ($groups as $value) {
    $groupsHtml.='<li class="collapsable"><div class="hitarea collapsable-hitarea "></div><span class="folder groups" name="';
    $groupsHtml.=$value['id'] . '"><a href="javascript:void()">';
    $groupsHtml.=$value['customer_group_name'];
    $groupsHtml.='</a></span></li>';
}
?>

<div class="listcontentLeft">
    <div class="">
        <div class="cate" name="group"><img src="../../images/button/tag_gray.png" width="14px" height="14px"><span><?php echo $name;?></span></div>
        <div class="treeContent cateselected nobottomline">
            <div  class="options">
                <table>
                    <tr>
                        <td><a href="javascript:void(0)" onclick="showPage('pages/common/popShow.php?who=addCustGroup&catetype=<?php echo $who;?>',600,400)"><span class="noticeadd"><img src="../../images/button/plus.png" width="14px" height="14px">新建</span></a></td>
                        <td><a href="javascript:void(0)" onclick="listleftpop('pages/common/popShow.php?who=addCustGroup',600,400)"><span class="noticeadd"><img src="../../images/button/pencil_edit.png" width="14px" height="14px">修改</span></a></td>
                        <td><a href="javascript:void(0)" onclick="deleteGroupContent()"><span class="noticeadd"><img src="../../images/button/close_delete.png" width="14px" height="14px">删除</span></a></td>
                        <td><a href="javascript:void(0)" onclick="listleftpop('pages/common/popShow.php?who=addCustGroup&check=true',600,400)"><span class="noticeadd"><img src="../../images/button/comment.png" width="14px" height="14px">查看</span></a></td>
                    </tr>
                </table>
            </div>
            <input type="hidden" id="selectedGroupId" value="">
            <div class="st_tree <?php echo $bindClassName;?>" style="height: 400px">
                <ul id="browser" class="filetree treeview">
                    <?php echo $groupsHtml; ?>

                </ul>
            </div>
        </div>

    </div>
    <input type="hidden" value="<?php echo $who;?>" id="leftlistname">
</div>