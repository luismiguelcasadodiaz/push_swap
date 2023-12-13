# push_swap
This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

Data to be sorted is made of integer values.

According to <limits.h>   INT_MIN = -2 147 483 648 and INT_MAX = +2 147 483 647.

## goal
Write a program in C called push_swap which calculates and displays on the standard output the **smallest** program, made of **Push swap language** instructions, that sorts the **integers** received as arguments.

Sorting values is simple. To sort them the fastest way possible is less simple. Especially because **from one integers configuration to another, the most efficient sorting solution can differ**.

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
