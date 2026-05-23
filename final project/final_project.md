# Final Project

### Task 1: Finding players that play both sports

To achieve $O(N + M)$ time complexity, I converted the first list of players into a set. This way, when iterating through the second list, I can see if they are found in list1 at $O(1)$ speed. (For a $O(1)$ lookup time, I used `unordered set`). As a result:
* Converting each name from list 1 to a set = $O(N)$
* Checking each name from list 2 against the set = $O(M)$
* Resultant runtime: $O(N) + O(M) = O(N + M)$

### Task 2: Find missing number

For this problem, I didn't use any special data structures. Instead, mathematical solution seemed to be simplier. If:
* If, Sum of integers from 0 to N = $TotalSum$
* And, Same sum but with missing number = $TotalSum - MissingNum = PartialSum$
* Then, $MissingNum = TotalSum - PartialSum$

$TotalSum$ can be calculated using summation formula $\frac{n(n+1)}{2}$
$PartialSum$ can be calculated by adding all numbers in the array.


### Task 3: Greatest Stock Profit

For this problem, program finds lower price point (lowest so far) and compares to today's price. It updates max_profit if selling today will yield greater profit. But if today's price is lowest yet, it updates the min_price. Since the array is only iterated over once, time complexity is $O(N)$.



### Task 4:
