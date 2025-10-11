### This VM is configured with Apache2, MariaDB, PHP and phpMyAdmin

```bash
apk add apache2 phpmyadmin php83-apache2 mariadb mariadb-client
```


```bash
localhost:~# apk add apache2 phpmyadmin php83-apache2 mariadb mariadb-client
(1/65) Installing apr (1.7.5-r0)
(2/65) Installing libexpat (2.7.3-r0)
(3/65) Installing apr-util (1.6.3-r1)
(4/65) Installing pcre2 (10.43-r0)
(5/65) Installing apache2 (2.4.65-r0)
Executing apache2-2.4.65-r0.pre-install
(6/65) Installing apache2-openrc (2.4.65-r0)
(7/65) Installing mariadb-common (10.11.14-r0)
(8/65) Installing libaio (0.3.113-r2)
(9/65) Installing ca-certificates (20250911-r0)
(10/65) Installing brotli-libs (1.1.0-r2)
(11/65) Installing c-ares (1.33.1-r0)
(12/65) Installing libunistring (1.2-r0)
(13/65) Installing libidn2 (2.3.7-r0)
(14/65) Installing nghttp2-libs (1.62.1-r0)
(15/65) Installing libpsl (0.21.5-r1)
(16/65) Installing libcurl (8.14.1-r2)
(17/65) Installing libgcc (13.2.1_git20240309-r1)
(18/65) Installing skalibs (2.14.1.1-r0)
(19/65) Installing utmps-libs (0.1.2.2-r1)
(20/65) Installing linux-pam (1.6.0-r0)
(21/65) Installing libstdc++ (13.2.1_git20240309-r1)
(22/65) Installing libxml2 (2.12.10-r0)
(23/65) Installing mariadb (10.11.14-r0)
Executing mariadb-10.11.14-r0.pre-install
(24/65) Installing mariadb-openrc (10.11.14-r0)
(25/65) Installing libbz2 (1.0.8-r6)
(26/65) Installing perl (5.38.5-r0)
(27/65) Installing mariadb-client (10.11.14-r0)
(28/65) Installing php83-common (8.3.15-r0)
(29/65) Installing argon2-libs (20190702-r5)
(30/65) Installing php83-apache2 (8.3.15-r0)
(31/65) Installing php83 (8.3.15-r0)
(32/65) Installing php83-openssl (8.3.15-r0)
(33/65) Installing php83-mysqlnd (8.3.15-r0)
(34/65) Installing php83-mysqli (8.3.15-r0)
(35/65) Installing php83-bz2 (8.3.15-r0)
(36/65) Installing php83-ctype (8.3.15-r0)
(37/65) Installing php83-curl (8.3.15-r0)
(38/65) Installing libxau (1.0.11-r4)
(39/65) Installing libmd (1.1.0-r0)
(40/65) Installing libbsd (0.12.2-r0)
(41/65) Installing libxdmcp (1.1.5-r1)
(42/65) Installing libxcb (1.16.1-r0)
(43/65) Installing libx11 (1.8.9-r1)
(44/65) Installing libxext (1.3.6-r2)
(45/65) Installing libice (1.1.1-r6)
(46/65) Installing libsm (1.2.4-r4)
(47/65) Installing libxt (1.3.0-r5)
(48/65) Installing libxpm (3.5.17-r0)
(49/65) Installing aom-libs (3.9.1-r0)
(50/65) Installing libdav1d (1.4.2-r0)
(51/65) Installing libsharpyuv (1.3.2-r0)
(52/65) Installing libavif (1.0.4-r0)
(53/65) Installing libpng (1.6.44-r0)
(54/65) Installing freetype (2.13.2-r0)
(55/65) Installing libjpeg-turbo (3.0.3-r0)
(56/65) Installing libwebp (1.3.2-r0)
(57/65) Installing php83-gd (8.3.15-r0)
(58/65) Installing oniguruma (6.9.9-r0)
(59/65) Installing php83-mbstring (8.3.15-r0)
(60/65) Installing php83-session (8.3.15-r0)
(61/65) Installing libzip (1.10.1-r0)
(62/65) Installing php83-zip (8.3.15-r0)
(63/65) Installing php83-xmlwriter (8.3.15-r0)
(64/65) Installing php83-iconv (8.3.15-r0)
(65/65) Installing phpmyadmin (5.2.2-r0)
Executing phpmyadmin-5.2.2-r0.post-install
*
* phpmyadmin has been installed to:
*     /usr/share/webapps/phpmyadmin
* phpmyadmin config file has been installed to:
*     /etc/phpmyadmin/config.inc.php
* If you use apache2:
*     1) Change the ownership of the config directory:
*            chown -R apache:apache /etc/phpmyadmin
*     2) See if you need to modify the apache2 config:
*            /etc/apache2/conf.d/phpmyadmin.conf
*     3) Restart apache2 when done.
*
Executing busybox-1.36.1-r30.trigger
Executing ca-certificates-20250911-r0.trigger
OK: 429 MiB in 121 packages
```

### auto start service at 'default'
```bash
rc-update add apache2 default
```

```bash
localhost:~# rc-update add apache2 default
 * service apache2 added to runlevel default

```

```bash
rc-update add mariadb default
```

```bash
localhost:~# rc-update add mariadb default
 * service mariadb added to runlevel default
```

### Restart MariaDB service
```bash
rc-service mariadb restart
```

```bash
localhost:~# rc-service mariadb status
 * status: stopped
localhost:~# rc-serice mariadb start
-sh: rc-serice: not found
localhost:~# rc-service mariadb start
 * Starting mariadb ...
251011 10:55:21 mysqld_safe Logging to syslog.
251011 10:55:21 mysqld_safe Starting mariadbd daemon with databases from /var/lib/mysql      [ ok ]
```


