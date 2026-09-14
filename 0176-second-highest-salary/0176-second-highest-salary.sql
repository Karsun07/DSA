select max(t.salary) as SecondHighestSalary
from (
    select salary,
dense_rank() over(order by salary desc) as rnk
from Employee
) t
where t.rnk=2
