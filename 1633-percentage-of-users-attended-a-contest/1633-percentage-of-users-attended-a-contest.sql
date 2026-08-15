# Write your MySQL query statement below
SELECT
    contest_id,
    ROUND(COUNT(user_id) * 100.0 /u.total_users,2) 
        AS percentage
FROM Register
cross join (
    select count(*) as total_users from Users
) u
GROUP BY contest_id
ORDER BY percentage DESC, contest_id;
