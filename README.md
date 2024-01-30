# push_swap
This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

The data to be sorted is made of integer values.

According to <limits.h>   INT_MIN = -2 147 483 648 and INT_MAX = +2 147 483 647.

## goal
Write a program in C called push_swap which calculates and displays on the standard output the **smallest** program, made of **Push swap language** instructions, that sorts the **integers** received as arguments.

Sorting values is simple. To sort them the fastest way possible is less simple. Especially because **from one set of integers configuration to another, the most efficient sorting solution can differ**.
 
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

• The goal is to sort in ascending order numbers into the stack a. To do so you have the following operations at your disposal:

|code | operation| Description |
|-----|-----|--------------|
|sa| (swap a)| Swap the first 2 elements at the top of stack a.<br> Do nothing if there is only one or no element.|
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

# Approach
I started this project by implementing the [stack library](https://github.com/luismiguelcasadodiaz/push_swap/blob/main/src/stack/README.md). A Stack circular with a double link to navigate it forward or backward. And checked that no memory leaks remained at the exit.

My stack holds some stack's metadata:

Field big holds the biggest  integer in the stack.
Field sma holds the smallest integer in the stack.
Field siz holds the number of integers in the stack.
Field nam holds the letter that names the stack.
Field fld holds the file descriptor to print stack data and movements.
Field big holds the biggest  index   in the stack.
Field sma holds the smallest index   in the stack.

```c
typedef struct s_pss
{
	t_nod		*top;
	int		big;
	int		sma;
	int		siz;
	char		nam;
	int		fld;
	int		bid;
	int		sid;
}	t_pss;
```

I started sorting stacks of 2, 3, 4, and five elements. I wrote a function for each case (ps_sort2, ps_sor3, ps_sort4 (sorts 3 and adds fourth), and ps_sort5 (sorts 3 then adds 4th and 5th),  I got a certain understanding of how to order a small number of numbers. I started to see conditions to insert in the top (no movements required), in the bottom (a ra movement required),  or in the middle of the stack (choose if going through the top or the bottom depending on destination deepness).

I got the idea that the bonus was not a hard task, so I implemented it at this point, comparing its behavior with existing checkers.

OSINT suggested three solutions, the chunks solution, the radix sort solution, and the Turkish solution. Radix was the more straight one to me. The [Radix Sort](https://github.com/luismiguelcasadodiaz/push_swap/blob/main/src/pushs/README.md) gave me 3 points sorting 100 numbers and 4 points sorting 500 numbers.

|mov|run 1|run 2|run 3|run 3%
|---|----:|---:|---:|-----|
|pa|381|381|381|35.25%|
|pb|381|381|381|35.25%|
|ra|319|319|319|29.51%|
|Tot|1 081|1 081|1 081|100.00%|

Sorting 100 integer below movemente gave me 5 points too.
|mov|run 1|run 2|run 3|run 3%
|---|-----:|----:|----:|-----:|
|pa|2 278|2 278|2 278|33.61%|
|pb|2 278|2 278|2 278|33.61%|
|ra|2 222|2 222|2 222|32.78%|
|Tot|6 778|6 778|6 778|100.00%|


I was happy, but suddenly I became unhappy when I discovered (Barcelona's Pedago team confirmed me) that it was mandatory to get 5 points by sorting 100 and 500 numbers to submit the bonus.

That is the reason why I worked out the [Turkish algorithm](https://github.com/luismiguelcasadodiaz/push_swap/blob/main/src/pushs/turkish.md).

With turkish, sorting 500 integer below 5500 movements gave me 5 points. 
|mov|run 1|run 2|run 3|run 3%
|---|-----:|----:|----:|-----:|
|pa|497|497|497|9.99%|
|pb|497|497|497|9.99%|
|ra|528|558|571|11.47%|
|rb|715|1 233|808|16.23%|
|rr|601|736|712|14.31%|
|rra|461|566|396|7.96%|
|rrb|939|657|1 023|20.55%|
|rrr|724|514|472|9.48%|
|sa|1|1|1|0.02%|
|Tot|4 963|5 259|4 977|100.00%|

Sorting 100 integer below movemente gave me 5 points too.
|mov|run 1|run 2|run 3|run 3%
|---|-----:|----:|----:|-----:|
|pa|97|97|97|17.93%|
|pb|97|97|97|17.93%|
|ra|56|44|36|6.65%|
|rb|95|80|135|24.95%|
|rr|33|42|78|14.42%|
|rra|35|40|36|6.65%|
|rrb|94|67|42|7.76%|
|rrr|52|63|40|3.70%|
|sa|1|0|0|0.00%|
|Tot|560|530|541|100.00%|

When i compare movements, i appreciate that Radix uses only 3 movements while Turkish uses 9 movements.

It is possible to check our results with [Gerard Martinez's tester](https://github.com/gemartin99/Push-Swap-Tester)....

<img width="429" alt="image" src="https://github.com/luismiguelcasadodiaz/push_swap/assets/19540140/c8c06ac9-d56e-4b5d-80c4-1d37b1ddcfbe">

This project involves 154 files. 52 files for push_swap_stack (pss_*.c). 12 files for push_swap (ps_*.c) 47 libft files. 10 ft_printf files. For the bonus 9 files (chk_*.c) plus the 12 getnextline files to read commands. 4 files for parsing arguments (arg_*.c) . 4 header files. 5 Makefiles.

# learnings
## linker
The library order matters. you get different results with these two option:

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
In this project,  I learned how to check leaks, and how to get some assistance to find where the leaks happened in my code.

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

In this journey, I also discovered a visualization tool for the memory usage.`massif-visualizer`

First, we request Valgrind the creation of a massif file.

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
   Loops the stack looking for num. If there is not, push num into  the stack     
   and return zero. Otherwise returns one ==> arg_seen == True                
                                                                                
   @author LMCD (Luis Miguel Casado Diaz)                                       
*/
/* ************************************************************************** */
```

This is 42 Norma incompatible. So I figured out how to create a 42 norma compatible comment that later easily transformed into a Doxygen compatible comment.  

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
/*.Loops the stack looking for num. If there is not, push num into  stack    .*/
/*.and returns zero. Otherwise returns one ==> arg_seen == True              .*/
/*.                                                                          .*/
/*.@author LMCD (Luis Miguel Casado Diaz)                                    .*/
/*.>*                                                                        .*/
/* ************************************************************************** */

```
This 42 norma-compatible comment can be transformed into a Doxygen-compatible comment with this bash script.

```bash
#!/bin/bash
sed -i 's/\/\*\.<.*$/\/\*\*/' $1
sed -i 's/\/\*\.>.*$/\*\//' $1
sed -i 's/\/\*\./   /' $1
sed -i 's/\.\*\//   /' $1
```

[you will find it here 42norma2doxugen.sh](https://github.com/luismiguelcasadodiaz/push_swap/blob/main/docs/42norma2doxygen.sh) 
## header file changes name

During the evaluation, Paul Borrull noticed that the bonus part had not ` _bonus.c/h`. After changing file names I still had to change the includes inside the files.

I solved it with one command.

```bash
 sed -i'.bak' -e  's/checker\.h/checker_bonus\.h/' *
 ```

`*` for all folders files.
`-i'.bak'` edit files in-place saving backups with extension `.bak`.
`-e ` append the command to the list of commands to execute.

## Makefile
I thank Eric Alonso Martinez for teaching me so much about Makefile. 

Eric touched one of my lib%.a files and noticed that my make did nothing.
Etic touched one of my %.h and noticed that all was relinked.


Eric hinted me to read GNU gcc manual [3.13 Options controlling the Preprocessor](https://gcc.gnu.org/onlinedocs/gcc-13.2.0/gcc/Preprocessor-Options.html).
`-MM` flag creates a dependencies file `*.d`  for each source file. I noticed that my `#include` usage created unnecessary dependencies. Then I moved some includes from `*.h` to the `*.c` really requiring it.

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

We can see the dependencies file as a `make rule`.

Each dependencies file is transformed with a sed instruction 

```bash
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
```

into this new `make rule` 

```bash
pss_unpe.o pss_unpe.d : pss_unpe.c ../../inc/libpss.h
```
This rule sets that any changes in either `pss_unpe.c` or in `../../inc/libpass.h`  affect to object file and dependency file.

All this magic happens with this rule from GNU make  manual [4.14 Generating Prerequisites Automatically](https://www.gnu.org/software/make/manual/make.html#Automatic-Prerequisites).

```make
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) $(HEADS) -MM $< > $@.$$$$ ; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
    rm -f $@.$$$$
```
Once the dependencies files (make rules) are properly formatted, they have to be included in `Makefile` with:

```make
DEPE_PUSHS = $(addprefix $(OBJDIR), $(SRCS_PUSHS:.c=.d))
 -include $(DEPE_PUSHS)
 ```
The [include directive](https://www.gnu.org/software/make/manual/make.html#Include) tells make to suspend reading the current makefile and read one or more other makefiles before continuing. 
Please notice the leading  minus sign. If you want to simply ignore a makefile that does not exist or cannot be remade,(that happens the first time) with no error message, use the -include directive instead of include,

With this knowledge, now I manage a more clever compilation process, where only REAL-dependent files are recompiled when something the file depends on has changed.

Additionally, Eric taught me [vpath directive](https://www.gnu.org/software/make/manual/make.html#Selective-Search) .   `vpath %.a ./lib` hints make that files ending in `*.a` should be looked for in the search path.


Finally, with [Directory search for link libraries](https://www.gnu.org/software/make/manual/make.html#Libraries_002fSearch) I was able to relink my targets if the libraries they depend on changed.


## library construnction.
Joan Renaull Valls assisted me with `ar`.

I faced a problem with the library construction after touching only one file `*.c` , generating the `*.o` and replacing it with the `*.a`.

```make
	ar rcs $(NAME) $?
	mv $(NAME) $(LIBDIR)
```

Joan taught me to manually add files to my `*.a` and observed that after moving the library to the lib dir, that did not exist anymore in the Makefile folder, so the new library contained only the new object created after recompiling. That generated symbols missing errors upwards in the linking process.

thanks to Joan's assistance my Makefile changed to :


```make
	ar rcs ($LIBDIR)$(NAME) $?
```

Creating the library directory directly into `push_swap/lib` folder.
