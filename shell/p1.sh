#! /bin/bash

# 简单的输入输出

#数组
name[0]=Logan
name[1]=Mike

echo "Hello `whoami` !"
echo "Your name is ${name[0]}, and your friend is ${name[1]}"

#input
read -p "What do you like?" like
echo "Yeah I see, you like ${like}"

