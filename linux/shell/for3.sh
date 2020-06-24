#! /bin/bash
# 实现以当前.sh 文件打包

for i in `find . -name "*.sh"`
do
	#echo $i
	tar -czf $i.tgz $i
done

if (($1 == 0));then
	for j in `find . -name "*.tgz"`;do
		rm $j	
	done
fi
