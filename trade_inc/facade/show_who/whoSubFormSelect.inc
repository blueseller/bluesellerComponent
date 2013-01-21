<?php

class whoSubFormSelect {

    public static $returnMsg = '';

    public static function insertCustomer($who) {

        $flag = configHandler::getConfigValueByKey($who);
        self::addcustomer($flag);
        return self::$returnMsg;
    }

    public static function editorCustomer($customerid, $contactid) {
        self::updateCustomer($customerid, $contactid);
        return self::$returnMsg;
    }

    private static function addcustomer($config) {
        $customerbean = array();
        $contactbean = array();

        $newcustomer = new customerBean();
        $newcontact = new contactBean();

        $customerbean = $newcustomer->getCustomerArray();
        $contactbean = $newcontact->getContactArray();
        $contactbean['contact_flag'] = $config['id'];
        $insertId = contactHandler::contactInsert($contactbean);
        $customerbean['customer_first_contacter'] = $insertId;
        $customerbean['customer_whohave'] = $_COOKIE['userId'];
        $return = customerHandler::customerInsert($customerbean);
        if ($return > 0) {
            self::$returnMsg = 'success';
        }
    }

    private static function updateCustomer($id, $contactid) {
        $customerbean = array();
        $contactbean = array();

        $newcustomer = new customerBean();
        $newcontact = new contactBean();

        $customerbean = $newcustomer->getCustomerArray();
        $return = customerHandler::customerUpdate($id, $customerbean);
        if ($return > 0) {
            $contactbean = $newcontact->getContactArray();
            $return = contactHandler::updateContacterContentById($contactid, $contactbean);
            if ($return > 0) {
                self::$returnMsg = 'success';
            }
        }
    }

    public static function editorCustomerGroup($groupid) {
        $content = array();
        $content['customer_group_name'] = Tools::getValue('custgroupname', '');
        $content['customer_group_detial'] = Tools::getValue('custgroupdetail', '');
        $content['group_category'] = Tools::getValue('catetype', '');
        if (empty($groupid)) {
            $return = customerGroupHandler::customerGroupInsert($content);
        } else {
            $return = customerGroupHandler::customerGroupUpdate($groupid, $content);
        }
        if ($return > 0) {
            self::$returnMsg = 'success';
        }
        return self::$returnMsg;
    }

    public static function addNoticeContent() {
        $contentArr = array();
        $contentArr['customer_category'] = Tools::getValue('noticecategory', '');
        $contentArr['notice_title'] = Tools::getValue('addnoticetitle', '');
        $contentArr['notice_content'] = Tools::getValue('addnoticeContent', '');
        $contentArr['editor_people'] = $_COOKIE['userId'];
        $return = companyNoticeHandler::insertNotice($contentArr);
        if ($return > 0) {
            self::$returnMsg = 'success';
        }
        return self::$returnMsg;
    }

    public static function addSupplier() {
        $supplier = array();
        $supplier = new supplierBean();
        $supplier = $supplier->getSupplierArray();
        $supplier["supplier_permission"] = $_COOKIE['userId'];
        $return = supplierHandler::supplierInsert($supplier);
        if ($return > 0) {
            self::$returnMsg = 'success';
        }
        return self::$returnMsg;
    }

    public static function shareCustomer() {
        $customerid = Tools::getValue('customerid', '');
        $userid = Tools::getValue('selectedWho', '');
        $return = contactHandler::updateCustomerUserId($customerid, $userid);
        if ($return > 0) {
            self::$returnMsg = 'success';
        }
        return self::$returnMsg;
    }

    public static function shareCustomerGroup() {
        $customerid = Tools::getValue('customerid', '');
        $groupid = Tools::getValue('selectedWho', '');
        $return = contactHandler::updateCustomerGroupId($customerid, $groupid);
        if ($return > 0) {
            self::$returnMsg = 'success';
        }
        return self::$returnMsg;
    }

