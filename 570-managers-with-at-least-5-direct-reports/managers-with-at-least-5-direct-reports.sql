-- Write your PostgreSQL query statement below
SELECT e.name
FROM Employee AS e 
INNER JOIN Employee AS m ON e.id=m.managerId 
GROUP BY e.name,m.managerId 
HAVING COUNT(m.managerId) >= 5