CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN  
SET N = N-1;

  RETURN (
      SELECT DISTINCT  salary FROM
      Employee
      ORDER BY salary DESC
      LIMIT 1 OFFSET N /*bc yaha pe leetcode mai bakchodi hai isliye upar set n= n-1 kar dya */

  );
END