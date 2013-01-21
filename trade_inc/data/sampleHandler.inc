<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of sampleHandler
 *
 * @author liukai
 */
class sampleHandler {

    public static function getSamplesListByStatus($status, $start, $listnum) {
        $sql = 'select * from sample where is_delete = 0 and sample_status=:status limit :start,:listnum';
        $paramsLimit[':start'] = $start;
        $paramsLimit[':listnum'] = $listnum;
        $paramsLimit[':status']=$status;
        $result = DB::tradeDB()->allPrepareLimit($sql, array(), $paramsLimit);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function getSamplesSumNumByStatus($status) {
        $sql = 'select count(*) as sum from sample where is_delete = 0 and sample_status=:status';
        $params[':status']=$status;
        $result = DB::tradeDB()->rowPrepare($sql,$params);
        if (!$result->isEmpty()) {
            return $result->data['sum'];
        }
        return 0;
    }

    public static function getSampleById($sampleId) {
        $sql = 'select * from sample where is_delete = 0 and id=:id';
        $paramsLimit[':id']=$sampleId;
        $result = DB::tradeDB()->rowPrepare($sql, $paramsLimit);
        if (!$result->isEmpty()) {
            return $result->data;
        }
        return array();
    }

    public static function insertSample($sampleArr) {
        $valfields = $params = array();
        foreach ($sampleArr as $key => $val) {
            $valfields[] = ":$key";
            $params[":$key"] = $val;
        }
        $sql = 'insert into sample (' . implode(',', array_keys($sampleArr)) . ',create_time)values(' . implode(',', $valfields) . ',now())';
        $result = DB::tradeDB()->insertPrepare($sql, $params);
        if ($result->data > 0) {
            return $result->data;
        }
        return 0;
    }

    public static function updateSampleByID($sampleArr, $sampleid) {
        $temp = '';
        $i = 0;
        foreach ($sampleArr as $key => $value) {
            $i++;
            if ($i != 1) {
                $temp .=',';
            }
            $temp .=$key . "='" . $value . "'";
        }

        $sql = 'update sample set ' . $temp . ' where id=:id';
        $params[':id'] = $sampleid;
        $result = DB::tradeDB()->changePrepare($sql, $params);
        if ($result->data > 0) {
            return $result->data;
        }
        return 0;
    }

    public static function updateSampleWhoSendByID($selectedName, $sampleid) {
        $sql = 'update sample set whosend=:nameid where id=:id';
        $params[':id']=$sampleid;
        $params[':nameid']=$selectedName;
        $result = DB::tradeDB()->rowPrepare($sql,$params);
        if ($result->data > 0) {
            return $result->data;
        }
        return 0;
    }
    
}

?>
