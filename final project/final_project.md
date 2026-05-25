# Final Project

### Task 1: Finding players that play both sports

Code: [task1.cpp](task1.cpp)

To achieve $O(N + M)$ time complexity, I converted the first list of players into a set. This way, when iterating through the second list, I can see if they are found in list1 at $O(1)$ speed. (For a $O(1)$ lookup time, I used `unordered set`). As a result:
* Converting each name from list 1 to a set = $O(N)$
* Checking each name from list 2 against the set = $O(M)$
* Resultant runtime: $O(N) + O(M) = O(N + M)$

### Task 2: Find missing number

Code: [task2.cpp](task2.cpp)

For this problem, I didn't use any special data structures. Instead, mathematical solution seemed to be simplier. If:
* If, Sum of integers from 0 to N = $TotalSum$
* And, Same sum but with missing number = $TotalSum - MissingNum = PartialSum$
* Then, $MissingNum = TotalSum - PartialSum$

$TotalSum$ can be calculated using summation formula $\frac{n(n+1)}{2}$
$PartialSum$ can be calculated by adding all numbers in the array.


### Task 3: Greatest Stock Profit

Code: [task3.cpp](task3.cpp)

For this problem, program finds lower price point (lowest so far) and compares to today's price. It updates max_profit if selling today will yield greater profit. But if today's price is lowest yet, it updates the min_price. Since the array is only iterated over once, time complexity is $O(N)$.



### Task 4: Greatest Product

Code: [task4.cpp](task4.cpp)

To find greatest product of two numbers in an array, we need to find two largest numbers and get their product. However, since we need to also track negative numbers as well, then we need to find not only two greatest positiven numbers but also two most negative numbers, calculate product of the two, and return which ever product is greatest.


## Task 5: Sort temperature readings in $O(1)$

Code: [task5.cpp](task5.cpp)

Since readings here are limited to only two changing digits and a known range, we can make a limited-range frequency table for each possible reading (21 total). Then, we can use this frequency table to iterate from 97.0 to 99.0 and add that reading back into the output array based on its frequency. As a result, we iterate total of $2N$ times, resulting in time complexity of $O(N)$. Moreover, since the frequency table always has same size and we are writing to the original array, space complexity is $O(1)$.


## Task 6: Longest Sequence

Code: [task6.cpp](task6.cpp)

To make this algorithm run in $O(N)$, we can use properties of (unordered) set's O(1) look-up. We can add all numbers in the input array to a set. Then, we can traverse the array for each number, asking "Is n+1 in the set? If yes, is n+2 in the set?" and so on. To make this run efficiently, before traversing through potential sequences, we can first check if current number is at the beginning of the sequence by checking if n-1 is not in a set.