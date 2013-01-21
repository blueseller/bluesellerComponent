<?php
$who = Tools::getValue('who', '');
if ($who == "customer") {
    $bindClassName = "customerlist";
}else{
    $bindClassName = "supplierlist";
}

$customergroups = customerGroupHandler::getGroups($who);
$customergroupshtmls = '';
foreach ($customergroups as $value) {
    $customergroupshtmls.='<li class="collapsable"><div class="hitarea collapsable-hitarea "></div><span class="folder groups" name="';
    $customergroupshtmls.=$value['id'] . '"><a href="javascript:void()">';
    $customergroupshtmls.=$value['customer_group_name'];
    $customergroupshtmls.='</a></span></li>';
}

$userId = $_COOKIE['userId'];
if ($who == "customer") {
    $userId = userPermissionHandler::getCustomerPermissionByUserId($userId);
}else{
    $userId = userPermissionHandler::getSuppliersPermissionByUserId($userId);
}
$userlist = userHandler::getUserNameByIds($userId);
$usersHtmls = '';
foreach ($userlist as $value) {
    $usersHtmls.='<li class="collapsable"><div class="hitarea collapsable-hitarea "></div><span class="folder groups" name="';
    $usersHtmls.=$value['id'] . '"><a href="javascript:void()">';
    $usersHtmls.=$value['user_nickname'];
    $usersHtmls.='</a></span></li>';
}

$grades = configHandler::getConfigValueByKey('customer_grade');
$gradearray = explode("|", $grades['config_value']);
$gradeHtml = '';
foreach ($gradearray as $key => $value) {
    $gradeHtml.='<li class="collapsable"><div class="hitarea collapsable-hitarea "></div><span class="folder groups" name="';
    $gradeHtml.=($key + 1) . '"><a href="javascript:void()">';
    $gradeHtml.=$value;
    $gradeHtml.='</a></span></li>';
}


?>

<div class="listcontentLeft">
    <div class="">
        <div class="cate" name="group"><img src="../../images/button/tag_gray.png" width="14px" height="14px"><span>客户分组</span></div>
        <div class="treeContent cateselected">
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
            <div class="st_tree <?php echo $bindClassName;?>">
                <ul id="browser" class="filetree treeview">
                    <?php echo $customergroupshtmls; ?>

                </ul>
            </div>
        </div>

    </div>

    <div class="">
        <div class="cate" name="user"><img src="../../images/button/tag_gray.png" width="14px" height="14px"><span>按拥有者查看</span></div>
        <div class="treeContent hidden">
            <div class="st_tree <?php echo $bindClassName;?>">
                <ul id="browser" class="filetree treeview">
                    <?php echo $usersHtmls; ?>
                </ul>
            </div>
        </div>
    </div>
    <div class="">
        <div class="cate" name="grade"><img src="../../images/button/tag_gray.png" width="14px" height="14px"><span>按星级查看</span></div>
        <div class="treeContent hidden">

            <div class="st_tree <?php echo $bindClassName;?>">
                <ul id="browser" class="filetree treeview">
                    <?php echo $gradeHtml; ?>
                </ul>
            </div>
        </div>
    </div>
    <input type="hidden" value="group" id="leftlistname">
</div>