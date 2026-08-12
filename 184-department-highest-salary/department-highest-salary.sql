# Write your MySQL query statement below
SELECT d.name as Department,
e.name as Employee,
e. salary as salary
From Employee e 
INNER JOIN DEPARTMENT d
ON e.departmentID = d.id
where e.salary = 
(SELECT MAX( salary) FROM
EMPLOYEE
where departmentId = e.departmentId
);
