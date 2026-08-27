# Write your MySQL query statement below
select t.product_name,t.unit
from
(
select p.product_name,sum(o.unit) as unit
from Products p 
join Orders o
on p.product_id=o.product_id
and left(o.order_date,7)='2020-02'
group by p.product_name
)t
where t.unit>=100
