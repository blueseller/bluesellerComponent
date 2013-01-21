<?php
$page = Tools::getValue("page", "");
$start = 0;
if (!empty($page)) {
    $start = $page * Conf::$numlist;
}
$customsCodeLists = customsCodeHandler::getCustomsCodeList($start,Conf::$numlist);
$allcountnum = customsCodeHandler::getCustomsCodeSumNum();
$listHtml = '';
foreach ($customsCodeLists as $value) {
    $listHtml.='<tr>';
    $listHtml.='<td>' . $value['customs_code_id'] . '</td>';
    $listHtml.='<td>' . $value['customs_code_name'] . '</td>';
    $listHtml.='<td>' . $value['customs_code_mark'] . '</td>';
    $listHtml.='<td>' . $value['customs_code_unit1'] . '</td>';
    $listHtml.='<td>' . $value['customs_code_unit2'] . '</td>';
    $listHtml.='<td>' . $value['customs_code_benefit_tax'] . '</td>';
    $listHtml.='<td>' . $value['customs_code_general_tax'] . '</td>';
    $listHtml.='<td>' . $value['customs_code_value_added_tax'] . '</td>';
    $listHtml.='<td>' . $value['customs_code_regulatory_conditions'] . '</td>';
    $listHtml.='<td>' . $value['customs_code_commodity_inspection'] . '</td>';
    $listHtml.='</tr>';
}
?>

<div class="listcontentRight">
    <div class="detailRight" style="width: 1190px">
        <table class="detailContent">

            <?php
            echo htmlTemplate::customercodeListHTML();
            echo $listHtml;
            ?>
        </table>

    </div>
    <div class="detailPageOptions">
        <div class="bottom" id="bottompaging">
            <?php
            $sumpage = ceil($allcountnum / Conf::$numlist);
            $pageHtml = commonFun::paging(1, $sumpage, count($customsCodeLists), $allcountnum,"getcustomscode"); //第一次进来都是第一页1
            echo $pageHtml;
            ?>
        </div>
        <input type="hidden" value="" id="selectedID">
        <input type="hidden" value="" id="pageoptions">
        <input type="hidden" value="" id="thisid">
    </div>
</div>