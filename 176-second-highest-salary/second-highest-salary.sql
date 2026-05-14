WITH SalaryRank AS (
    SELECT 
        salary,
        DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
    FROM Employee
)

SELECT 
    MAX(salary) AS SecondHighestSalary
FROM SalaryRank
WHERE rnk = 2;