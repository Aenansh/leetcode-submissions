# Write your MySQL query statement below
select m.name
from employee m
inner join employee e
on m.id = e.managerId
group by e.managerId
having count(e.managerId) >= 5
