## Radix Sort

Radix Sort is used to sort numbers. 

Sorting starts from the least significant digit to the most significant digit.

| n1| n2| n3| n4| n5| n6| n7| n8|
|---|---|---|---|---|---|---|---|
|170|045|075|090|802|024|002|066|



### Sorting units

| n1| n2| n3| n4| n5| n6| n7| n8|
|---|---|---|---|---|---|---|---|
|17**0**|04**5**|07**5**|09**0**|80**2**|02**4**|00**2**|06**6**|
|17**0**|09**0**|80**2**|00**2**|02**4**|04**5**|07**5**|06**6**|
|       | 0     |  2    |       |  4    |  5    |       |   6   |

We see five buckets (0, 2, 4, 5, and 6)

### Sorting tens

| n1| n2| n3| n4| n5| n6| n7| n8|
|---|---|---|---|---|---|---|---|
|1**7**0|0**9**0|8**0**2|0**0**2|0**2**4|0**4**5|0**7**5|0**6**6|
|8**0**2|0**0**2|0**2**4|0**4**5|0**6**6|1**7**0|0**7**5|0**9**0|
|       | 0     |  2    |   4   |   6   |   7   |       |   9   |
i
We see  six buckets (0, 2, 4, 6, 7, and 9)

### Sorting hundreds

| n1| n2| n3| n4| n5| n6| n7| n8|
|---|---|---|---|---|---|---|---|
|**8**02|**0**02|**0**24|**0**45|**0**66|**1**70|**0**75|**0**90|
|**0**02|**0**24|**0**45|**0**66|**0**75|**0**90|**1**70|**8**02|
|       | 0     |       |       |       |       |  1    |   8   |

We see three buckets (0, 1, and 8)

## Radix Sort in Push_swap.

The previous section aimed to understand the algorithm and the concept of classification buckets used in the shadow.

We are restricted by two stacks. Let's think about it as buckets for classification.


Push_swap  sorts integers in the interval -2147483648 .. 2147483647. if we had one bucket per digit (0..9), we have to loop over all numbers 10 times plus the positive/negative discrimination.  A dataset of 100 integers requires 100 times 11 visits to each number. That is 1100 visits.

The point is that we have ONLY two buckets. We have to think in binary. This makes things worse as we require 32 bits to represent the interval of valid integer to sort. 100 numbers times 32 visits. That is 3200 visits.

After some consideration, we can see that we only have 100 numbers to sort. We have 100 positions. The positions are not affected by the size of the number to be sorted. Position 7 will always be position seven regardless of whether it has the value -2147483600 or the value 125.

That said, if we associate each number in the stack, let's call it x, with the number of numbers in the stack less than x, we will have the position it has to occupy in the ordering.

100 numbers fit in 128 = 2⁷ ==> 100 times 7 =  700 visits.
500 numbers fit in 512 = 2⁹ ==> 500 times 9 = 4500 visits.

## Round bit 1

| STACK A  |  STACK A | STACK B  | STACK A  |
|----------|----------|----------|----------|
|4 010**0**|          |          |4 010**0**|
|2 001**0**|          |          |2 001**0**|
|3 001**1**|          |0 000**0**|0 000**0**|
|0 000**0**|3 001**1**|2 001**0**|3 001**1**|
|1 000**1**|1 000**1**|4 010**0**|1 000**1**|

			pb pb ra pb ra		 pa pa pa

## Round bit 2

| STACK A  |  STACK A | STACK B  | STACK A  |
|----------|----------|----------|----------|
|4 01**0**0|          |          |4 01**0**0|
|2 00**1**0|          |          |0 00**0**0|
|0 00**0**0|          |1 00**0**1|1 00**0**1|
|3 00**1**1|2 00**1**0|0 00**0**0|2 00**1**0|
|1 00**0**1|3 00**1**1|4 01**0**0|3 00**1**1|

			pb ra pb ra pb       pa pa pa

## Round bit 3

| STACK A  |  STACK A | STACK B  | STACK A  |
|----------|----------|----------|----------|
|4 0**1**00|          |          |0 0**0**00|
|0 0**0**00|          |3 0**0**11|1 0**0**01|
|1 0**0**01|          |2 0**0**10|2 0**0**10|
|2 0**0**10|          |1 0**0**01|3 0**0**11|
|3 0**0**11|4 0**1**00|0 0**0**00|4 0**1**00|

			ra pb pb pb pb       pa pa pa pa


## Number of commands
We can estimate the number of commands like this
3 bits times 5 + 5/2			

In a genereic way k * (1,5 * n), being k de number of bits and n the number of values to sort.

for 100 numbers = 7 * 150 = 1050 ==> you will get 3 points
for 500 numbers = 9 * 750 = 6750 ==> you will get 4 points



