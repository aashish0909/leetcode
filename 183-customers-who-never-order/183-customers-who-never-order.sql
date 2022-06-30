# Write your MySQL query statement below
SELECT Name as Customers FROM Customers WHERE id NOT IN (SELECT customerId FROM Orders)