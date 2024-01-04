#!/usr/bin/bash

for (( i=1; i<=30; i++ )) 
do
	ARG=$(seq 0 4 | sort -R | tr '\n' ' ')
	echo $ARG
	./push_swap $ARG | ./checker_linux $ARG 
done
