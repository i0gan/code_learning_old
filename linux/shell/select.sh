#! /bin/bash

while true
do
select menuItem in Show List File Exit
do
	case "$menuItem" in
		Show)
			date
			pwd
			break;;

		List)
			who
			break;;

		File)
			ls -al;;

		Exit)
			exit;;
		*)
			;;
	esac
done
done
			
