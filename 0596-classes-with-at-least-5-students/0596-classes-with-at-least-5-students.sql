# Write your MySQL query statement below

select class 
from
(
select count(student) as stu, class 
from Courses
group by class
) as t
where t.stu>=5
