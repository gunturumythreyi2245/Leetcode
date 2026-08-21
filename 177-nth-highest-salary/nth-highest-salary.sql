CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  -- Create a variable to hold the offset value
  DECLARE M INT;
  SET M = N - 1;
  
  RETURN (
      # Write your T-SQL query statement below.
      SELECT DISTINCT salary 
      FROM Employee
      ORDER BY salary DESC
      LIMIT 1 OFFSET M
  );
END
