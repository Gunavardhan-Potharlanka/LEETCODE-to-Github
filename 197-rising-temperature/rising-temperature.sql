# Write your MySQL query statement below
select w1.id as Id from Weather as w1 join Weather as w2 on w1.recordDate = date_add(w2.recordDate, interval 1 day) where w1.temperature > w2.temperature;