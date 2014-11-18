DROP TABLE IF EXISTS `entity_results_guesswho`;
CREATE TABLE `entity_results_guesswho` (
  `result_id` int(10) NOT NULL,
  `turns_used` int(10) DEFAULT NULL,
  `date_time` datetime DEFAULT NULL,
  PRIMARY KEY (`result_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
INSERT INTO `entity_results_guesswho` VALUES (1,12,'2014-11-16 20:40:00'),(2,3,'2014-11-13 12:12:00'),(3,5,'2014-11-15 01:24:00'),(4,4,'2014-11-17 18:20:00'),(5,7,'2014-11-15 15:16:00');



DROP TABLE IF EXISTS `entity_user_guesswho`;
CREATE TABLE `entity_user_guesswho` (
  `player_id` int(10) NOT NULL,
  `username` varchar(50) NOT NULL,
  `date_time` datetime DEFAULT NULL,
  PRIMARY KEY (`player_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
INSERT INTO `entity_user_guesswho` VALUES (1,'K-Dog',NULL),(2,'S-Chip',NULL),(3,'K-F-C',NULL),(4,'J-Beans',NULL),(5,'G-Worms',NULL);



DROP TABLE IF EXISTS `xref_user_results_guesswho`;
CREATE TABLE `xref_user_results_guesswho` (
  `xref_id` int(10) NOT NULL,
  `player_id` int(10) DEFAULT NULL,
  `result_id` int(10) DEFAULT NULL,
  PRIMARY KEY (`xref_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
INSERT INTO `xref_user_results_guesswho` VALUES (1,2,4),(2,5,1),(3,3,2),(4,1,5),(5,4,3);