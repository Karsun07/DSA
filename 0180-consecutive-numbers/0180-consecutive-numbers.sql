# Write your MySQL query statement below
select distinct t.num as ConsecutiveNums
from 
(
    select *,
lag(num,1) over(order by id) as prev1,
lag(num,2) over(order by id) as prev2
from Logs 
) t
WHERE t.num = t.prev1
AND t.prev1 = t.prev2;