### Restart apache server
```bash
rc-service apache2 restart
```

```bash
localhost:~# rc-service apache2 restart
 * Caching service dependencies ...                                                                                                                    [ ok ]
 * Starting apache2 ...
AH00558: httpd: Could not reliably determine the server's fully qualified domain name, using ::1. Set the 'ServerName' directive globally to suppress this message
```

#### Initialize mariaDB

```bash
rc-service mariadb status
```

```bash
 * status: stopped
localhost:~# rc-service mariadb start
 * Datadir '/var/lib/mysql' is empty or invalid.
 * Run '/etc/init.d/mariadb setup' to create new database.
 * ERROR: mariadb failed to start
```

```bash
# Initialize MySQL Data Directory. 
mariadb-install-db --user=mysql --datadir=/var/lib/mysql
```


```bash
rc-service mariadb start
```

```bash
localhost:~# rc-service mariadb start
 * Starting mariadb ...
251011 10:55:21 mysqld_safe Logging to syslog.
251011 10:55:21 mysqld_safe Starting mariadbd daemon with databases from /var/lib/mysql      [ ok ]
```


### Secure database (Add root user password)

```bash
mariadb-secure-installation
```

```bash
localhost:~# mysql_secure_installation <<EOF
> 
> y
> secret
> secret
> y
> y
> y
> y
> EOF

NOTE: RUNNING ALL PARTS OF THIS SCRIPT IS RECOMMENDED FOR ALL MariaDB
      SERVERS IN PRODUCTION USE!  PLEASE READ EACH STEP CAREFULLY!

In order to log into MariaDB to secure it, we'll need the current
password for the root user. If you've just installed MariaDB, and
haven't set the root password yet, you should just press enter here.

stty: standard input: Not a tty
Enter current password for root (enter for none): 
stty: standard input: Not a tty
OK, successfully used password, moving on...

Setting the root password or using the unix_socket ensures that nobody
can log into the MariaDB root user without the proper authorisation.

You already have your root account protected, so you can safely answer 'n'.

Switch to unix_socket authentication [Y/n] Enabled successfully!
Reloading privilege tables..
 ... Success!


You already have your root account protected, so you can safely answer 'n'.

Change the root password? [Y/n] You already have your root account protected, so you can safely answer 'n'.

Change the root password? [Y/n] You already have your root account protected, so you can safely answer 'n'.

Change the root password? [Y/n] stty: standard input: Not a tty
New password: 
Re-enter new password: 
stty: standard input: Not a tty
Password updated successfully!
Reloading privilege tables..
 ... Success!


By default, a MariaDB installation has an anonymous user, allowing anyone
to log into MariaDB without having to have a user account created for
them.  This is intended only for testing, and to make the installation
go a bit smoother.  You should remove them before moving into a
production environment.

Remove anonymous users? [Y/n]  ... Success!

Normally, root should only be allowed to connect from 'localhost'.  This
ensures that someone cannot guess at the root password from the network.

Disallow root login remotely? [Y/n]  ... Success!

By default, MariaDB comes with a database named 'test' that anyone can
access.  This is also intended only for testing, and should be removed
before moving into a production environment.

Remove test database and access to it? [Y/n]  - Dropping test database...
 ... Success!
 - Removing privileges on test database...
 ... Success!

Reloading the privilege tables will ensure that all changes made so far
will take effect immediately.

Reload privilege tables now? [Y/n]  ... Success!

Cleaning up...

All done!  If you've completed all of the above steps, your MariaDB
installation should now be secure.

Thanks for using MariaDB!
```

### Setup password for MariaDB

```bash
mysql -u root -r "ALTER USER 'root'@'localhost' IDENTIFIED BT 'toor';"
```


### Reset password if you forgot the MariaDB password ***

#### 1. Stop MariaDB
```bash
rc-service mariadb stop
```

```bash
localhost:~# rc-service mariadb stop
 * Stopping mariadb ...                                                                      [ ok ]
```

#### 2. start MariaDB in safe mode 

```bash
mysql_safe --skip-grant-tables &
```

```bash
localhost:~# mysqld_safe --skip-grant-tables &
localhost:~# 251011 11:24:54 mysqld_safe Logging to '/var/lib/mysql/localhost.err'.
251011 11:24:54 mysqld_safe Starting mariadbd daemon with databases from /var/lib/mysql
```

#### 3. Login in as root without passsword (In new terminal)
```bash
mysql -u root
```

```bash
localhost:~#  mysql -u root
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 3
Server version: 10.11.14-MariaDB Alpine Linux

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]>
```

#### 4. Update root password 
```sql
ALTER USER 'root'@'localhost' IDENTIFIED BY 'toor';
```


```sql
FLUSH PRIVILEGES;
```

```sql
quit;
```



```
```
```sql
MariaDB [(none)]>   ALTER USER 'root'@'localhost' IDENTIFIED BY 'new_secure_password';
ERROR 1290 (HY000): The MariaDB server is running with the --skip-grant-tables option so it cannot execute this statement


MariaDB [(none)]>   FLUSH PRIVILEGES;
Query OK, 0 rows affected (0.016 sec)


MariaDB [(none)]>   quit;
```


#### 5. shutdown MariaDB

```bash
mysqladmin -u root -p shutdown
```


```bash
localhost:~# mysqladmin -u root -p shutdown
Enter password: 
```


#### 6. Start MariaDB service
```bash
rc-service mariadb start
```

```bash
localhost:~# rc-service mariadb start
 * Starting mariadb ...
251011 11:27:12 mysqld_safe Logging to syslog.
251011 11:27:12 mysqld_safe Starting mariadbd daemon with databases from /var/lib/mysql     [ ok ]
```


## htdocs at /var/www/localhost/htdocs


```
