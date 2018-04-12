-- drop table Employee;
-- Create table If Not Exists Employee (
--   Id        int,
--   Name      varchar(255),
--   Salary    int,
--   ManagerId int NULL
-- );
-- Truncate table Employee;
-- insert into Employee (Id, Name, Salary, ManagerId) values ('1', 'Joe', '70000', '3');
-- insert into Employee (Id, Name, Salary, ManagerId) values ('2', 'Henry', '80000', '4');
-- insert into Employee (Id, Name, Salary, ManagerId) values ('3', 'Sam', '60000', NULL);
-- insert into Employee (Id, Name, Salary, ManagerId) values ('4', 'Max', '90000', NULL);

select a.Name as Employee
from Employee as a
  join Employee as b
where a.ManagerId = b.Id && a.Salary > b.Salary;
