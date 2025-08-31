-- Last updated: 8/31/2025, 10:49:24 AM
# Write your MySQL query statement below
select distinct author_id as id from Views where author_id=viewer_id order by author_id asc;