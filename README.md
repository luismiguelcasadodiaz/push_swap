# push_swap
This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

Data to be sorted is made of integer values.

According to <limits.h>   INT_MIN = -2 147 483 648 and INT_MAX = +2 147 483 647.

## goal
Write a program in C called push_swap which calculates and displays on the standard output the **smallest** program, made of **Push swap language** instructions, that sorts the **integers** received as arguments.

Sorting values is simple. To sort them the fastest way possible is less simple. Especially because **from one integers configuration to another, the most efficient sorting solution can differ**.
 
In terms of 42, the word **smallest** requires clarification:

|numbers to sort| Max operations | Score|
|--------------:|---------------:|-----:|
|3              |3|
|5              |12| 
|100            |700|5|
|               |900|4|
|               |1100|3|
|               |1300|2|
|               |1500|1|
|500            |5500|5|
|               |7000|4|
|               |8500|3|
|               |10000|2|
|               |11500|1|

## rules
You have 2 stacks named a and b.

• At the beginning:
  ◦ The stack a contains a random amount of negative and/or positive numbers which **cannot be duplicated**.
  ◦ The stack b is empty.

• The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:

|code | operation| Description |
|-----|-----|--------------|
|sa| (swap a)| Swap the first 2 elements at the top of stack a.<br> Do nothing if there is only one or no elements.|
|sb| (swap b)| Swap the first 2 elements at the top of stack b.<br> Do nothing if there is only one or no elements.|
|ss| (swap a) and (swap b)| sa and sb at the same time.|
|pa| (push a)| Take the first element at the top of b and put it at the top of a.<br>Do nothing if b is empty.|
|pb| (push b)| Take the first element at the top of a and put it at the top of b.<br>Do nothing if a is empty.|
|ra| (rotate a)| Shift up all elements of stack a by 1.<br>The first element becomes the last one.|
|rb| (rotate b)| Shift up all elements of stack b by 1.<br> The first element becomes the last one.|
|rr| (rotate a) and (rotate b)| ra and rb at the same time.|
|rra| (reverse rotate a)| Shift down all elements of stack a by 1.<br>The last element becomes the first one.|
|rrb| (reverse rotate b)| Shift down all elements of stack b by 1.<br> The last element becomes the first one.|
|rrr| (reverse rotate a) and (reverse rotate b)| rra and rrb at the same time.|

