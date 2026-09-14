SELECT d.name as Department, t.name as Employee, t.salary
FROM (
    SELECT *,
           DENSE_RANK() OVER (
               PARTITION BY departmentId
               ORDER BY salary DESC
           ) AS rnk
    FROM Employee
) t
JOIN Department d
    ON t.departmentId = d.id
WHERE t.rnk < 4
ORDER BY t.departmentId;