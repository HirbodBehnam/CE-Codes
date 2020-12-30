-- Section1
    SELECT `name` FROM `singer` WHERE `balance` = 0;
-- Section2
    CREATE TABLE producer(name VARCHAR(20) PRIMARY KEY); INSERT INTO `producer` (name) SELECT DISTINCT `producer` FROM `song`;
-- Section3 from https://stackoverflow.com/a/4951354/4213397
    SELECT `name`, `total_sell` FROM `song` WHERE `producer`="dr.dre" AND `singer` IN (SELECT a.singer FROM song AS a WHERE (SELECT COUNT(*) FROM song AS b WHERE b.singer = a.singer AND b.total_sell >= a.total_sell) = 2 AND a.producer = "dr.dre");