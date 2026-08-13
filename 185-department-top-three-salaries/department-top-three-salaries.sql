/*
SELECT d.name as Department,
 e.name as Employee,
 e.salary as Salary
 FROM Employee e 
 INNER JOIN Department d
 on e.departmentId = d.id
 where (
    SELECT COUNT( DISTINCT salary)
    From Employee
    where departmentId = e.departmentId
    AND salary > e.salary

 ) < 3;
*/

/*using window function and rank*/
 with top3salary as (
    SELECT Employee.name as Employee,
    Department.name as Department,
     Employee.salary as Salary, 
    DENSE_RANK() OVER( PARTITION BY Department.id ORDER BY Salary DESC) as `rank`
    FROM Employee INNER JOIN Department on Employee.departmentId = Department.id
 )
 SELECT Department , Employee , Salary
 FROM top3salary
 where `rank` <=3;

