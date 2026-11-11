# Write your MySQL query statement below
select c.visited_on,
(
    select sum(amount) 
    from Customer c1 
    where c1.visited_on between date_sub(c.visited_on,interval 6 day) and c.visited_on 
) as amount,
(
select round(sum(c2.amount)/7,2) 
from Customer c2
where c2.visited_on between date_sub(c.visited_on,interval 6 day) and c.visited_on  
) as average_amount
from Customer c
where c.visited_on >=
(
    select date_add(min(visited_on),interval 6 day)
    from Customer
)
group by c.visited_on