(
    SELECT u.name AS results
    FROM Users u
    JOIN MovieRating m
        ON u.user_id = m.user_id
    GROUP BY u.user_id, u.name
    ORDER BY COUNT(*) DESC, u.name
    LIMIT 1
)

UNION ALL

(
    SELECT mov.title AS results
    FROM Movies mov
    JOIN MovieRating m
        ON mov.movie_id = m.movie_id
    WHERE m.created_at >= '2020-02-01'
      AND m.created_at < '2020-03-01'
    GROUP BY mov.movie_id, mov.title
    ORDER BY AVG(m.rating) DESC, mov.title
    LIMIT 1
);