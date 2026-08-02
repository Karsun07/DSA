SELECT 
    s.user_id,round(
        coalesce(sum(c.action='confirmed')/count(c.action),0)
        ,2) AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c
ON s.user_id = c.user_id
GROUP BY s.user_id;