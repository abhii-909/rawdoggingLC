CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
    select salary
    from (
        select salary, Dense_rank()
        over (order by salary desc) as ranking
        from Employee
    ) as ranked_salaries
    where ranking = N
    limit 1
  );
END