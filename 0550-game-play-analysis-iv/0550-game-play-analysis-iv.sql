SELECT
    ROUND(
        COUNT(DISTINCT t.player_id) /
        (SELECT COUNT(DISTINCT player_id) FROM Activity),
        2
    ) AS fraction
FROM (
    SELECT player_id, event_date
    FROM Activity
    WHERE (player_id, DATE_SUB(event_date, INTERVAL 1 DAY))
    IN (
        SELECT
            a.player_id,
            MIN(a.event_date)
        FROM Activity a
        GROUP BY a.player_id
    )
) t;