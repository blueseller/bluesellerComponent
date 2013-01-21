/*
SQLyog Enterprise - MySQL GUI v7.02 
MySQL - 5.0.77 : Database - trade
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

USE `trade`;

/*Table structure for table `company_notice` */

CREATE TABLE `company_notice` (
  `id` bigint(20) NOT NULL auto_increment,
  `notice_title` varchar(100) NOT NULL,
  `notice_content` text,
  `customer_category` varchar(100) NOT NULL,
  `is_delete` int(1) NOT NULL default '0',
  `editor_people` int(11) NOT NULL,
  `creat_time` datetime NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=33 DEFAULT CHARSET=utf8;

/*Data for the table `company_notice` */

insert  into `company_notice`(`id`,`notice_title`,`notice_content`,`customer_category`,`is_delete`,`editor_people`,`creat_time`) values (4,'','','',0,1,'2012-12-25 12:30:16'),(5,'','','',0,1,'2012-12-25 12:30:40'),(6,'','','',0,1,'2012-12-25 12:31:01'),(7,'','','',0,1,'2012-12-25 12:31:04'),(8,'','','',0,1,'2012-12-25 12:31:29'),(9,'','','',0,1,'2012-12-25 12:32:52'),(10,'','','',0,1,'2012-12-25 12:32:56'),(11,'','','通知',0,1,'2012-12-25 12:35:10'),(12,'','','通知',0,1,'2012-12-25 12:35:13'),(13,'','','通知',0,1,'2012-12-25 12:35:15'),(14,'','','通知',0,1,'2012-12-25 13:04:12'),(15,'','','通知',0,1,'2012-12-25 13:04:13'),(16,'','','通知',0,1,'2012-12-25 13:04:13'),(17,'','','通知',0,1,'2012-12-25 13:04:13'),(18,'','','通知',0,1,'2012-12-25 13:04:22'),(19,'','','通知',0,1,'2012-12-25 13:05:44'),(20,'','','通知',0,1,'2012-12-25 13:05:49'),(21,'','','通知',0,1,'2012-12-25 13:06:17'),(22,'','','通知',0,1,'2012-12-25 13:07:29'),(23,'','','通知',0,1,'2012-12-25 13:07:41'),(24,'','','通知',0,1,'2012-12-25 13:08:04'),(25,'','','通知',0,1,'2012-12-25 13:08:16'),(26,'dfghdfgh','上的风格','通知',0,1,'2012-12-25 13:08:52'),(27,'sdfasdfasdf','发电公司地方官倒萨发个斯蒂芬gadflygadfly个','通知',0,1,'2012-12-25 13:09:26'),(28,'上的风格','斯蒂芬个','通知',0,1,'2012-12-25 13:09:45'),(29,'','','通知',0,1,'2012-12-25 13:39:10'),(30,'','','通知',0,1,'2012-12-25 13:39:37'),(31,'阿斯蒂芬','阿斯蒂芬阿斯蒂芬','个人分享',0,1,'2012-12-25 13:41:48'),(32,'都是','是的','通知',0,1,'2012-12-25 17:11:28');

/*Table structure for table `company_static_month` */

CREATE TABLE `company_static_month` (
  `id` bigint(20) NOT NULL auto_increment,
  `static_date` date NOT NULL,
  `static_addCustomerNum` int(11) NOT NULL default '0',
  `static_signingMoney` int(11) NOT NULL default '0',
  `static_remittancesReceived` int(11) NOT NULL default '0',
  `static_receivableBalances` int(11) NOT NULL default '0',
  `static_overdueReceivables` int(11) NOT NULL default '0',
  PRIMARY KEY  (`id`),
  KEY `static_date` (`static_date`)
) ENGINE=InnoDB AUTO_INCREMENT=18 DEFAULT CHARSET=utf8;

/*Data for the table `company_static_month` */

insert  into `company_static_month`(`id`,`static_date`,`static_addCustomerNum`,`static_signingMoney`,`static_remittancesReceived`,`static_receivableBalances`,`static_overdueReceivables`) values (1,'2012-12-00',22,0,0,56,0),(2,'2012-11-00',1,0,6,0,56),(3,'2012-10-00',3,22,6,56,5),(4,'2012-09-00',4,0,6,0,0),(5,'2012-08-00',0,0,0,567,56),(6,'2012-07-00',34,0,4,567,0),(7,'2012-06-00',66,22,7,0,5656),(8,'2012-05-00',1,3,45,56,0),(9,'2012-04-00',33,0,0,56,0),(10,'2012-03-00',4,0,0,0,56),(11,'2012-02-00',123,1,0,56,0),(12,'2012-01-00',123,0,0,0,56),(13,'2011-12-00',22,0,0,56,0),(14,'2011-11-00',3,0,0,0,0),(15,'2011-10-00',4,0,0,0,0),(16,'2011-09-00',33,0,0,0,0),(17,'2011-08-00',3,0,0,0,0);

/*Table structure for table `config` */

CREATE TABLE `config` (
  `id` bigint(20) NOT NULL auto_increment,
  `config_key` varchar(100) default NULL,
  `config_value` varchar(200) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

/*Data for the table `config` */

insert  into `config`(`id`,`config_key`,`config_value`) values (1,'addcustomer','客户联系人'),(2,'customer_grade','一级|二级|三级|四级|五级'),(3,'customer_grade_images','★|★★|★★★|★★★★|★★★★★');

/*Table structure for table `contact` */

CREATE TABLE `contact` (
  `contact_id` bigint(20) NOT NULL auto_increment,
  `contact_coustomer_id` int(11) NOT NULL,
  `contact_name` varchar(100) NOT NULL,
  `contact_email` varchar(300) NOT NULL,
  `contact_tel` varchar(50) default NULL,
  `contact_phone` varchar(50) default NULL,
  `contact_fax` varchar(50) default NULL,
  `contact_msn` varchar(50) default NULL,
  `contact_skype` varchar(50) default NULL,
  `contact_other` varchar(50) default NULL,
  `contact_create_time` datetime NOT NULL,
  `contact_lastcontacttime` timestamp NOT NULL default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  `contact_flag` varchar(50) default NULL,
  `is_delete` int(11) NOT NULL default '0',
  KEY `contact_id` (`contact_id`)
) ENGINE=InnoDB AUTO_INCREMENT=1078 DEFAULT CHARSET=utf8;

/*Data for the table `contact` */

insert  into `contact`(`contact_id`,`contact_coustomer_id`,`contact_name`,`contact_email`,`contact_tel`,`contact_phone`,`contact_fax`,`contact_msn`,`contact_skype`,`contact_other`,`contact_create_time`,`contact_lastcontacttime`,`contact_flag`,`is_delete`) values (1006,1002,'刘凯','liukai198612@gmail.com','8618010156796','8618010156796','','阿斯','阿斯蒂','阿斯蒂芬34 ','0000-00-00 00:00:00','2012-12-27 17:58:03','customer',0),(1007,1002,'asdf阿斯蒂芬','asdf','爱上','','阿斯蒂芬','','','','2012-12-16 16:10:29','2012-12-27 17:58:03','customer',0),(1008,1,'sdf ','asdfasdf ','','','','','','','2012-12-18 17:56:17','2012-12-27 17:58:03','customer',0),(1009,1,'sdfgsdfg','sdfgsdfg','','','','','','','2012-12-18 17:56:33','2012-12-27 17:58:03','customer',0),(1010,1002,'asdfasdf','asdfasdf','sdfgsdfg','','asdfasdf','','','','2012-12-18 17:58:10','2012-12-27 17:58:03','customer',0),(1011,1005,'asdfasdfasdfasdf','asdfasdf','','rftgewrt','tgfjhfgjh','','','sadfasdf','2012-12-18 18:10:26','2012-12-27 17:58:03','customer',0),(1012,1005,'asdfasdfasdfasdfasdfasdfasdfasdf','asdfasdf','','','','','','','2012-12-18 18:17:08','2012-12-27 17:58:03','customer',1),(1013,0,'asdfasdfasdfasdf','asdfasdf','','rftgewrt','tgfjhfgjh','','','sdfgsdfgdf','2012-12-19 10:50:15','2012-12-27 17:58:03','customer',0),(1014,0,'asdfasdfasdfasdf','asdfasdf','','rftgewrt','tgfjhfgjh','','','','2012-12-19 11:18:27','2012-12-27 17:58:03','customer',0),(1015,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:11','2012-12-27 17:58:03','customer',0),(1016,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:13','2012-12-27 17:58:03','customer',0),(1017,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:13','2012-12-27 17:58:03','customer',0),(1018,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:13','2012-12-27 17:58:03','customer',0),(1019,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:13','2012-12-27 17:58:03','customer',0),(1020,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:13','2012-12-27 17:58:03','customer',0),(1021,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:13','2012-12-27 17:58:03','customer',0),(1022,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:14','2012-12-27 17:58:03','customer',0),(1023,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:14','2012-12-27 17:58:03','customer',0),(1024,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:14','2012-12-27 17:58:03','customer',0),(1025,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:15','2012-12-27 17:58:03','customer',0),(1026,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:15','2012-12-27 17:58:03','customer',0),(1027,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:15','2012-12-27 17:58:03','customer',0),(1028,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:15','2012-12-27 17:58:03','customer',0),(1029,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:15','2012-12-27 17:58:03','customer',0),(1030,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:15','2012-12-27 17:58:03','customer',0),(1031,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:16','2012-12-27 17:58:03','customer',0),(1032,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:16','2012-12-27 17:58:03','customer',0),(1033,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:16','2012-12-27 17:58:03','customer',0),(1034,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:16','2012-12-27 17:58:03','customer',0),(1035,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:17','2012-12-27 17:58:03','customer',0),(1036,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:18','2012-12-27 17:58:03','customer',0),(1037,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:18','2012-12-27 17:58:03','customer',0),(1038,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:18','2012-12-27 17:58:03','customer',0),(1039,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:35','2012-12-27 17:58:03','customer',0),(1040,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:35','2012-12-27 17:58:03','customer',0),(1041,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:35','2012-12-27 17:58:03','customer',0),(1042,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:36','2012-12-27 17:58:03','customer',0),(1043,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:36','2012-12-27 17:58:03','customer',0),(1044,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:36','2012-12-27 17:58:03','customer',0),(1045,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:36','2012-12-27 17:58:03','customer',0),(1046,0,'阿斯蒂芬阿斯蒂芬阿斯蒂芬','阿斯顿发生的发斯蒂芬','','','','','','','2012-12-19 11:55:37','2012-12-27 17:58:03','customer',0),(1047,0,'阿斯蒂芬阿斯蒂芬','滴答滴答','','','','','','','2012-12-19 11:57:14','2012-12-27 17:58:03','customer',0),(1048,0,'22222222222','22222222222','','','','','','','2012-12-19 11:58:29','2012-12-27 17:58:03','customer',0),(1049,0,'阿斯顿发','啊 ','','','','','','','2012-12-19 11:59:31','2012-12-27 17:58:03','customer',0),(1050,0,'阿斯顿发生的发斯蒂芬','3333','','','','','','','2012-12-19 12:00:15','2012-12-27 17:58:03','customer',0),(1051,0,'上的风格','上的风格','','','','','','','2012-12-19 15:34:48','2012-12-27 17:58:03','customer',0),(1052,0,'大发光火','电饭锅','','','','','','','2012-12-20 15:11:44','2012-12-27 17:58:03','customer',0),(1053,0,'上的风格','的萨芬个','','','','','','','2012-12-20 15:11:53','2012-12-27 17:58:03','customer',0),(1054,0,'大发光火','地方规划法规环境','','','','','','','2012-12-20 15:12:02','2012-12-27 17:58:03','customer',0),(1055,0,'飞','飞','','','','','','','2012-12-20 15:12:08','2012-12-27 17:58:03','customer',0),(1056,0,'的','的','','','','','','','2012-12-20 15:12:16','2012-12-27 17:58:03','customer',0),(1057,0,'大发光火','地方港行','','','','','','','2012-12-20 15:12:23','2012-12-27 17:58:03','customer',0),(1058,0,'大发光火','电饭锅好','','','','','','','2012-12-20 15:12:30','2012-12-27 17:58:03','customer',0),(1059,0,'电饭锅好','电饭锅 ','','','','','','','2012-12-20 15:12:37','2012-12-27 17:58:03','customer',0),(1060,1052,'','','','','','','','','2012-12-20 15:12:45','2012-12-27 18:41:42','customer',0),(1061,0,'凤飞飞','方法','','','','','','','2012-12-20 15:34:43','2012-12-27 18:42:29','customer',0),(1062,0,'啊','啊','','','','','','','2012-12-24 13:31:26','2012-12-27 17:58:03','customer',0),(1063,0,'啊','liukai198612@gmail.com','','','','','','','2012-12-24 13:35:40','2012-12-27 17:58:03','customer',0),(1064,0,'ai、','liukai198612@gmail.com','','','','','','','2012-12-25 16:43:07','2012-12-27 17:58:03','customer',0),(1065,0,'asdf','liukai198612@gmail.com','','','','','','','2012-12-25 16:45:10','2012-12-27 17:58:03','customer',0),(1066,1006,'阿斯顿发生的','','','','爱上','','','','2012-12-27 17:58:36','2012-12-27 17:59:11','customer',0),(1067,0,'sass','','','','试试','','','','2012-12-27 18:05:16','2012-12-27 18:05:16','1057',0),(1068,1057,'撒','','','','啊','','','','2012-12-27 18:07:05','2012-12-27 18:07:05','customer',0),(1069,1057,'阿斯蒂芬','','','','阿斯顿','','','','2012-12-27 18:08:21','2012-12-27 18:08:21','customer',0),(1070,5,'阿斯蒂芬','','','','阿斯顿','','','','2012-12-27 18:18:28','2012-12-27 18:21:06','supplier',1),(1071,5,'阿斯顿官大大大方','擦擦擦v','阿斯顿','啊','阿斯蒂芬','啊','','','2012-12-27 18:22:33','2012-12-27 18:22:46','supplier',0),(1072,5,'当当','的 sdf ','sd ','sd ','人','','','sadf ','2012-12-27 18:23:31','2012-12-27 18:38:10','supplier',0),(1073,1053,'asdf','asss','sa','a','a','a','a','assss','2012-12-27 18:38:25','2012-12-27 18:38:32','customer',0),(1074,1052,'asdf','asdf','asdf','asdf','asdfasdf','asdf','asdf','asdfasdf','2012-12-27 18:42:41','2012-12-27 18:42:41','customer',0),(1075,1057,'','','','','','','','','2012-12-28 16:00:58','2012-12-28 16:00:58','customer',0),(1076,1056,'梵蒂冈','斯蒂芬个斯蒂芬个是','','','','','','','2012-12-28 16:05:20','2012-12-28 16:05:20','customer',0),(1077,7,'阿斯顿发生','','','','','','','阿斯顿','2012-12-29 15:25:37','2012-12-29 15:25:37','supplier',0);

/*Table structure for table `customer` */

CREATE TABLE `customer` (
  `id` bigint(20) NOT NULL auto_increment,
  `customer_id` varchar(100) default NULL,
  `customer_remind_id` int(20) NOT NULL default '0',
  `customer_name` varchar(300) NOT NULL,
  `customer_addr` varchar(300) NOT NULL default '',
  `customer_postal_code` int(10) default NULL,
  `customer_group` int(10) NOT NULL,
  `customer_grade` int(10) default NULL,
  `customer_country` varchar(300) NOT NULL default '',
  `customer_province` varchar(300) NOT NULL default '',
  `customer_from` varchar(300) NOT NULL default '',
  `customer_whohave` int(11) default NULL,
  `customer_website` varchar(300) NOT NULL default '',
  `customer_attention` text NOT NULL,
  `customer_remarks` text NOT NULL,
  `customer_first_contacter` bigint(20) NOT NULL,
  `is_delete` int(11) NOT NULL default '0',
  KEY `id` (`id`),
  KEY `customer_id` (`customer_id`)
) ENGINE=InnoDB AUTO_INCREMENT=1058 DEFAULT CHARSET=utf8;

/*Data for the table `customer` */

insert  into `customer`(`id`,`customer_id`,`customer_remind_id`,`customer_name`,`customer_addr`,`customer_postal_code`,`customer_group`,`customer_grade`,`customer_country`,`customer_province`,`customer_from`,`customer_whohave`,`customer_website`,`customer_attention`,`customer_remarks`,`customer_first_contacter`,`is_delete`) values (1002,'1',0,'liukai','beijing china',100000,1,0,'请选择','请选择','请选择',1,'','','',1007,0),(1003,'0984e543',0,'asdfasdf','asdf',0,1,1,'请选择','请选择','请选择',1,'asdf','asdf','asdf',0,0),(1004,'sdfg',0,'sdfg','',0,1,1,'请选择','请选择','请选择',1,'','','',0,0),(1005,'asdfasdf',0,'asdf','dfsgsdfgsdfg',0,1,0,'请选择','请选择','请选择',1,'','','',1011,0),(1006,'当当',0,'asdf凤飞飞当当','阿斯蒂芬',0,1,0,'请选择','请选择','请选择',1,'','','',1013,0),(1043,'',0,'斯蒂芬个斯蒂芬个','',0,1,0,'请选择','请选择','',1,'','','',1051,0),(1044,'',0,'梵蒂冈和地方工会','',0,1,0,'请选择','请选择','',1,'','','',1052,0),(1045,'',0,'上的风格','',0,1,0,'请选择','请选择','',1,'','','',1053,0),(1046,'',0,'地方规划地方工会','',0,1,0,'请选择','请选择','',1,'','','',1054,0),(1047,'',0,'风景画','',0,1,0,'请选择','请选择','',1,'','','',1055,0),(1048,'',0,'地方规划地方港行','',0,1,0,'请选择','请选择','',1,'','','',1056,0),(1049,'1080',0,'大发光火','',0,1,0,'请选择','请选择','',1,'','','',1057,0),(1050,'',0,'梵蒂冈好','',0,1,0,'请选择','请选择','',1,'','','',1058,0),(1051,'',0,'大发光火','',0,1,0,'请选择','请选择','',1,'','','',1059,1),(1052,'',0,'大发光火','',0,1,0,'请选择','请选择','',1,'','','',1074,0),(1053,'',0,'刘凯','',0,32,0,'请选择','请选择','',1,'','','',1073,0),(1054,'刘凯我爱',0,'阿斯顿','',0,0,0,'请选择','请选择','',1,'','','',1062,1),(1055,'',1088,'分割','',123456,24,1,'','请选择','',1,'','','',1063,0),(1056,'ai、',1089,'刘凯','',3333,0,2,'','','',1,'','','',1064,0),(1057,'1082',1087,'asdf ','',0,0,1,'','','',1,'','','',1068,0);

/*Table structure for table `customer_group` */

CREATE TABLE `customer_group` (
  `id` bigint(20) NOT NULL auto_increment,
  `customer_group_name` varchar(100) NOT NULL,
  `customer_group_level` int(11) default '1',
  `group_category` varchar(50) NOT NULL,
  `customer_group_detial` text,
  `is_delete` int(1) NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=39 DEFAULT CHARSET=utf8;

/*Data for the table `customer_group` */

insert  into `customer_group`(`id`,`customer_group_name`,`customer_group_level`,`group_category`,`customer_group_detial`,`is_delete`) values (1,'阿斯蒂芬',1,'customer','',0),(2,'撒地方',1,'customer','阿斯顿发斯蒂芬',0),(3,'所有分组',1,'suppliers','',0),(4,'所有分组',1,'customer',NULL,0),(5,'斯蒂芬2222',1,'customer','阿斯蒂芬阿斯蒂芬阿斯蒂芬',1),(6,'斯蒂芬2222',1,'customer','阿斯蒂芬阿斯蒂芬阿斯蒂芬',1),(7,'滴答滴答',1,'customer','',1),(8,'滴答滴答',1,'customer','',1),(9,'333',1,'suppliers','33',1),(24,'55555',1,'customer','',0),(25,'55555',1,'customer','',1),(32,'都是',1,'customer','',0),(33,'都是',1,'suppliers','',0),(34,'撒地方',1,'customer','',0),(35,'33333',1,'customer','',0),(36,'多带点',1,'customer','',0),(37,'爱上',1,'customer','',0),(38,'凤飞飞',1,'product','瓦尔地方',0);

/*Table structure for table `groups` */

CREATE TABLE `groups` (
  `group_id` bigint(20) NOT NULL auto_increment,
  `group_name` varchar(50) default NULL,
  `group_permission` varchar(500) default NULL,
  `is_delete` int(11) NOT NULL default '0',
  `creation_date` datetime default '0000-00-00 00:00:00',
  `last_modified_date` datetime default '0000-00-00 00:00:00',
  PRIMARY KEY  (`group_id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;

/*Data for the table `groups` */

insert  into `groups`(`group_id`,`group_name`,`group_permission`,`is_delete`,`creation_date`,`last_modified_date`) values (1,'管理员','_121_131_1_11_171_281_81_2_3_4_71_31_51_61_101_91_141_151_161_501_481_181_191_201_491_221_231_241_251_261_271_301_311_321_431_441_381_391_451_461_291_341_331_421_',0,'0000-00-00 00:00:00','0000-00-00 00:00:00'),(11,'临时用户组','_121_141_151__371_391_381__131_161__11_71_31_51_61_101__171_181_191_201_411_221_231_241_251_261_271_301_311_321_431__81_91_',0,'0000-00-00 00:00:00','0000-00-00 00:00:00');

/*Table structure for table `product_price` */

CREATE TABLE `product_price` (
  `price_id` bigint(20) NOT NULL auto_increment,
  `price_cost_cn` varchar(300) default '',
  `price_sale_cn` varchar(300) default '',
  `price_cost_en` varchar(300) default '',
  `price_sale_en` varchar(300) default '',
  `price_cost_other` varchar(300) default '',
  `price_sale_other` varchar(300) default '',
  `is_delete` int(11) NOT NULL default '0',
  KEY `id` (`price_id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

/*Data for the table `product_price` */

insert  into `product_price`(`price_id`,`price_cost_cn`,`price_sale_cn`,`price_cost_en`,`price_sale_en`,`price_cost_other`,`price_sale_other`,`is_delete`) values (1,'阿斯蒂芬揉揉','6','工行是当当','当当飞','','第四大',0),(2,'','','','','','',0);

/*Table structure for table `products` */

CREATE TABLE `products` (
  `id` bigint(20) NOT NULL auto_increment,
  `product_id` varchar(100) default NULL,
  `product_price_id` int(11) NOT NULL,
  `company_productcode` varchar(300) default '',
  `product_type` varchar(300) default '',
  `product_group` int(11) default NULL,
  `product_chinaname` varchar(300) default '',
  `product_chinacontent` varchar(300) default '',
  `product_englishname` varchar(300) default '',
  `product_englishcontent` varchar(300) default '',
  `product_shortname` varchar(300) default '',
  `product_customscode` varchar(300) default '',
  `product_model_cn` varchar(300) default '',
  `product_format_cn` varchar(300) default '',
  `product_model_en` varchar(300) default '',
  `product_format_en` varchar(300) default '',
  `product_unit` varchar(300) default '',
  `is_delete` int(11) NOT NULL default '0',
  `create_time` datetime NOT NULL,
  KEY `id` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

/*Data for the table `products` */

insert  into `products`(`id`,`product_id`,`product_price_id`,`company_productcode`,`product_type`,`product_group`,`product_chinaname`,`product_chinacontent`,`product_englishname`,`product_englishcontent`,`product_shortname`,`product_customscode`,`product_model_cn`,`product_format_cn`,`product_model_en`,`product_format_en`,`product_unit`,`is_delete`,`create_time`) values (1,'阿斯蒂芬',1,'','',38,'阿斯蒂芬','','阿斯顿','','','','','','','','',0,'2013-01-03 17:16:26'),(2,'2',2,'','',38,'阿斯蒂芬','','阿斯顿','','','','','','','','',0,'2013-01-03 17:16:59');

/*Table structure for table `reminds` */

CREATE TABLE `reminds` (
  `remind_id` bigint(20) NOT NULL auto_increment,
  `remind_start_time` datetime NOT NULL,
  `remind_end_time` datetime NOT NULL,
  `remind_title` varchar(300) NOT NULL,
  `remind_content` text,
  `userid` int(11) default NULL,
  `is_delete` int(11) NOT NULL default '0',
  KEY `remind_id` (`remind_id`)
) ENGINE=InnoDB AUTO_INCREMENT=1090 DEFAULT CHARSET=utf8;

/*Data for the table `reminds` */

insert  into `reminds`(`remind_id`,`remind_start_time`,`remind_end_time`,`remind_title`,`remind_content`,`userid`,`is_delete`) values (1077,'0000-00-00 00:00:00','0000-00-00 00:00:00','圣达菲','',1,0),(1078,'0000-00-00 00:00:00','0000-00-00 00:00:00','圣达菲','',1,0),(1079,'0000-00-00 00:00:00','0000-00-00 00:00:00','圣达菲','',1,0),(1080,'2012-12-29 11:26:33','1970-01-01 08:33:40','圣达菲','',1,0),(1081,'2012-12-29 11:29:34','1970-01-01 08:01:35','电饭锅','',1,0),(1082,'2012-12-29 11:29:42','1970-01-01 08:01:35','电饭锅','',1,0),(1083,'2012-12-29 11:31:00','1970-01-01 08:00:13','撒打发斯蒂芬','',1,0),(1084,'2012-12-29 11:31:05','1970-01-01 08:00:13','撒打发斯蒂芬','',1,0),(1085,'2012-12-29 11:34:41','2002-01-05 00:00:00','上的发生大发','',1,0),(1086,'2012-12-29 11:34:45','2002-01-05 00:00:00','上的发生大发','',1,0),(1087,'2012-12-29 12:36:07','2087-04-12 12:00:00','阿斯','圣达菲',1,0),(1088,'2012-12-29 11:37:04','0000-00-00 00:00:00','啊事实上','',1,0),(1089,'2012-12-29 11:39:21','2085-12-28 00:00:00','揉揉','',1,0);

/*Table structure for table `static_confige` */

CREATE TABLE `static_confige` (
  `id` bigint(20) NOT NULL auto_increment,
  `static_confige_name` varchar(100) NOT NULL,
  `static_confige_title` varchar(500) NOT NULL default '',
  `static_confige_statistical_units` varchar(100) NOT NULL default '',
  `static_confige_char_units` varchar(100) NOT NULL default '',
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

/*Data for the table `static_confige` */

insert  into `static_confige`(`id`,`static_confige_name`,`static_confige_title`,`static_confige_statistical_units`,`static_confige_char_units`) values (1,'addCustomerNum','新增单位个数','个','顾客数'),(2,'signingMoney','签单额','万美元','万美元'),(3,'remittancesReceived','收汇款','万美元','万美元'),(4,'receivableBalances','应收款余额','万美元','万美元'),(5,'overdueReceivables','逾期应收款','万美元','万美元');

/*Table structure for table `supplier` */

CREATE TABLE `supplier` (
  `id` bigint(20) NOT NULL auto_increment,
  `supplier_id` varchar(100) default NULL,
  `supplier_name` varchar(300) NOT NULL,
  `supplier_addr` varchar(300) NOT NULL default '',
  `supplier_products` text,
  `supplier_group` int(10) NOT NULL,
  `supplier_grade` int(10) default NULL,
  `supplier_contact_name` varchar(300) NOT NULL default '',
  `supplier_contact_tel` varchar(300) NOT NULL default '',
  `supplier_contact_phone` varchar(300) NOT NULL default '',
  `supplier_contact_postal` varchar(300) default NULL,
  `supplier_contact_email` varchar(300) NOT NULL default '',
  `supplier_contact_fax` varchar(300) default NULL,
  `supplier_contact_other` varchar(300) default NULL,
  `supplier_bank_name` varchar(300) NOT NULL default '',
  `supplier_bank_username` varchar(300) NOT NULL,
  `supplier_bank_num` varchar(300) NOT NULL,
  `supplier_company_representative` varchar(300) NOT NULL,
  `supplier_company_taxnum` varchar(300) NOT NULL,
  `supplier_remind` text NOT NULL,
  `supplier_permission` int(11) NOT NULL,
  `is_delete` int(11) NOT NULL default '0',
  `create_time` text,
  KEY `id` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;

/*Data for the table `supplier` */

insert  into `supplier`(`id`,`supplier_id`,`supplier_name`,`supplier_addr`,`supplier_products`,`supplier_group`,`supplier_grade`,`supplier_contact_name`,`supplier_contact_tel`,`supplier_contact_phone`,`supplier_contact_postal`,`supplier_contact_email`,`supplier_contact_fax`,`supplier_contact_other`,`supplier_bank_name`,`supplier_bank_username`,`supplier_bank_num`,`supplier_company_representative`,`supplier_company_taxnum`,`supplier_remind`,`supplier_permission`,`is_delete`,`create_time`) values (1,'2','dfg','asdf','asdfasdfasd',0,1,'asdf','asdf','sadf','sadf','sadf','sadf',NULL,'asdf','asdf','sadf','sadfasdf','asdf','sadf',1,0,NULL),(2,'','阿斯顿发斯蒂芬','','',3,1,'撒四十四','','','','','',NULL,'','','','','','                    ',1,0,'2012-12-27 15:05:52'),(3,'','阿斯顿发斯蒂芬','','',3,1,'撒四十四','','','','','',NULL,'','','','','','                    ',1,1,'2012-12-27 15:05:56'),(4,'','阿斯顿发斯蒂芬','','',3,1,'撒四十四','','','','','',NULL,'','','','','','                    ',1,0,'2012-12-27 15:06:12'),(5,'','阿斯蒂芬','','',3,1,'阿斯顿啊','','','','','',NULL,'','','','','','                    ',1,0,'2012-12-27 15:06:18'),(6,'','阿斯顿发斯蒂芬','','',33,1,'撒四十四','','','','','','','','','','','','                                        ',1,0,'2012-12-27 18:44:09'),(7,'','阿斯顿发斯蒂芬','','',33,5,'撒四十四','','','','','','','','','','','','                                                            ',1,0,'2012-12-28 12:57:12');

/*Table structure for table `user` */

CREATE TABLE `user` (
  `id` bigint(20) NOT NULL auto_increment,
  `user_name` varchar(100) default NULL,
  `user_password` varchar(100) default NULL,
  `user_email` varchar(100) default NULL,
  `user_nickname` varchar(50) default NULL,
  `user_depart` varchar(100) default NULL,
  `is_delete` int(11) NOT NULL default '0',
  `creation_date` datetime NOT NULL default '0000-00-00 00:00:00',
  `last_modified_date` datetime NOT NULL default '0000-00-00 00:00:00',
  PRIMARY KEY  (`id`),
  KEY `user_email` (`user_email`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

/*Data for the table `user` */

insert  into `user`(`id`,`user_name`,`user_password`,`user_email`,`user_nickname`,`user_depart`,`is_delete`,`creation_date`,`last_modified_date`) values (1,'liukai','21a451cad4e8a6727d6d39c21e75e5ab','liukai@dangdang.com','刘凯','技术部',0,'0000-00-00 00:00:00','2013-01-03 17:45:53');

/*Table structure for table `user_group_map` */

CREATE TABLE `user_group_map` (
  `user_group_map_id` bigint(20) NOT NULL auto_increment,
  `user_id` bigint(20) NOT NULL default '0',
  `group_id` bigint(20) NOT NULL,
  `is_delete` int(11) NOT NULL default '0',
  `creation_date` datetime NOT NULL default '0000-00-00 00:00:00',
  `last_modified_date` datetime NOT NULL default '0000-00-00 00:00:00',
  PRIMARY KEY  (`user_group_map_id`),
  KEY `user_id` (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

/*Data for the table `user_group_map` */

insert  into `user_group_map`(`user_group_map_id`,`user_id`,`group_id`,`is_delete`,`creation_date`,`last_modified_date`) values (1,1,1,0,'0000-00-00 00:00:00','0000-00-00 00:00:00'),(2,1,12,0,'0000-00-00 00:00:00','0000-00-00 00:00:00');

/*Table structure for table `user_permission` */

CREATE TABLE `user_permission` (
  `id` bigint(20) NOT NULL auto_increment,
  `user_id` bigint(20) NOT NULL default '0',
  `customer_permission` varchar(500) NOT NULL,
  `supplier_permission` varchar(500) NOT NULL,
  `is_delete` int(11) NOT NULL default '0',
  `creation_date` datetime NOT NULL default '0000-00-00 00:00:00',
  `last_modified_date` datetime NOT NULL default '0000-00-00 00:00:00',
  PRIMARY KEY  (`id`),
  KEY `user_id` (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

/*Data for the table `user_permission` */

insert  into `user_permission`(`id`,`user_id`,`customer_permission`,`supplier_permission`,`is_delete`,`creation_date`,`last_modified_date`) values (3,1,'1,2,4','1,2,4',0,'0000-00-00 00:00:00','0000-00-00 00:00:00');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;