-- Last updated: 8/31/2025, 10:49:48 AM
# Write your MySQL query statement below
SELECT name
FROM Customer
WHERE referee_id!=2 OR referee_id is null;