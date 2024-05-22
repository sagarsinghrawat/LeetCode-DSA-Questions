# Write your MySQL query statement below


Select d.name as Department, e.name as Employee, e.salary as Salary
from Employee e
join Department d
on e.departmentId = d.id
where e.salary = ( select max(Salary) from Employee t where t.departmentId = e.departmentId)