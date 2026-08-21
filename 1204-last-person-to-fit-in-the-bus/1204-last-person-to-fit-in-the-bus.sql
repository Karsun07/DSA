# Write your MySQL query statement below
select person_name
from (
    SELECT 
        person_name,
        turn,
        SUM(weight) OVER (ORDER BY turn) AS total_weight
    FROM Queue
)t
where t.total_weight<=1000
order by t.total_weight desc 
limit 1
