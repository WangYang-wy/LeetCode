Create table If Not Exists Employee (Id int, Salary int);
Truncate table Employee;
insert into Employee (Id, Salary) values ('1', '100');
insert into Employee (Id, Salary) values ('2', '200');
insert into Employee (Id, Salary) values ('3', '300');

select * from Employee order by Salary;

select MAX(Salary) as SecondHighestSalary from Employee where Salary < (select MAX(Salary) from Employee);