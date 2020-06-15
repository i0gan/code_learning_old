#! /bin/bash

# set 命令为位置参数赋值或重新赋值[1~9]
set a b c d e f
echo $1 $2 $3 $4 $5 $6

echo "use shift to move var"
shift
echo $1 $2 $3 $4 $5

echo "move 2"
shift 2
echo $1 $2 $3

# $#表示上一个命令的参数个数,不包含shell脚本本身
echo -e "\n\$# 参数个数"
echo $#

# $?:表示上一条命令执行后的返回值(也称为“返回码”“退出状态”“退出码”
#等),它是一个十进制数。多数 shell 命令执行成功时,返回值为 0;若执行失败,则返回
#非 0 值。shell 本身返回$?的当前值作为 shell 命令的退出状态
echo -e "\n\$? 上一条命令的返回值"
echo $?


# $$:表示当前进程的进程号. 每个进程都有唯一的进程号(即 PID)
echo -e "\n\$$ 进程号"
echo $$

# $!:表示上一个后台命令对应的进程号,是一个由 1~5 位数字构成的数字串
echo -e "\n\$! 上一个命令的进程号(退出就没有了)"
echo $!

# $-:是由当前 shell 设置的执行标志名组成的字符串. 例如,“set -xv”命令行给
#shell 设置标志-x 和-v(用于跟踪输出)
echo -e "\n\$- 标志名组成的字符串"
echo $-

# $*:表示在命令行中实际给出的所有实参字符串,并不仅限于 9 个实参
echo -e "\n\$* 实参字符串"
echo $* 

# $@: 与$*的功能基本相同,表示在命令行中给出的所有实参,但"$@"与"$*"不同
echo -e "\n\$@ 实参字符串"
echo $@ 

# 证实 $* 与$2不同
echo -e "\n证实 \$* 与\$2不同"

date
set `date`
echo -e "\n\$* print"
echo $*
for i in "$*"
	do
		echo $i;
	done
echo -e "\n\$@ print"
echo $@
for i in "$@"
	do
		echo $i;
	done

echo "end"

