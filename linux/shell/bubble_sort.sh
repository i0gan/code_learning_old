#! /bin/bash
# 实现功能为冒泡排序

arr=(52 39 68 94 75 6 31 43)
len=${#arr[@]}
for (( i=0; i<$[$len - 1]; i=i+1)); do
	for (( j=0; j<$[$len - $i - 1]; j=j+1)); do
		if [ ${arr[$j]} -gt ${arr[$[$j+1]]} ]; then
			temp=${arr[$j]}
			arr[$j]=${arr[$[$j+1]]}
			arr[$[$j+1]]=$temp
		fi	
	done
done

# 打印排序后的arr
for i in "${arr[@]}"; do
	echo -n "$i "
done
