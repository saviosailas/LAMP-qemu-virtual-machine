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

