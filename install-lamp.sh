#!/bin/sh

set -e

echo "=== Updating Alpine and installing packages ==="
apk update
apk upgrade

# Install Apache, PHP 8.3 (php83), and MySQL (mariadb)
echo "=== Installing Apache, PHP 8.3, MariaDB ==="
apk add apache2 php83 php83-apache2 php83-mysqli php83-mbstring php83-session php83-json php83-openssl php83-pdo php83-pdo_mysql php83-zlib mariadb mariadb-client wget unzip

# Enable and start Apache
echo "=== Enabling and starting Apache ==="
rc-update add apache2
rc-service apache2 start

# Enable and start MariaDB
echo "=== Enabling and starting MariaDB ==="
rc-update add mariadb
rc-service mariadb setup
rc-service mariadb start

# Secure MariaDB (optional: auto secure with no password, for testing)
echo "=== Securing MariaDB ==="
mysql -e "UPDATE mysql.user SET Password=PASSWORD('root') WHERE User='root';"
mysql -e "DELETE FROM mysql.user WHERE User='';"
mysql -e "DROP DATABASE IF EXISTS test;"
mysql -e "FLUSH PRIVILEGES;"

# Create phpMyAdmin directory
echo "=== Downloading and setting up phpMyAdmin ==="
mkdir -p /var/www/localhost/htdocs/phpmyadmin
cd /var/www/localhost/htdocs/phpmyadmin

# Download latest phpMyAdmin (can change version here)
PHPMYADMIN_VERSION="5.2.1"
wget https://files.phpmyadmin.net/phpMyAdmin/${PHPMYADMIN_VERSION}/phpMyAdmin-${PHPMYADMIN_VERSION}-all-languages.zip
unzip phpMyAdmin-${PHPMYADMIN_VERSION}-all-languages.zip
mv phpMyAdmin-${PHPMYADMIN_VERSION}-all-languages/* .
rm -rf phpMyAdmin-${PHPMYADMIN_VERSION}-all-languages*
chown -R apache:apache /var/www/localhost/htdocs/phpmyadmin

# Configure PHP if needed (e.g., timezone)
echo "=== Configuring PHP timezone ==="
echo "date.timezone = UTC" >>/etc/php83/php.ini

# Restart Apache to load PHP module
echo "=== Restarting Apache ==="
rc-service apache2 restart

echo ""
echo "=== DONE! ==="
echo "You can now access phpMyAdmin at: http://localhost/phpmyadmin"
echo "MariaDB root password is: root"
