<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of supplierBean
 *
 * @author liukai
 */
class supplierBean {

    private static $supplierArray = array();

    public function __construct() {

        self::$supplierArray['supplier_id'] = Tools::getValue('supplierCode', '');
        self::$supplierArray['supplier_name'] = Tools::getValue('supplierName', '');
        self::$supplierArray['supplier_group'] = Tools::getValue('suppliergroup', '');
        self::$supplierArray['supplier_contact_name'] = Tools::getValue('supplierContactName', '');
        self::$supplierArray['supplier_contact_tel'] = Tools::getValue('supplierContactTel', '');
        self::$supplierArray['supplier_contact_phone'] = Tools::getValue('supplierContactPhone', '');
        self::$supplierArray['supplier_contact_email'] = Tools::getValue('supplierContactEmail', '');
        self::$supplierArray['supplier_contact_fax'] = Tools::getValue('supplierContactFax', '');
        self::$supplierArray['supplier_contact_postal'] = Tools::getValue('supplierContactpostal', '');
        self::$supplierArray['supplier_contact_other'] = Tools::getValue('supplierContactOther', '');
        self::$supplierArray['supplier_products'] = Tools::getValue('products', '');
        self::$supplierArray['supplier_addr'] = Tools::getValue('address', '');
        self::$supplierArray['supplier_bank_name'] = Tools::getValue('bankname', '');
        self::$supplierArray['supplier_bank_username'] = Tools::getValue('openbankname', '');
        self::$supplierArray['supplier_bank_num'] = Tools::getValue('banknum', '');
        self::$supplierArray['supplier_company_representative'] = Tools::getValue('companyRepresentative', '');
        self::$supplierArray['supplier_company_taxnum'] = Tools::getValue('companyTaxnum', '');
        self::$supplierArray['supplier_grade'] = Tools::getValue('suppliergrade', '');
        self::$supplierArray['supplier_remind'] = Tools::getValue('supplierRemind', '');
    }

    public function getSupplierArray() {
        return self::$supplierArray;
    }

    public static function setSupplierData($param) {
        $supplier = array();
        $supplier['supplier_id'] = isset($param['supplier_id']) ? $param['supplier_id'] : '';
        $supplier['supplier_name'] = isset($param['supplier_name']) ? $param['supplier_name'] : '';
        $supplier['supplier_addr'] = isset($param['supplier_addr']) ? $param['supplier_addr'] : '';
        $supplier['supplier_group'] = isset($param['supplier_group']) ? $param['supplier_group'] : '';
        $supplier['supplier_grade'] = isset($param['supplier_grade']) ? $param['supplier_grade'] : '';
        $supplier['supplier_contact_name'] = isset($param['supplier_contact_name']) ? $param['supplier_contact_name'] : '';
        $supplier['supplier_contact_tel'] = isset($param['supplier_contact_tel']) ? $param['supplier_contact_tel'] : '';
        $supplier['supplier_contact_phone'] = isset($param['supplier_contact_phone']) ? $param['supplier_contact_phone'] : '';
        $supplier['supplier_contact_postal'] = isset($param['supplier_contact_postal']) ? $param['supplier_contact_postal'] : '';
        $supplier['supplier_contact_email'] = isset($param['supplier_contact_email']) ? $param['supplier_contact_email'] : '';
        $supplier['supplier_contact_fax'] = isset($param['supplier_contact_fax']) ? $param['supplier_contact_fax'] : '';
        $supplier['supplier_bank_name'] = isset($param['supplier_bank_name']) ? $param['supplier_bank_name'] : '';
        $supplier['supplier_bank_username'] = isset($param['supplier_bank_username']) ? $param['supplier_bank_username'] : '';
        $supplier['supplier_bank_num'] = isset($param['supplier_bank_num']) ? $param['supplier_bank_num'] : '';
        $supplier['supplier_company_representative'] = isset($param['supplier_company_representative']) ? $param['supplier_company_representative'] : '';
        $supplier['supplier_company_taxnum'] = isset($param['supplier_company_taxnum']) ? $param['supplier_company_taxnum'] : '';
        $supplier['supplier_remind'] = isset($param['supplier_remind']) ? $param['supplier_remind'] : '';
        $supplier['supplier_products'] = isset($param['supplier_products']) ? $param['supplier_products'] : '';
        $supplier['supplier_contact_other'] = isset($param['supplier_contact_other']) ? $param['supplier_contact_other'] : '';
        return $supplier;
    }

}

?>
