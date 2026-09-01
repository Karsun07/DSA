SELECT x.customer_id, COUNT(x.customer_id) AS count_no_trans
FROM
(
    SELECT v.customer_id,v.visit_id,t.transaction_id
    FROM Visits v
    LEFT JOIN Transactions t
        ON v.visit_id = t.visit_id
) AS x
WHERE x.transaction_id IS NULL
GROUP BY x.customer_id;