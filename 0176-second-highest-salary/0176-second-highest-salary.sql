# Write your MySQL query statement below
select
(
SELECT salary AS SecondHighestSalary
FROM Employee
WHERE id NOT IN
(
    SELECT id
    FROM Employee
    WHERE salary = (
        SELECT MAX(salary)
        FROM Employee
    )
)
order by salary desc
limit 1
) as SecondHighestSalary
