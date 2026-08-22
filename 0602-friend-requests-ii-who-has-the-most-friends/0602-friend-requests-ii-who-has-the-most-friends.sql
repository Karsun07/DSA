# Write your MySQL query statement below
select t.id as id, count(t.id) as num
from
(
    select requester_id as id
    from RequestAccepted

    union all

    select accepter_id as id
    from RequestAccepted
)t
group by t.id
order by num desc
limit 1
