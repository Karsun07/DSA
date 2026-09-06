select round(count(distinct a.player_id)/(
    select count(distinct player_id)
    from Activity
),2) as fraction
from Activity a
join
(
    select player_id,min(event_date) as first_login
from Activity 
group by player_id
) x
on x.player_id = a.player_id and a.event_date=date_add(x.first_login,INTERVAL 1 DAY)
