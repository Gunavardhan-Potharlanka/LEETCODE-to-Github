# Write your MySQL query statement below
SELECT PERSON.firstName, PERSON.lastName, ADDRESS.city, ADDRESS.state FROM PERSON LEFT JOIN ADDRESS ON PERSON.personId = ADDRESS.personId