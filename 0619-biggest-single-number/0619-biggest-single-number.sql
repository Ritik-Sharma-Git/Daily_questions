# Write your MySQL query statement below
SELECT MAX(num) as num FROM (SELECT num from Mynumbers group by 1 having count(1)=1) as t;