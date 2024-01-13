#!/usr/bin/bash

#generates $1 random numbers of 1 byte (-N1) from /dev /random
#USAGE ./random.sh 7 
# generates seven integers 
# NUmbers maybe not unique
#dd if=/dev/urandom of=./random_number count=$1 bs=1
#od -An  --format=dI ./random_number | tr '\n' ' ' | sed 's/  */ /g' | tr ' ' '\n'

od -An -N1 -i /dev/random | tee numbers

for (( c=1; c<$1; c++ ))
do
	od -An -N1 -i /dev/random | tee -a numbers
done

cat numbers |tr '\n' ' '| tr -s ' ' > input
rm numbers
export ARG=$(cat input)
rm input

echo $ARG
