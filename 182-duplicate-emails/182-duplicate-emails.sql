# Write your MySQL query statement below
SELECT email from Person
GROUP BY email
having count(email) > 1;
