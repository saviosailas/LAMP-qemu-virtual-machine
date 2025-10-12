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
