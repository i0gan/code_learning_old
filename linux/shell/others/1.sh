#!/bin/bash
echo "Please you input two number!"
num1=$1
num2=$2
num3=$*
num4=$@
num5=$#
total=$(($num1+$num2))
echo -e "\e[1;37m OK: \e[0m"
echo $total
echo $num3
echo $num4
echo $num5