[Complexity of Sorting algorithms](https://pereiratechtalks.com/analisis-de-algoritmos-de-ordenamiento/)


# learnings
## linker
The library order matters. you get different results with this two option:

```bash
gcc -o test_argpa test_argpa.o -L../../../lib -lft -lftprintf -lpss -largpar
/usr/bin/ld: ../../../lib/libargpar.a(arg_pars.o): en la función `arg_ok':
/home/luicasad/Documentos/c/cursus/circle3/push_swap/src/argpa/arg_pars.c:21: referencia a `pss_init' sin definir
/usr/bin/ld: /home/luicasad/Documentos/c/cursus/circle3/push_swap/src/argpa/arg_pars.c:30: referencia a `pss_have' sin definir
/usr/bin/ld: ../../../lib/libargpar.a(arg_digi.o): en la función `check':
/home/luicasad/Documentos/c/cursus/circle3/push_swap/src/argpa/arg_digi.c:26: referencia a `ft_isdigit' sin definir
/usr/bin/ld: ../../../lib/libargpar.a(arg_rang.o): en la función `arg_range_int':
/home/luicasad/Documentos/c/cursus/circle3/push_swap/src/argpa/arg_rang.c:22: referencia a `ft_atol' sin definir
collect2: error: ld returned 1 exit status
```

```bash
gcc -o test_argpa test_argpa.o -L../../../lib -largpar -lpss -lftprintf -lft
```

Library argpa uses pss to check duplicates or if num are ordered. Also uses libft to check digits and convert arg to longs
LIbrary pss used ftprintf for stack visualization.

## Valgrind
In this proyect i learned how to check leaks with, and how to get some assistance to find where the leaks happend in my code.

```bash
    valgrind --tool=memcheck --leak-check=yes ./$(NAME)
luis@:push_swap$ valgrind --tool=memcheck --leak-check=yes ./push_swap 7 1 8 2 3
==14009== Memcheck, a memory error detector
==14009== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==14009== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==14009== Command: ./push_swap 7 1 8 2 3
==14009== 
pb
pb
ra
pa
rra
pa
ra
ra
==14009== 
==14009== HEAP SUMMARY:
==14009==     in use at exit: 0 bytes in 0 blocks
==14009==   total heap usage: 17 allocs, 17 frees, 432 bytes allocated
==14009== 
==14009== All heap blocks were freed -- no leaks are possible
==14009== 
==14009== For lists of detected and suppressed errors, rerun with: -s
==14009== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```

In this journey I also discovered a visualization tool of the memory usage.`massif-visualizer`

First we request Valgrind the creation of a massif file.

```bash
    valgrind --tool=massif --stacks=yes ./push_swap
```

I got `massif.out.14023` where the number was de `PID` 


![image](https://github.com/luismiguelcasadodiaz/push_swap/blob/main/docs/media/massif_visualizer.png)

## Doxygen 

Doxygen helps with project documentation if you embrace comments with `/**..*/`. 

```c
/* ************************************************************************** */
/**
   @file arg_seen.c                                                             
   @brief arg_seen() check if num has been previously seen in the arguments.    
                                                                                
   @param[in] num: the num to see if exists inside the stack.                   
   @param[in]   a: the stack to save the arguments.                             
                                                                                
   @returns 0 if the argument has not been seen.   That is, it is not           
   inside the stack. 1 if the argument has been seen.                           
                                                                                
   @details                                                                     
   Loops the stack looking for num. If there is not, pushes num into  stack     
   and returns zero. Otherwiser returns one ==> arg_seen == True                
                                                                                
   @author LMCD (Luis Miguel Casado Diaz)                                       
*/
/* ************************************************************************** */
```

This is 42 Norma incompatible. So I figured out how to create a 42 norma compatible comment that later easyly trasnforms into a Doxygen compatible comment.  

```c
/* ************************************************************************** */
/*.<*                                                                        .*/
/*.@file arg_seen.c                                                          .*/
/*.@brief arg_seen() check if num has been previously seen in the arguments. .*/
/*.                                                                          .*/
/*.@param[in] num: the num to see if exists inside the stack.                .*/
/*.@param[in]   a: the stack to save the arguments.                          .*/
/*.                                                                          .*/
/*.@returns 0 if the argument has not been seen.   That is, it is not        .*/
/*.inside the stack. 1 if the argument has been seen.                        .*/
/*.                                                                          .*/
/*.@details                                                                  .*/
/*.Loops the stack looking for num. If there is not, pushes num into  stack  .*/
/*.and returns zero. Otherwiser returns one ==> arg_seen == True             .*/
/*.                                                                          .*/
/*.@author LMCD (Luis Miguel Casado Diaz)                                    .*/
/*.>*                                                                        .*/
/* ************************************************************************** */

```
This 42 norma compatible comment can be transformed to Doxygen compatible comment with this bash script.

```bash
#!/bin/bash
sed -i 's/\/\*\.<.*$/\/\*\*/' $1
sed -i 's/\/\*\.>.*$/\*\//' $1
sed -i 's/\/\*\./   /' $1
sed -i 's/\.\*\//   /' $1
```

[you will find it here 42norma2doxugen.sh](https://github.com/luismiguelcasadodiaz/push_swap/blob/main/docs/42norma2doxygen.sh) 
## header file changes name

During the evaluation, Paul Borrull noticed that bonus part had not ` _bonus.c/h`. After changing file names i still had to change includes inside the files.

I solved it with one command.

```bash
 sed -i'.bak' -e  's/checker\.h/checker_bonus\.h/' *
 ```

`*` for all folders files.
`-i'.bak'` edit files in-place saving backups with extension `.bak`.
`-e ` append the command to the list of command to execute.

## Makefile
I thank to Eric Alonso Martinez for teaching me so much about Makfile. 

Eric touched one of my lib%.a files and noticed that my make did nothing.
Etic touched one of my %.h and noticed that all was relinked.


Eric hinted me to read GNU gcc manual [3.13 Options controlling the Preprocessor](https://gcc.gnu.org/onlinedocs/gcc-13.2.0/gcc/Preprocessor-Options.html).
`-MM` flag creates a dependencies file `*.d`  for each source file. I notice that my `#include` usage created unnecessary dependencies. Them I moved some includes from `*.h` to the `*.c` really requiring it.

```bash
➜  stack git:(main) ✗ cat *.d
nod_free.o: nod_free.c ../../inc/libpss.h
nod_init.o: nod_init.c ../../inc/libpss.h
pss_bign.o: pss_bign.c ../../inc/libpss.h
pss_bott.o: pss_bott.c ../../inc/libpss.h
pss_empt.o: pss_empt.c ../../inc/libpss.h
pss_free.o: pss_free.c ../../inc/libpss.h
pss_have.o: pss_have.c ../../inc/libpss.h
pss_init.o: pss_init.c ../../inc/libpss.h
pss_isor.o: pss_isor.c ../../inc/libpss.h
pss_mami.o: pss_mami.c ../../inc/libpss.h
pss_maxi.o: pss_maxi.c ../../inc/libpss.h
pss_mini.o: pss_mini.c ../../inc/libpss.h
pss_mkid.o: pss_mkid.c ../../inc/libpss.h
pss_nrot.o: pss_nrot.c ../../inc/libpss.h
pss_nrro.o: pss_nrro.c ../../inc/libpss.h
pss_ovbo.o: pss_ovbo.c ../../inc/libpss.h
pss_pall.o: pss_pall.c ../../inc/libpss.h
pss_peek.o: pss_peek.c ../../inc/libpss.h
pss_peek_idx.o: pss_peek_idx.c ../../inc/libpss.h
pss_pope.o: pss_pope.c ../../inc/libpss.h
pss_prad.o: pss_prad.c ../../inc/libpss.h ../../inc/libft.h
pss_prin.o: pss_prin.c ../../inc/libpss.h ../../inc/ft_printf.h
pss_prnu.o: pss_prnu.c ../../inc/libpss.h ../../inc/ft_printf.h
pss_psoo.o: pss_psoo.c ../../inc/libpss.h ../../inc/ft_printf.h
pss_push.o: pss_push.c ../../inc/libpss.h
pss_reve.o: pss_reve.c ../../inc/libpss.h ../../inc/ft_printf.h
pss_roro.o: pss_roro.c ../../inc/libpss.h ../../inc/ft_printf.h
pss_rota.o: pss_rota.c ../../inc/libpss.h ../../inc/ft_printf.h
pss_rrot.o: pss_rrot.c ../../inc/libpss.h ../../inc/ft_printf.h
pss_rrrr.o: pss_rrrr.c ../../inc/libpss.h ../../inc/ft_printf.h
pss_size.o: pss_size.c ../../inc/libpss.h
pss_sman.o: pss_sman.c ../../inc/libpss.h
pss_swap.o: pss_swap.c ../../inc/libpss.h ../../inc/ft_printf.h
pss_swsw.o: pss_swsw.c ../../inc/libpss.h ../../inc/ft_printf.h
pss_unpe.o: pss_unpe.c ../../inc/libpss.h
```

We can see the dependenciess file as a `make rule`.

Each dependencies file is transformed with a sed instruction 

```bash
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
```

into this new `make rule` 

```bash
pss_unpe.o pss_unpe.d : pss_unpe.c ../../inc/libpss.h
```
This rules sets that any changes in either `pss_unpe.c` or in `../../inc/libpass.h`  affects to object file and dependency file.

All this magic happens wiht this rule from GNU make  manual [4.14 Generating Prerequisites Automatically](https://www.gnu.org/software/make/manual/make.html#Automatic-Prerequisites).
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) $(HEADS) -MM $< > $@.$$$$ ; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
    rm -f $@.$$$$

Once the dependencies files (make rules) are properly formatted, they have to be included into `Makefile` with:

```make
DEPE_PUSHS = $(addprefix $(OBJDIR), $(SRCS_PUSHS:.c=.d))
 -include $(DEPE_PUSHS)
 ```
The [include directive] (https://www.gnu.org/software/make/manual/make.html#Include) tells make to suspend reading the current makefile and read one or more other makefiles before continuing. 
Please notice leading  minus sign .If you want make to simply ignore a makefile which does not exist or cannot be remade,(that happens the first time) with no error message, use the -include directive instead of include,

With this knowledge, now i manage a more clever compilation process, where only REAL depended files are recompiled when something the file depends on has changed.

Addtionally Eric taught me [vpath directive](https://www.gnu.org/software/make/manual/make.html#Selective-Search) .   `vpath %.a ./lib` hints make that files ending in `*.a` should be looked for in sach path.


Finally, with [Directory search for link libraries](https://www.gnu.org/software/make/manual/make.html#Libraries_002fSearch) i was able to relink my targets if the libraries they depend on changed.

