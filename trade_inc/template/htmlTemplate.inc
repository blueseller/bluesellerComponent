<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of htmlTemplate
 *
 * @author liukai
 */
class htmlTemplate {

    public static function contactShowHtml() {
        $html = '<table class="checktable" id="{id}">
        <tr>
            <td class="doublename">主联系人:</td>
            <td class="doubleinput"><label>{contact_name}</label></td>
            <td class="doublename">传真:</td>
            <td class="doubleinput"><label>{contact_fax}</label></td>
        </tr>
        <tr>
            <td class="doublename">电话:</td>
            <td class="doubleinput"><label>{contact_tel}</label></td>
            <td class="doublename">手机:</td>
            <td class="doubleinput"><label>{contact_phone}</label></td>
        </tr>
        <tr>
            <td class="doublename">MSN:</td>
            <td class="doubleinput"><label>{contact_msn}</label></td>
            <td class="doublename">电子邮件:</td>
            <td class="doubleinput"><label>{contact_email}</label></td>
        </tr> 
        <tr>
            <td class="doublename">Skype:</td>
            <td class="doubleinput"><label>{contact_skype}</label></td>
            <td class="doublename">其他:</td>
            <td class="doubleinput"><label>{contact_other}</label></td>
        </tr>
        <tr>
            <td class="doublename" colspan=2 style="text-align:left">是否升级为主联系人：<input value="变为主联系人" type="button" onclick="changeToMainContact(\'{id}\',\'{customer_id}\')"><input value="删除此联系人" type="button" onclick="deleteContact(\'{contact_id}\')"></td>
            <td class="doublename" colspan=2 style="text-align:left">修改联系信息：<input value="修改联系信息" type="button" onclick="changeContactContent(\'{id}\',\'{contact_id}\',\'customer\')" class="{hidden}" id="changecontact"><input value="保存联系信息" id="savecontact" class="hidden" type="button" onclick="saveContactContent(\'{id}\',\'{contact_id}\')"></td>
        </tr> 
    </table>';
        return $html;
    }

    public static function supplierContactShowHtml() {
        $html = '<table class="checktable" id="{id}">
        <tr>
            <td class="doublename">主联系人:</td>
            <td class="doubleinput"><label>{contact_name}</label></td>
            <td class="doublename">传真:</td>
            <td class="doubleinput"><label>{contact_fax}</label></td>
        </tr>
        <tr>
            <td class="doublename">电话:</td>
            <td class="doubleinput"><label>{contact_tel}</label></td>
            <td class="doublename">手机:</td>
            <td class="doubleinput"><label>{contact_phone}</label></td>
        </tr>
        <tr>
            <td class="doublename">电子邮件:</td>
            <td class="doubleinput"><label>{contact_email}</label></td>
            <td class="doublename">其它:</td>
            <td class="doubleinput"><label>{contact_other}</label></td>
        </tr> 
        <tr>
            <td class="doublename" colspan=2 style="text-align:left">是否删除此联系人：<input value="删除此联系人" type="button" onclick="deleteContact(\'{contact_id}\')"></td>
            <td class="doublename" colspan=2 style="text-align:left">修改联系信息：<input value="修改联系信息" type="button" onclick="changeContactContent(\'{id}\',\'{contact_id}\',\'supplier\')" class="{hidden}" id="changecontact"><input value="保存联系信息" id="savecontact" class="hidden" type="button" onclick="saveContactContent(\'{id}\',\'{contact_id}\')"></td>
        </tr>
        
    </table>';
        return $html;
    }

    public static function customerlistHTML() {
        $html = '<tr>
                <th width="80px;">客户编码</th>
                <th width="50px;">提醒</th>
                <th width="200px;">客户名称</th>
                <th width="100px;">主联系人</th>
                <th width="180px;">电子邮件</th>
                <th width="100px;">电话</th>
                <th width="100px;">国家</th>
                <th width="100px;">地区</th>
                <th width="100px;">拥有者</th>
                <th width="170px;">最近联系时间</th>
                <th width="100px;">客户来源</th>
                <th width="120px;">传真</th>
                <th width="300px;">关注产品</th>
            </tr>';
        return $html;
    }

    public static function supplierListHTML() {
        $html = '<tr>
                <th width="80px;">供应商编码</th>
                <th width="200px;">供应商名称</th>
                <th width="200px;">供应商地址</th>
                <th width="100px;">主联系人</th>
                <th width="180px;">电子邮件</th>
                <th width="100px;">电话</th>
                <th width="100px;">手机</th>
                <th width="100px;">等级</th>
                <th width="100px;">所属分组</th>
            </tr>';
        return $html;
    }

    public static function productListHTML() {
        $html = '<tr>
                <th width="80px;">产品编码</th>
                <th width="80px;">公司货号</th>
                <th width="150px;">产品中文名</th>
                <th width="150px;">产品英文名</th>
                <th width="100px;">所属分组</th>
                <th width="100px;">中文型号</th>
                <th width="100px;">中文规格</th>
                <th width="100px;">英文型号</th>
                <th width="100px;">英文规格</th>
                <th width="100px;">进价(人民币)</th>
                <th width="120px;">指导价格(人民币)</th>
                <th width="170px;">创建日期</th>
            </tr>';
        return $html;
    }

    public static function customercodeListHTML() {
        $html = '<tr>
                <th width="80px;">海关编码</th>
                <th width="250px;">海关商品名称</th>
                <th width="200px;">海关商品备注</th>
                <th width="80px;">法定单位一</th>
                <th width="80px;">法定单位二</th>
                <th width="80px;">惠税</th>
                <th width="90px;">普税</th>
                <th width="100px;">增值税</th>
                <th width="100px;">监管条件</th>
                <th width="100px;">商检标志</th>
            </tr>';
        return $html;
    }

    public static function sampleListHTML() {
        $html = '<tr>
                <th width="80px;">样品单号</th>
                <th width="80px;">快件单号</th>
                <th width="150px;">寄入or寄出</th>
                <th width="150px;">客户名称</th>
                <th width="100px;">快递公司</th>
                <th width="100px;">付费方式</th>
                <th width="100px;">运费(人民币)</th>
                <th width="100px;">样品费(人民币)</th>
                <th width="100px;">样品费(美元)</th>
                <th width="100px;">寄样人</th>
                <th width="100px;">寄样日期</th>
                <th width="100px;">寄件国家</th>
                <th width="100px;">寄件城市</th>
                <th width="100px;">寄件地址</th>
                <th width="100px;">寄件状态</th>
            </tr>';
        return $html;
    }

}

?>
