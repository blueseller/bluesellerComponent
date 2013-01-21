<?php

class popContentSelect {

    private static $who = "";
    private static $includePageName = "";

    public static function init() {
        self::$who = Tools::getValue("who", "");
        self::$includePageName = self::getIncludePageName(self::$who);
        return self::$includePageName;
    }

    private static function getIncludePageName($to) {
        $return = "trade_inc/pages/";
        switch ($to) {
            case "popview":
                $return .="notices/popview.inc";
                break;
            case "addnotice":
                $return .="notices/addnotice.inc";
                break;
            case "morenotice":
                $return .="notices/morenotice.inc";
                break;
            case "addshare":
                $return .="workshare/addshare.inc";
                break;
            case "moreshare":
                $return .="workshare/moreshare.inc";
                break;
            case "addcustomer":
                $return .="customer/addCustomer.inc";
                break;
            case "checkCustomer":
                $return .="customer/checkCustomer.inc";
                break;
            case "addCustGroup":
                $return .="customer/addCustGroup.inc";
                break;
            case "checkContact":
                $return .="customer/checkContact.inc";
                break;
            case "addsupplier":
                $return .="supplier/addsupplier.inc";
                break;
            case "checkSupplier":
                $return .="supplier/checksupplier.inc";
                break;
            case "checkSupplierContacter":
                $return .="supplier/checkSupplierContacter.inc";
                break;
            case "tocustGroup":
                $return .="customer/tocustGroup.inc";
                break;
            case "editcustGroup":
                $return .="customer/editcustGroup.inc";
                break;
            case 'addContacter':
                $return .="customer/addContacter.inc";
                break;
            case 'addRemind':
                $return .="customer/addRemind.inc";
                break;
            case 'checkRemind':
                $return .="customer/checkRemind.inc";
                break;
            case 'addsuppliercontact':
                $return .="supplier/addsuppliercontact.inc";
                break;
            case "addproduct":
                $return .="products/addproduct.inc";
                break;
            case "checkproduct":
                $return .="products/checkproduct.inc";
                break;
            case "addsample":
                $return .="sample/addsample.inc";
                break;
            case "checksample":
                $return .="sample/checksample.inc";
                break;
            case "sharesample":
                $return .="sample/sharesample.inc";
                break;
            default:
                $return = "";
                break;
        }
        return $return;
    }

}

?>
