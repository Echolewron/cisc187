# Activity 13: Space Constraints

### Task 1: Word Builder algorithm
$$Space Complexity = O(N^2)$$
For each item in an array of size $N$, the algorithm writes almost as many new words to `collections` array as there are words in input array, that is $N-1$. As a result, `collections` array will have the size of $N(N-1)$. This is a space complexity of $O(N^2)$.

### Task 2: Reverse algorithm
$$SpaceComplexity = O(N)$$
This algorithm writes a copy of an input array to `newArray` in reverse order. That means computer made new array of identical size. Space Complexity is then $O(N)$

### Task 3: O(1) Reverse algorithm

```lua
    function reverse(array) {
        for (let i = 0; i < array.length / 2; i++) {
            temp = array[i];
            array[i] = array[array.length - i];
            array[array.length - i] = temp;
        }

        return array;
    }
```

To upgrade previous reverse algorithm with $O(N)$ space complexity, we need to modify original array in place instead of creating a new one. To reverse it, we can swap outer elements until we reach the middle of the array.

### Task 4: Comparing array doubling space and time complexities
| Version | Time Complexity | Space Complexity |
| --- | --- | --- |
| Version # 1 | $O(N)$ | $O(N)$  |
| Version # 2 | $O(N)$ | $O(1)$ |
| Version # 3 | $O(N)$ | $O(N)$ |

**Version #1.** Time complexity is $O(N)$ because it needs to double each number in an array. Space complexity is $O(N)$ because it stores as many duplicated numbers as there are numbers in input array.

**Version #2.** Time complexity is still $O(N)$ because it still needs to double each number in an array. Space complexity is $O(1)$ because it doubles each number in place, without creating new data.

**Version #3.** Time complexity is $O(N)$ because every function created for each number still has to double each number in an array. Space complexity is also $O(N)$ because for each number, new function is called recursively, adding data to the stack for each function.