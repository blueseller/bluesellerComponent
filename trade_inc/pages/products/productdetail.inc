<?php
$page = Tools::getValue("page", "");
$start = 0;
if (!empty($page)) {
    $start = $page * Conf::$numlist;
}
$productLists = productHandler::getProducts($start,Conf::$numlist);
$allcountnum = productHandler::getProductsSunNum();
$listHtml = '';
foreach ($productLists as $value) {
    $listHtml.='<tr id="' . $value['id'] . '" class="">';
    $listHtml.='<td>' . $value['product_id'] . '</td>';
    $listHtml.='<td>' . $value['company_productcode'] . '</td>';
    $listHtml.='<td>' . $value['product_chinaname'] . '</td>';
    $listHtml.='<td>' . $value['product_englishname'] . '</td>';
    $listHtml.='<td>' . customerGroupHandler::getGroupNameById($value['product_group']) . '</td>';
    $listHtml.='<td>' . $value['product_model_cn'] . '</td>';
    $listHtml.='<td>' . $value['product_format_cn'] . '</td>';
    $listHtml.='<td>' . $value['product_model_en'] . '</td>';
    $listHtml.='<td>' . $value['product_format_en'] . '</td>';
    $listHtml.='<td>' . $value['price_cost_cn'] . '</td>';
    $listHtml.='<td>' . $value['price_sale_cn'] . '</td>';
    $listHtml.='<td>' . $value['create_time'] . '</td>';
    $listHtml.='</tr>';
}
?>

<div class="listcontentRight">
    <div class="detailRight">
        <table class="productdetailContent">

            <?php
            echo htmlTemplate::productListHTML();
            echo $listHtml;
            ?>
        </table>

    </div>
    <div class="detailPageOptions">
        <div class="bottom" id="bottompaging">
            <?php
            $sumpage = ceil($allcountnum / Conf::$numlist);
            $pageHtml = commonFun::paging(1, $sumpage, count($productLists), $allcountnum,"getproduct"); //第一次进来都是第一页1
            echo $pageHtml;
            ?>
        </div>
        <input type="hidden" value="" id="selectedID">
        <input type="hidden" value="" id="pageoptions">
        <input type="hidden" value="" id="thisid">
    </div>
</div>
<div class="contextMenu" id="productListRightMenu">
    <ul>
        <li id="add"><img src="../../images/button/plus.png" width="14px" height="14px">新建产品</li>
        <li id="edit"><img src="../../images/button/pencil_edit.png" width="14px" height="14px">修改产品</li>
        <li id="check"><img src="../../images/button/comment.png" width="14px" height="14px">查看产品</li>
        <li id="delete"><img src="../../images/button/close_delete.png" width="14px" height="14px">删除产品</li>
    </ul>
</div>