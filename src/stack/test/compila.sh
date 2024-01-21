#!/bin/sh
# This tiny detail strips from the argument the file extension,  keeping in name only the file name.
# I reuse the filename to find the test files for each function i want to test the file name 
name=${1%.c}
norminette -R CheckForbiddenSourceHeader $1
gcc -Wall -Wextra -Werror  -c $1 -I../../../inc/

uname_out=$(uname -s)

echo $uname_out | cat -e

if [ "$uname_out" = Linux ]
then
	cc  -g -Wall -Wextra -Werror -o $name $name.o  -L../../../lib/ -l:libftprintf.a -l:libpss.a
elif [ $(uname -s) == Darwin ]; then
	cc  -g -Wall -Wextra -Werror -o $name $name.o  -L../../../lib/ -lftprintf -lpss
fi

./$name
