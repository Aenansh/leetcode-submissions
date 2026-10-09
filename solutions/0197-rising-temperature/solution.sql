# Write your MySQL query statement below
select t1.id
from weather as t1
inner join weather as t2
on t1.id != t2.id
where t1.temperature > t2.temperature
and datediff(t1.recordDate, t2.recordDate) = 1;
