# Turkish algoritm
I will sort indexes instead of numbers. I became influenced by the Radix sort where i precaculated, for each number to sort, how many are smaller than itself there are, so i got the potential future position in the stack for each number. 
In this way i only order indexes from 1 to 100 or from 1 to 500.

The departure point is an unsorted stack A of indexes.
Let's move two elements from A to B. This allows me to have the smallest index (sid) and de biggest index(bid) for stack b. AS well as i have it for stack A.
