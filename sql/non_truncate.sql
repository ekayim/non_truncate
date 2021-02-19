CREATE EXTENSION non_truncate;

--
-- create table for test
--
CREATE TABLE non_truncate_test(
	value	INT
);

-- 
-- truncate statement
--
TRUNCATE non_truncate_test;

--
-- drop table
--
DROP TABLE non_truncate_test;

DROP EXTENSION non_truncate;
