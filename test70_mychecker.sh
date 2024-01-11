#!/bin/bash
for (( i=1; i<=1; i++ )) 
do
	ARG=$(seq 0 5000 | sort -R | head -70 |  tr '\n' ' ')
	NUM=$(./push_swap $ARG | wc -l)
	if [ $(uname -s) = Linux ]
	then
		OK=$(./push_swap $ARG | ./checker $ARG)
	elif [ $(uname -s) = Darwin ]
	then
		OK=$(./push_swap $ARG | ./checker $ARG)
	fi
	echo "$ARG ==> $OK [$NUM]"
done
