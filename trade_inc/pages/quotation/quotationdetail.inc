<?php
$page = Tools::getValue("page", "");
$start = 0;
if (!empty($page)) {
    $start = $page * Conf::$numlist;
}
$status = "";
$quotationCodeLists = quotationHandler::getQuotationListByStatus($status,$start, Conf::$numlist);
$allcountnum = sampleHandler::getSamplesSumNumByStatus($status);
$listHtml = '';
foreach ($samplesCodeLists as $value) {
    $customer = customerHandler::getCustomerOnlyById($value['toaddress_customerid']);
    $listHtml.='<tr id="' . $value['id'] . '">';
    $listHtml.='<td>' . $value['sample_code'] . '</td>';
    $listHtml.='<td>' . $value['sample_express_num'] . '</td>';
    $listHtml.='<td>' . $value['sample_status'] . '</td>';
    $listHtml.='<td>' . $customer['customer_name'] . '</td>';
    $listHtml.='<td>' . $value['sample_express_company'] . '</td>';
    $listHtml.='<td>' . $value['sample_express_price_type'] . '</td>';
    $listHtml.='<td>' . $value['sample_express_price'] . '</td>';
    $listHtml.='<td>' . $value['sample_price_rmb'] . '</td>';
    $listHtml.='<td>' . $value['sample_price_usd'] . '</td>';
    $listHtml.='<td>' . userHandler::getUserNameById($value['whosend']) . '</td>';
    $listHtml.='<td>' . $value['sample_to_date'] . '</td>';
    $listHtml.='<td>' . $value['toaddress_country'] . '</td>';
    $listHtml.='<td>' . $value['toaddress_city'] . '</td>';
    $listHtml.='<td>' . $value['toaddress_address'] . '</td>';
    $listHtml.='<td>' . $value['sample_express_status'] . '</td>';
    $listHtml.='</tr>';
}
?>

<div class="listcontentRight">
    <div class="detailRight" style="width: 1190px">
        <table class="sampledetailContent">

            <?php
            echo htmlTemplate::sampleListHTML();
            echo $listHtml;
            ?>
        </table>

    </div>
    <div class="detailPageOptions">
        <div class="bottom" id="bottompaging">
            <?php
            $sumpage = ceil($allcountnum / Conf::$numlist);
            $pageHtml = commonFun::paging(1, $sumpage, count($samplesCodeLists), $allcountnum, "getsample" . $status); //第一次进来都是第一页1
            echo $pageHtml;
            ?>
        </div>
        <input type="hidden" value="" id="selectedID">
        <input type="hidden" value="" id="pageoptions">
        <input type="hidden" value="" id="thisid">
    </div>
</div>
<div class="contextMenu" id="sampleListRightMenu">
    <ul>
        <li id="add"><img src="../../images/button/plus.png" width="14px" height="14px">新建样品</li>
        <li id="edit"><img src="../../images/button/pencil_edit.png" width="14px" height="14px">修改样品</li>
        <li id="check"><img src="../../images/button/comment.png" width="14px" height="14px">查看样品</li>
        <li id="delete"><img src="../../images/button/close_delete.png" width="14px" height="14px">删除样品</li>
        <li id="shareforortherpeople"><img src="../../images/button/friends_group.png" width="14px" height="14px">分配样品</li>
    </ul>
</div>