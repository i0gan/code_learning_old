#! /bin/bash
# expr 求和运算
# 采用 sh -x for2.sh 可以看执行过程
sum=0
for ((i=1; i <=100; i++))
do
	sum=`expr $i +  $sum`
done
	echo "1 + ... + 100 = $sum"
