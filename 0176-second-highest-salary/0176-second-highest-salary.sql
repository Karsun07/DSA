SELECT
    CASE
        WHEN (SELECT COUNT(*) FROM Employee) = 1 THEN NULL
        ELSE MAX(CASE WHEN t.rnk = 2 THEN t.salary END)
    END AS SecondHighestSalary
FROM (
    SELECT
        salary,
        DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
    FROM Employee
) t;