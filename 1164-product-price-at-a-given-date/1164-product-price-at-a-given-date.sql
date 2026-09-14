# Write your MySQL query statement below
select product_id,max(new_price) as price
from Products
where change_date<='2019-08-16'
group by product_id

union 
select product_id,10 
from products
where
product_id not in
(
    select product_id
    from Products
    where change_date<='2019-08-16'
    group by product_id
)
