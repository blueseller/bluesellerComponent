<?php
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of paging
 *
 * @author liukai
 */
class commonFun {

    //分页
    public static function paging($nowpage, $sumpage, $nowlists, $sumlists,$who) {
        $html = '';
        $html .= '<span>当前显示 '.$nowpage.'-' . $nowlists . ' 条， 共' . $sumlists . '条 </span><span><input type="hidden" id="pagemaxnum" value="'.$sumpage.'"><input type="hidden" id="pagetowho" value="'.$who.'">';
        if ($nowpage == 1) {
            $html .='<a href="javascript:void(0)"><img src="../../images/button/top.png" width="18px" height="18px"></a><a href="javascript:void(0)"><img src="../../images/button/preview.png" width="18px" height="18px"></a>';
        } else {
            $html .='<a href="javascript:void(0)" onclick="pagechange(\'1\',\''.$who.'\')"><img src="../../images/button/top.png" width="18px" height="18px"></a><a href="javascript:void(0)" onclick="pagechange(\'' . ($nowpage - 1) . '\',\''.$who.'\')"><img src="../../images/button/preview.png" width="18px" height="18px"></a>';
        }
        $html .=' | 第 <input type="text" value="" id="inputpagenum" style="width: 20px;height: 15px;"> 页 共'.$sumpage.'页 | <input type="button" id="pagegoto" value="确定"> ';
        if ($nowpage == $sumpage || $sumpage==0) {
            $html .='<a href="javascript:void(0)"><img src="../../images/button/next.png" width="18px" height="18px"></a> <a href="javascript:void(0)"><img src="../../images/button/end.png" width="18px" height="18px"></a>';
        } else {
            $html .='<a href="javascript:void(0)" onclick="pagechange(\'' . ($nowpage + 1) . '\',\''.$who.'\')"><img src="../../images/button/next.png" width="18px" height="18px"></a> <a href="javascript:void(0)" onclick="pagechange(\''.$sumpage.'\',\''.$who.'\')"><img src="../../images/button/end.png" width="18px" height="18px"></a>';
        }
        return $html;
    }

}
?>
