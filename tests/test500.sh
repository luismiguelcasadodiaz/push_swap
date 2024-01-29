#!/bin/bash
for (( i=1; i<=3; i++ )) 
do
	ARG=$(seq 0 5000 | sort -R | head -500 | tr '\n' ' ')
	./push_swap $ARG
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
