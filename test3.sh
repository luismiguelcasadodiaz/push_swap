#!/bin/bash
for (( i=1; i<=9; i++ )) 
do
	ARG=$(seq 0 2 | sort -R | tr '\n' ' ')
	NUM=$(./push_swap $ARG | wc -l)
	if [ $(uname -s) = Linux ]
	then
		OK=$(./push_swap $ARG | ./checker_linux $ARG)
	elif [ $(uname -s) = Darwin ]
	then
		OK=$(./push_swap $ARG | ./checker_Mac $ARG)
	fi
	echo "$ARG ==> $OK [$NUM]"
done
