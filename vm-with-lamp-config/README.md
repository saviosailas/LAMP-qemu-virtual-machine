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

#### Try starting mariaDB

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

```
