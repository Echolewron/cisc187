# Sorting Algorithms

[YouTube Video Activity 3](https://www.youtube.com/watch?v=oY6H_oEI24w)

## 1. Big O Notation for algorithm with $4N + 16 steps$:

**`O(N)`**

Big O Notation measures how an algorithm runtime grows as input size increases. It ignores constants. Therefore, for algorithm that takes $4N + 16 steps$, time complexity is **O(N)** because runtime grows linearly with input growth.

## 2. Big O Notation for algorithm that takes $2N$<sup>2</sup> steps:

**`O(N²)`**

Runtime of this algorithm grows quadratically with the input size. Therefore, time complexity is **O(N²)**.

## 3. Big O Notation for double-then-sum algorithm:

**`O(N)`**

This algorithm has two loops each running through an array once. First loop takes N steps to double each number. Second loop takes N steps to add all numbers to sum. Total steps is 2N. Since runtime of this algorithm grows linearly, time complexity is **O(N)**.

## 4. Big O Notation for multiple case string algorithm:

**`O(N)`**

This algorithm runs through each string in an array and performs an `upcase`, `downcase`, and `capitalize` function. Assuming that each string function costs 1 step, it would be 3 steps per string, making total step count 3N steps. Since runtime growth is linear with the input size, time complexity is **O(N)**.

## 5. Big O Notation for every-other-sum algorithm:

**`O(N²)`**

This algorithm iterates through the array once, and for each element at an even index, it iterates through the entire array again. Since the outer loop runs N times and the inner loop runs about N times, the total number of steps is proportional to N². Ignoring constants, the time complexity is **O(N²)**.