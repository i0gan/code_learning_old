#! /bin/bash
# 计算小于100的所有正偶数的和

sum=0

for ((i=2; i<100; i=i+1)); do
	if [ $((i%2)) -eq 0 ]; then
		sum=$((sum + i))
	fi
done

echo "sum: $sum"
