# Write your MySQL query statement below
select id as Id from Weather as w where w.temperature > (select temperature from weather as we where we.recordDate = date_sub(w.recordDate, interval 1 day));