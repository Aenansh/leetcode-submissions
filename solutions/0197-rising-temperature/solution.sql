# Write your MySQL query statement below
select today.id from
weather as today
inner join weather as yesterday
where today.temperature > yesterday.temperature
and datediff(today.recordDate, yesterday.recordDate) = 1;
