# Write your MySQL query statement below
Select T1.name as Employee
From Employee T1, Employee T2
Where T1.managerId = T2.id
And T1.salary > T2.salary;
