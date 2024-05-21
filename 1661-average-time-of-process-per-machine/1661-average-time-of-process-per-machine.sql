# Write your MySQL query statement below
SELECT a1.machine_id , ROUND(AVG(a2.timestamp - a1.timestamp),3) as processing_time  FROM Activity a1 
JOIN Activity a2 
ON a1.process_id = a2.process_id
WHERE a2.activity_type = 'end' 
  AND a1.activity_type = 'start' 
  and a1.process_id = a2.process_id 
  and  a1.machine_id = a2.machine_id
GROUP BY a1.machine_id