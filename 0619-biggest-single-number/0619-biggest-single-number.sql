# Write your MySQL query statement below
select max(t.num) as num
from
(
select num,count(num) as freq
from MyNumbers 
group by num
) t
where t.freq=1;
