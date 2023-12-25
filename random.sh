#!/usr/bin/sh
dd if=/dev/urandom of=./random_number count=$1 bs=1
od -An --format=dI ./random_number 

