# Turkish algorithm
I will sort indexes instead of numbers. I became influenced by the Radix sort where I precalculated, for each number to sort, how many smaller than itself there are, so I got the potential future position in the stack for each number. 
In this way, I only order indexes from 1 to 100 or from 1 to 500.

The departure point is an unsorted stack A of indexes.
- Let's move two elements from A to B. This allows me to have the smallest index (sid) and de biggest index(bid) for stack b. As well as I have it for stack A.

- While in A there are more than 3 nodes, precalculated the cheaper index to move from A to a **descendant ordered Stack B**, then move it.

- Sort the remaining nodes in A.

- Move all nodes from B to A

- Rotate A till the smallest one is on top.

The cheaper index means the index that requires fewer movements to be extracted from stack A and correctly inserted in the **descendant ordered stack B**, the index with the lowest cost.:

The cost of an index movement is calculated in this way.

  1.- Movements to put the index on top of A.
  
  2.- Movements to put on top of stack B the first smaller index.
  
  3.- The push movement.
  

Let's dig a little more into the sentence "Movements to put the index on top of A". That means a certain number of ra(n) or rra(size of a - n) movements. We can appreciate that steps 1 and 2 above generate two options ((n)ra or (sa-n)rra and (n)rb or (sa-n)rrb). We face 4 options each time we calculate the cost:

Option a) (n)ra and (n)rb. calculate cost considering the movement rr.

Option b) (n)ra and (sa-n)rrb. cost is the addition of both.

Option c) (sa-n)rra and (n)rb. cost is the addition of both.

Option d) (sa-n)rra and (sa-n)rrb. We must consider the movement rrr.

Summarizing: For one state of Stack A, for each index in A calculate its optimal movement cost. Choose the cheapest index and move it.


