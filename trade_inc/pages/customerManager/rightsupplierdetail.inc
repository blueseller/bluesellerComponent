<?php
$customerLists = requestCustomer::$customers;
$allcountnum = requestCustomer::$allcount;
$grades = configHandler::getConfigValueByKey('customer_grade_images');
$grades = explode("|", $grades['config_value']);
$listHtml = '';
foreach ($customerLists as $value) {
    $listHtml.='<tr id="' . $value['id'] . '" class="' . $value['supplier_name'] . '">';
    $listHtml.='<td>' . $value['supplier_id'] . '</td>';
    $listHtml.='<td>' . $value['supplier_name'] . '</td>';
    $listHtml.='<td>' . $value['supplier_addr'] . '</td>';
    $listHtml.='<td>' . $value['supplier_contact_name'] . '</td>';
    $listHtml.='<td>' . $value['supplier_contact_email'] . '</td>';
    $listHtml.='<td>' . $value['supplier_contact_tel'] . '</td>';
    $listHtml.='<td>' . $value['supplier_contact_phone'] . '</td>';
    $listHtml.='<td>' . $grades[$value['supplier_grade'] - 1] . '</td>';
    $listHtml.='<td>' . customerGroupHandler::getGroupNameById($value['supplier_group']) . '</td>';
    $listHtml.='</tr>';
}
?>

<div class="listcontentRight">
    <div class="detailRight">
        <table class="suppliers">
            <tr>
                <th width="80px;">供应商编码</th>
                <th width="200px;">供应商名称</th>
                <th width="200px;">供应商地址</th>
                <th width="100px;">主联系人</th>
                <th width="180px;">电子邮件</th>
                <th width="100px;">电话</th>
                <th width="100px;">手机</th>
                <th width="100px;">等级</th>
                <th width="100px;">所属分组</th>
            </tr>
            <?php echo $listHtml; ?>
        </table>

    </div>
    <div class="detailPageOptions">
        <div class="bottom" id="bottompaging">
            <?php
            $sumpage = ceil($allcountnum / Conf::$numlist);
            $pageHtml = commonFun::paging(1, $sumpage, count($customerLists), $allcountnum,"getsupplier"); //第一次进来都是第一页1
            echo $pageHtml;
            ?>
        </div>
        <input type="hidden" value="" id="selectedID">
        <input type="hidden" value="" id="pageoptions">
        <input type="hidden" value="" id="thisid">
    </div>
</div>
<div class="contextMenu" id="supplierRightMenu">
    <ul>
        <li id="checksupplier"><img src="../../images/button/comment.png" width="14px" height="14px">查看供应商</li>
        <li id="addsupplier"><img src="../../images/button/plus.png" width="14px" height="14px">新建供应商</li>
        <li id="editsupplier"><img src="../../images/button/pencil_edit.png" width="14px" height="14px">修改供应商</li>
        <li id="deletesupplier"><img src="../../images/button/close_delete.png" width="14px" height="14px">删除供应商</li>
        <li id="addSupplierContacter"><img src="../../images/button/plus.png" width="14px" height="14px">新建联系人</li>
    </ul>
</div>