#!/bin/bash
inf=500
a=1
Delete_object(){
	let a=a+1
	if [ $a -gt $inf ];then
		return
	fi
	find $1  ! -name "*.cpp" ! -name "*.sh"  ! -name "*.pdf" ! -name "*.txt" -type f  -exec rm {} \;
	for file in $1
	do
        if test -d $file
		then
			Delete_object $file
		fi
	done
}
Delete_object ./