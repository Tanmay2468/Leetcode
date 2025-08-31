-- Last updated: 8/31/2025, 10:49:45 AM
# Write your MySQL query statement below
SELECT *
FROM Cinema
WHERE id%2=1 AND description NOT LIKE "boring"
ORDER BY rating DESC;