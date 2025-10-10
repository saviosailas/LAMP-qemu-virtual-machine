### _Alpine Linux 3.20

https://dl-cdn.alpinelinux.org/alpine/v3.20/community/x86_64/

```bash
localhost:~# free -h
              total        used        free      shared  buff/cache   available
Mem:         721.4M       60.7M      618.2M      108.0K       42.4M      583.9M
Swap:       1024.0M           0     1024.0M
```

```bash
localhost:~# df -h
Filesystem                Size      Used Available Use% Mounted on
devtmpfs                 10.0M         0     10.0M   0% /dev
shm                     360.7M         0    360.7M   0% /dev/shm
/dev/vda3                 2.6G     57.0M      2.4G   2% /
tmpfs                   144.3M    108.0K    144.2M   0% /run
/dev/vda1               271.1M     24.0M    228.1M  10% /boot
tmpfs                   360.7M         0    360.7M   0% /tmp
```

APK respository
```
vi /etc/apk/repositories
```
```bash
#/media/cdrom/apks
http://foobar.turbo.net.id/alpine/v3.20/main
http://foobar.turbo.net.id/alpine/v3.20/community
```

Install Apache2
```
apk add apache2
```

Start service
```bash
localhost:~# rc-service apache2 start
 * Caching service dependencies ...                                               [ ok ]
 * Starting apache2 ...
AH00558: httpd: Could not reliably determine the server's fully qualified domain name, using ::1. Set the 'ServerName' directive globally to suppress this message        [ ok ]
```

PhpMyAdmin
```
localhost:~# apk add phpmyadmin
(1/47) Installing php83-common (8.3.15-r0)
(2/47) Installing argon2-libs (20190702-r5)
(3/47) Installing libxml2 (2.12.10-r0)
(4/47) Installing php83 (8.3.15-r0)
(5/47) Installing php83-openssl (8.3.15-r0)
(6/47) Installing php83-mysqlnd (8.3.15-r0)
(7/47) Installing php83-mysqli (8.3.15-r0)
(8/47) Installing libbz2 (1.0.8-r6)
(9/47) Installing php83-bz2 (8.3.15-r0)
(10/47) Installing php83-ctype (8.3.15-r0)
(11/47) Installing ca-certificates (20250911-r0)
(12/47) Installing brotli-libs (1.1.0-r2)
(13/47) Installing c-ares (1.33.1-r0)
(14/47) Installing libunistring (1.2-r0)
(15/47) Installing libidn2 (2.3.7-r0)
(16/47) Installing nghttp2-libs (1.62.1-r0)
(17/47) Installing libpsl (0.21.5-r1)
(18/47) Installing libcurl (8.14.1-r2)
(19/47) Installing php83-curl (8.3.15-r0)
(20/47) Installing libxau (1.0.11-r4)
(21/47) Installing libmd (1.1.0-r0)
(22/47) Installing libbsd (0.12.2-r0)
(23/47) Installing libxdmcp (1.1.5-r1)
(24/47) Installing libxcb (1.16.1-r0)
(25/47) Installing libx11 (1.8.9-r1)
(26/47) Installing libxext (1.3.6-r2)
(27/47) Installing libice (1.1.1-r6)
(28/47) Installing libsm (1.2.4-r4)
(29/47) Installing libxt (1.3.0-r5)
(30/47) Installing libxpm (3.5.17-r0)
(31/47) Installing aom-libs (3.9.1-r0)
(32/47) Installing libdav1d (1.4.2-r0)
(33/47) Installing libsharpyuv (1.3.2-r0)
(34/47) Installing libavif (1.0.4-r0)
(35/47) Installing libpng (1.6.44-r0)
(36/47) Installing freetype (2.13.2-r0)
(37/47) Installing libjpeg-turbo (3.0.3-r0)
(38/47) Installing libwebp (1.3.2-r0)
(39/47) Installing php83-gd (8.3.15-r0)
(40/47) Installing oniguruma (6.9.9-r0)
(41/47) Installing php83-mbstring (8.3.15-r0)
(42/47) Installing php83-session (8.3.15-r0)
(43/47) Installing libzip (1.10.1-r0)
(44/47) Installing php83-zip (8.3.15-r0)
(45/47) Installing php83-xmlwriter (8.3.15-r0)
(46/47) Installing php83-iconv (8.3.15-r0)
(47/47) Installing phpmyadmin (5.2.2-r0)
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
OK: 175 MiB in 109 packages
```
