# Write your MySQL query statement below
select t.person_name 
from
(select *,
sum(weight) over(order by turn) as s
from
Queue
order by turn) t
where t.s<=1000
order by s desc
limit 1








