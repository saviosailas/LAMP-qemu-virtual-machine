apk add apache2 phpmyadmin php83-apache2 mariadb mariadb-client
rc-update add apache2 default
rc-update add mariadb default
rc-service apache2 restart
# Initialize MySQL Data Directory. 
mariadb-install-db --user=mysql --datadir=/var/lib/mysql
rc-service mariadb start
mysql_secure_installation <<EOF
> 
> y
> secret
> secret
> y
> y
> y
> y
> EOF

mysql -u root -r "ALTER USER 'root'@'localhost' IDENTIFIED BT 'toor';"

