
<?php

if (!defined("ROOT"))
    define("ROOT", dirname(__FILE__));
include(ROOT . "/../trade_inc/lib/phpexcel.inc");
include(ROOT . "/../trade_inc/conf.inc");
include(ROOT . "/../trade_inc/lib/tools.inc");
include(ROOT . "/../trade_inc/lib/myPDO.inc");
include(ROOT . "/../trade_inc/data/db.inc");

$deletesql = 'delete from customs_code';
$result = DB::tradeDB()->rowPrepare($deletesql);
$xl_reader = new Spreadsheet_Excel_Reader ( );
$xl_reader->setOutputEncoding('UTF-8');
$xl_reader->read(ROOT . "/../trade_inc/lib/2012.xls");
$codesArray = $xl_reader->sheets[0]["cells"];
foreach ($codesArray as $key => $value) {
    if (!isset($value['3'])){
        $value['3']="";
    }
    if (!isset($value['5'])){
        $value['5']="";
    }
    if (!isset($value['9'])){
        $value['9']="";
    }
    $sql = 'insert into customs_code 
    (customs_code_id,customs_code_name,customs_code_mark,customs_code_unit1,customs_code_unit2,customs_code_benefit_tax,customs_code_general_tax,customs_code_value_added_tax,customs_code_regulatory_conditions,customs_code_commodity_inspection) 
    values (\'' . $value['1'] . '\',\'' . $value['2'] . '\',\'' . $value['3'] . '\',\'' . $value['4'] . '\',\'' . $value['5'] . '\',\'' . $value['6'] . '\',\'' . $value['7'] . '\',\'' . $value['8'] . '\',\'' . $value['9'] . '\',\'' . $value['10'] . '\')';
    $result = DB::tradeDB()->rowPrepare($sql);
}
?>

