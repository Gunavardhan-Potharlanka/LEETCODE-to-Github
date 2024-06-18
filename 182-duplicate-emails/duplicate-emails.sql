# Write your MySQL query statement below
select distinct email as Email from person as p1 where (select count(email) from person where person.email = p1.email) > 1