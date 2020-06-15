#!/bin/bash
# Auto backup mysql database
# define backup path

BACK_DIR=./mysql/backup/`date +%Y%m%d`
MYSQL_DB=ltalk
MYSQL_USER=ltalk
MYSQL_PASSWD=123456
MYSQL_CMD=/usr/bin/mysqldump

if [ $UID -ne 0 ]; then
	echo "Must be root exec shell script"
	exit
fi


if [ ! -d $BACK_DIR ];then
	mkdir -p $BACK_DIR
else
	echo "This { $BACK_DIR } is existed!"
fi

# Mysql backup
$MYSQL_CMD -u$MYSQL_USER -p$MYSQL_PASSWD -d $MYSQL_DB > $BACK_DIR/$MYSQL_DB.db

# Print result info
if [ $? -eq 0 ];then
	echo -e "\033[32mThe mysql backup [$MYSQL_DB Successfully!\033[0m"
else
	echo -e "\033[32mThe mysql backup [$MYSQL_DB Failed!\033[0m"
fi



