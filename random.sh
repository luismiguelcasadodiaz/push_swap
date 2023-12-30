#!/usr/bin/bash
#dd if=/dev/urandom of=./random_number count=$1 bs=1
#od -An  --format=dI ./random_number | tr '\n' ' ' | sed 's/  */ /g' | tr ' ' '\n'

od -An -N2 -i /dev/random | tee numbers

for (( c=1; c<$1; c++ ))
do
	od -An -N2 -i /dev/random | tee -a numbers
done

cat numbers |tr '\n' ' '| tr -s ' ' > input
rm numbers
cat input
