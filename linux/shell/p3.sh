#! /bin/bash

echo "Input two numbers"

read x y
((z=x+y))
if [[ z -gt 10 ]] # gt:大于 lt:小于
then
	echo "x+y>10"
else
	echo "x+y<=10"
fi

((x*=y))
((x%=5))

if [[ x -le 100 || z -ne 0 ]] # or
then
	echo "x*y<100 or (x+y)%5!=0"
fi

echo "Your current directory is `pwd`"
echo "Input a filename ->"
read name
filename=${name:=./}

if [[ -r $filename && -f $filename ]]   # 是文件就查看当前文件
then
	cat $filename
elif [[ -d $filename && -x $filename ]] # 是目录就查看当前目录的文件个数
then
	cd $filename
	ls -l | wc -l
else # 文件不存在
	echo "bad file name"
fi

