-- # Write your MySQL query statement below
SELECT
    LastName,
    FirstName,
    City,
    State
from
    Person
    left join Address on Person.PersonID = Address.PersonID;