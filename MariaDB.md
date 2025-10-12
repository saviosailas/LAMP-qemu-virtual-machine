### connect to MariaDB server
```bash
mysql -u root -p

# mysql -u root -p your_database_name
```

### List all databses

```sql
show databases;
```

```bash
MariaDB [(none)]> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| sys                |
| user_db            |
+--------------------+
5 rows in set (0.057 sec)
```
### Select database

```sql
use your_database;
```

```bash
MariaDB [(none)]> use user_db;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
```

### Current database

```sql
select database();
```

```bash
MariaDB [(none)]> select database();
+------------+
| database() |
+------------+
| NULL       |
+------------+
1 row in set (0.003 sec)
```

### List tables

```sql
show tables;
```
```sql
show tables from your_database;
```

```bash
MariaDB [user_db]> show tables;
+-------------------+
| Tables_in_user_db |
+-------------------+
| user_info         |
+-------------------+
1 row in set (0.006 sec)
```

### List columns

```sql
show columns from your_table_name;
```
```sql
show columns from your_table_name from your_database;
```

```bash
MariaDB [user_db]> show columns from user_info;
+-----------+--------------+------+-----+---------+----------------+
| Field     | Type         | Null | Key | Default | Extra          |
+-----------+--------------+------+-----+---------+----------------+
| roll_numb | int(11)      | NO   | PRI | NULL    | auto_increment |
| name      | varchar(80)  | NO   |     | NULL    |                |
| age       | int(3)       | NO   |     | NULL    |                |
| class     | varchar(100) | NO   |     | NULL    |                |
+-----------+--------------+------+-----+---------+----------------+
4 rows in set (0.013 sec)
```

### fetch data from table

```sql
select * from your_table;
```

```bash
MariaDB [user_db]> select * from user_info;
+-----------+-------+-----+------------------------+
| roll_numb | name  | age | class                  |
+-----------+-------+-----+------------------------+
|         1 | savio |  28 | B.Sc. computer science |
+-----------+-------+-----+------------------------+
1 row in set (0.002 sec)
```




