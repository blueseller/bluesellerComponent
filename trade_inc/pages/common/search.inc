<!--/**
 * Description of seatch
 *
 * @author liukai
 */-->
<div class="search">
    <span class="searchlogo"><img src="images/button/search_lense.png"></span>
    <span class="seachCate">
        <select>
            <option>产品编码</option>
            <option>产品中文名</option>
            <option>产品英文名</option>
            <option>英文型号</option>
            <option>英文规格</option>
            <option>所属分组</option>
            <option>创建日期</option>
        </select>
    </span>
    <span class="searchInput"><input type="text" value="" class="searchkey" id="searchkey"></span>
    <span><input type="button" value="立即搜索" class="searchButton" id="searchButton"></span>
    <span class="highsearchLink"><a href="javascript:void(0)" class="tohighsearch">切换到高级搜索</a></span>
</div>
<div class="highsearch hidden">
    <table class="searchAllTips">
        <tr>
            <td>客户编码：<input type="text" value=""></td>
            <td>客户名称：<input type="text" value=""></td>
            <td>主联系人：<input type="text" value=""></td>
            <td>电子邮件：<input type="text" value=""></td>
            <td><a href="javascript:void(0)" class="tobasesearch">切换至普通搜索</a></td>
        </tr>
        <tr>
            <td>国家或地域：<input type="text" value=""></td>
            <td>电话：<input type="text" value=""></td>
            <td>最近联系时间：<input type="text" value=""></td>
            <td>至：&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="text" value=""></td>
            <td><input type="button" value="立即搜索" class="searchButton" style="width: 80px;"><input type="button" value="清除" class="clearButton" style="width: 50px;margin-left: 10px;"></td>
        </tr>
    </table>

</div>