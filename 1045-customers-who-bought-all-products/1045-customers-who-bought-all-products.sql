# Write your MySQL query statement below
select t.customer_id as customer_id
from
(
select customer_id,count(distinct product_key) as freq
from Customer
group by customer_id
) t
where t.freq=(
    select count(*) 
    from Product
)