    public static function addRemind() {
        $remindArr = array();
        $remindArr['remind_title'] = Tools::getValue('remindtitle', '');
        $remindArr['remind_start_time'] = Tools::getValue('starttime', '');
        if (empty($remindArr['remind_start_time'])) {
            $remindArr['remind_start_time'] = date("Y-m-d H:i:s");
        }
        $remindArr['remind_end_time'] = Tools::getValue('endtime', '');
        if (empty($remindArr['remind_end_time'])) {
            $remindArr['remind_end_time'] = date("Y-m-d H:i:s", mktime(0, 0, 0, 12, 28, 2085));
        }
        $remindArr['remind_content'] = Tools::getValue('remindcontent', '');
        $remindArr['userid'] = $_COOKIE['userId'];
        $remindid = remindsHandler::insertRemind($remindArr);

        if ($remindid > 0) {
            $customerid = Tools::getValue('customerid', '');
            $return = customerHandler::updateRemindIdByCustomerId($remindid, $customerid);
            if ($return > 0) {
                self::$returnMsg = 'success';
            }
        }
        return self::$returnMsg;
    }

    public static function updateRemind() {
        $remindArr = array();
        $remindArr['remind_title'] = Tools::getValue('remindtitle', '');
        $remindArr['remind_start_time'] = Tools::getValue('starttime', '');
        if (empty($remindArr['remind_start_time'])) {
            $remindArr['remind_start_time'] = date("Y-m-d H:i:s");
        }
        $remindArr['remind_end_time'] = Tools::getValue('endtime', '');
        if (empty($remindArr['remind_end_time'])) {
            $remindArr['remind_end_time'] = date("Y-m-d H:i:s", mktime(0, 0, 0, 12, 28, 2085));
        }
        $remindArr['remind_content'] = Tools::getValue('remindcontent', '');
        $remindid = Tools::getValue('remindId', '');
        $return = remindsHandler::updateRemindByid($remindArr, $remindid);
        if ($return > 0) {
            self::$returnMsg = 'success';
        }
        return self::$returnMsg;
    }

    public static function addProduct() {
        $productArr = $productpriceArr = array();
        $productArr = new productBean();
        $productpriceArr = new productPriceBean();
        $productArr = $productArr->getProductArray();
        $productpriceArr = $productpriceArr->getProductPriceArray();
        $insertId = productHandler::insertProductPrice($productpriceArr);
        $productArr['product_price_id'] = $insertId;
        $return = productHandler::insertProductContent($productArr);
        if ($return > 0) {
            self::$returnMsg = 'success';
        }
        return self::$returnMsg;
    }

    public static function updateProduct() {
        $productid = Tools::getValue('productid', '');
        $priceid = Tools::getValue('price_productid', '');
        $productArr = $productpriceArr = array();
        $productArr = new productBean();
        $productpriceArr = new productPriceBean();
        $productArr = $productArr->getProductArray();
        $productpriceArr = $productpriceArr->getProductPriceArray();
        $return = productHandler::updateProductPrice($productpriceArr,$priceid);
        if ($return > 0) {
            self::$returnMsg = 'success';
            $return = productHandler::updateProductContent($productArr,$productid);
            if ($return < 0) {
                self::$returnMsg = '';
            }
        }
        return self::$returnMsg;
    }

    public static function addSample() {
        $sampleArr = new sampleBean();
        $sampleArr = $sampleArr->getSampleArray();
        $sampleArr["whosend"] = $_COOKIE['userId'];
        $return = sampleHandler::insertSample($sampleArr);
        if ($return > 0) {
            self::$returnMsg = 'success';
        }
        return self::$returnMsg;
    }

    public static function updateSample() {
        $sampleid = Tools::getValue('sampleid', '');
        $sampleArr = new sampleBean();
        $sampleArr = $sampleArr->getSampleArray();
        $sampleArr["whosend"] = $_COOKIE['userId'];
        $return = sampleHandler::updateSampleByID($sampleArr,$sampleid);
        if ($return > 0) {
            self::$returnMsg = 'success';
        }
        return self::$returnMsg;
    }

    public static function shareSample() {
        $sampleid = Tools::getValue('sampleid', '');
        $selectedName = Tools::getValue('selectedName', '');
        $return = sampleHandler::updateSampleWhoSendByID($selectedName,$sampleid);
        if ($return > 0) {
            self::$returnMsg = 'success';
        }
        return self::$returnMsg;
    }

}

?>
