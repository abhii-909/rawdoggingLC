CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) 
RETURNS TABLE (Salary INT) AS $$
BEGIN
    RETURN QUERY
    (
        WITH SalaryRank AS (
            SELECT DISTINCT
                e.salary,
                DENSE_RANK() OVER (ORDER BY e.salary DESC) AS rnk
            FROM Employee e
        )

        SELECT MAX(sr.salary) AS Salary
        FROM SalaryRank sr
        WHERE sr.rnk = N
    );
END;
$$ LANGUAGE plpgsql;