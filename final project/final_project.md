# Final Project

### Task 1: Finding players that play both sports

To achieve $O(N + M)$ time complexity, I converted the first list of players into a set. This way, when iterating through the second list, I can see if they are found in list1 at $O(1)$ speed. (For a $O(1)$ lookup time, I used `unordered set`). As a result:
* Converting each name from list 1 to a set = $O(N)$
* Checking each name from list 2 against the set = $O(M)$
* Resultant runtime: $O(N) + O(M) = O(N + M)$