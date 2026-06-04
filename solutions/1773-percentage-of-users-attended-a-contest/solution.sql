# Write your MySQL query statement below
select contest_id, round((count(distinct r.user_id)) * 100 / (select count(user_id) from users), 2) as percentage
from register r
left join users u
on r.user_id = u.user_id
group by r.contest_id
order by percentage
desc, contest_id
asc
