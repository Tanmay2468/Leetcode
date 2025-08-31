-- Last updated: 8/31/2025, 10:49:16 AM
# Write your MySQL query statement below
select unique_id,name from Employees left join EmployeeUNI on EmployeeUNI.id=Employees.id;