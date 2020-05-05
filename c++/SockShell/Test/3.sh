#!/bin/bash

read -t 30 -p "Plese input your name:" name
echo "Your name is:"$name
read -t 30 -s -p "Plese input your age" age
echo -e "\nYour age is $age"
read -n 1 -t 30 -p "Please select your sex[m/f]" gender
echo -e "\n"
echo "Sex is $gender"
