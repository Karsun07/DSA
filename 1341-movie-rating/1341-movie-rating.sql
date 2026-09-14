(select u.name as results
from MovieRating mr
join Users u
on mr.user_id=u.user_id
group by mr.user_id
order by count(mr.rating) desc, u.name
limit 1)


union all

(SELECT m.title AS results
FROM MovieRating mr
JOIN Movies m
    ON mr.movie_id = m.movie_id
WHERE LEFT(mr.created_at, 7) = '2020-02'
GROUP BY mr.movie_id, m.title
ORDER BY AVG(mr.rating) DESC, m.title ASC
LIMIT 1)







