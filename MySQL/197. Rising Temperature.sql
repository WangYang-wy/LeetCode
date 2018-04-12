Create table If Not Exists Weather (
  Id          int,
  RecordDate  date,
  Temperature int
);
Truncate table Weather;
insert into Weather (Id, RecordDate, Temperature) values (1, '2015-01-01', 10);
insert into Weather (Id, RecordDate, Temperature) values (2, '2015-01-02', 25);
insert into Weather (Id, RecordDate, Temperature) values (3, '2015-01-03', 20);
insert into Weather (Id, RecordDate, Temperature) values (4, '2015-01-04', 30);

SELECT W1.Id
FROM Weather as W1 INNER JOIN Weather as W2
WHERE W1.Temperature > W2.Temperature and TO_DAYS(W1.RecordDate) = TO_DAYS(W2.RecordDate) + 1;