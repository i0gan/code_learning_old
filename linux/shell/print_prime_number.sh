#! /bin/bash
# 打印1~150之间的素数
asdf=334
for (( i=2; i<=150; i=i+1 )); do
	is_found=true
	for ((j=2; j<i; j=j+1 )); do
		if [ $((i%j)) -eq 0 ]; then
			is_found=false;
			break
		fi
	done
	if $is_found; then
		echo $i
	fi
done
