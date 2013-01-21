<?php

class popCharStaticSelect {

    private static $who = "";
    private static $script = "";
    private static $tableMonths = "";
    private static $tablestaticNums = "";
    private static $title = "";
    private static $statistical_units = "";
    private static $char_units = "";

    public static function init() {
        self::$who = Tools::getValue("who", "");
        self::getCharDatesByWho(self::$who);
        $static_datas = companyStaticMonthHandler::getStaricConfigByName("static_".self::$who);
        self::getScriptHtml($static_datas);
        $returns = array();
        $returns['script'] = self::$script;
        $returns['tableMonths'] = self::$tableMonths;
        $returns['tablestaticNums'] = self::$tablestaticNums;
        $returns['title'] = self::$title;
        $returns['statistical_units'] = self::$statistical_units;
        return $returns;
    }

    private static function getCharDatesByWho($to) {
        $return = staticConfigeHandler::getStaricConfigByName($to);
        self::$title = $return['static_confige_title'];
        self::$statistical_units = $return['static_confige_statistical_units'];
        self::$char_units = $return['static_confige_char_units'];
    }
    
    private static function getScriptHtml($static_datas){
        self::$script = '<script type="text/javascript">';
        self::$script.='var chartitle =\' '.self::$title."';";
        self::$script.='var yAxis={title: {text: \''.self::$title."'}};";
        $categories = "[";
        $series = "[";
        $sum = 0;
        foreach ($static_datas as $key => $value) {
            $sum+=$value['staticnum'];
            $series.=$value['staticnum'];
            $categories.='\''.Conf::$months[$value['month']].'\'';
            if($key != count($static_datas)-1){
                $categories.=',';
                $series.=',';
            }
            self::$tableMonths.="<td>".$value['year']." ".Conf::$months[$value['month']]."</td>";
            self::$tablestaticNums.="<td>".$value['staticnum']."</td>";
        }
        self::$script.='var xAxis ={categories: '.$categories."],title: {text: '月份'}};";
        self::$script.='var series=[{ name: \''.self::$char_units.'\',data:'.$series."]}];";
        self::$script.='</script>';
        self::$tablestaticNums.="<td>".$sum."</td>";
    }

}

?>
