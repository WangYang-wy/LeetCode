drop table Person;
Create table If Not Exists Person (
  Id    int,
  Email varchar(255)
);
Truncate table Person;
insert into Person (Id, Email) values (1, 'a@b.com');
insert into Person (Id, Email) values (2, 'c@d.com');
insert into Person (Id, Email) values (3, 'a@b.com');
# insert into Person (Id, Email) values (4, 'c@d.com');

SELECT email
FROM Person
GROUP BY email
HAVING COUNT(*) > 1;