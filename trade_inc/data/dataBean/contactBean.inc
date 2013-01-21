<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of contactBean
 *
 * @author liukai
 */
class contactBean {

    private static $contactArray = array();

    public function __construct() {

        self::$contactArray['contact_name'] = Tools::getValue('custcontactName', '');
        self::$contactArray['contact_email'] = Tools::getValue('custcontactEmail', '');
        self::$contactArray['contact_tel'] = Tools::getValue('custcontactTel', '');
        self::$contactArray['contact_fax'] = Tools::getValue('custcontactFax', '');
        self::$contactArray['contact_msn'] = Tools::getValue('custcontactMSN', '');
        self::$contactArray['contact_phone'] = Tools::getValue('custcontactPhone', '');
        self::$contactArray['contact_skype'] = Tools::getValue('custcontactSkype', '');
        self::$contactArray['contact_other'] = Tools::getValue('custcontactOther', '');
    }

    public function getContactArray() {
        return self::$contactArray;
    }

}

?>
