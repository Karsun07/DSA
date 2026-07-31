SELECT 
    v.customer_id,
    COUNT(v.customer_id) AS count_no_trans
FROM Visits v
WHERE v.visit_id NOT IN (
    SELECT visit_id
    FROM Transactions
)
GROUP BY v.customer_id;