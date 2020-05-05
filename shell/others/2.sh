#!/bin/bash
# for i in "$*"
#	do
#		echo "The parameters is:$i"
#	done
 x=1
 for y in "$@"
	do
		echo "The parameter$x is:$y"
		x=$(($x+1))
	done
