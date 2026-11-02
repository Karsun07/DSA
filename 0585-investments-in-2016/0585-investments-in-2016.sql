# Write your MySQL query statement below

with cte as
(
    select *,
    count(*) over(partition by lat,lon) as lat_lon_pair,
    count(*) over(partition by tiv_2015) as cnt_2015
    from Insurance
)
select round(sum(tiv_2016),2) as tiv_2016
from cte
where lat_lon_pair=1 and cnt_2015>1



