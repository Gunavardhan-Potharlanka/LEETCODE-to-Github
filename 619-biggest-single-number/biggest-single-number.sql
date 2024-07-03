# Write your MySQL query statement below
select max(num) as num from MyNumbers as m where (select count(*) from MyNumbers where num = m.num) = 1;