#!/bin/bash 

run=0

if [ $# -ne 1 ]; then
	echo "start"
	source $0 prvykrat
	#. $0 prvykrat
	echo "$var1"
	echo ""

	exec $0 druhykrat
	echo "$var2"
elif [ $1 == prvykrat ]; then
	var1=prvykrat
	echo "$var1 zo source"
elif [ $1 == druhykrat ]; then
	var2=druhykrat
	echo "$var2 z exec"
fi


