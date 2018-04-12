Create table If Not Exists courses (
  student varchar(255),
  class   varchar(255)
);
Truncate table courses;
insert into courses (student, class) values ('A', 'Math');
insert into courses (student, class) values ('B', 'English');
insert into courses (student, class) values ('C', 'Math');
insert into courses (student, class) values ('D', 'Biology');
insert into courses (student, class) values ('E', 'Math');
insert into courses (student, class) values ('F', 'Computer');
insert into courses (student, class) values ('G', 'Math');
insert into courses (student, class) values ('H', 'Math');
insert into courses (student, class) values ('I', 'Math');

-- # 要防止学生重复。

select a.class
FROM (
       select DISTINCT
         student,
         class,
         COUNT(*)
       from courses as a
       GROUP BY class, student) a # 先按照课程进行排序，然后去重！
GROUP BY a.class
HAVING COUNT(*) >= 5