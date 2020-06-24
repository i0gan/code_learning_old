#!/bin/bash

# seq 是制定数的范围进行打印
for i in `seq 1 100`;do
	echo -e "\033[32m$i\033[0m"
done
