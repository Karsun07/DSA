# Write your MySQL query statement below
select distinct num as ConsecutiveNums
from
(select *,
lag(num,1) over () as rn1,
lag(num,2) over() as rn2
from Logs) t
where t.rn1=t.rn2 and t.rn1=num


