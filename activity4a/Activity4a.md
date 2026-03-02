# Activity 4a - Sorting Algorithms

[YouTube Video](https://youtu.be/81l80mRGS3s)

## 1. Proof $O(N^2)$ time complexity for insertion sort, average case:

1. For the i-th element, it will take an average of about $\frac{i}{2}$ comparisons and $\frac{i}{2}$ shifts, totalling $i$ steps per iteration.

For an array of length N, sum the steps for all elements from index $1$ to $N - 1$:

$$\sum_{i=1}^{N-1} i = \frac{N^2 - N}{2}$$



3. We can see that the total amount of steps taken results in $\frac{N^2-N}{2}$. Since $N^2$ dominates $N$ in growth and we ignore constants in time complexities, the time complexity is $O(N^2)$.



## 2. Counting operations for Insertion Sort worst-case scenario:

#### a) Starting from $i = 1$

$i=1$, key is 4:
- Compare: 5 > 4 = true (+1)
- Shift: A[1] = 5 (+1)
- Subtotal: 2 operations.

$i=2$, key is 3:
- Compare: 5 > 3 = true (+1)
- Shift: A[2] = 5 (+1)
- Compare: 4 > 3 = true (+1)
- Shift: A[1] = 4 (+1)
- Subtotal: 4 operations.

$i=3$, key is 2:
- Compare: 5 > 2 = true (+1)
- Shift: A[3] = 5 (+1)
- Compare: 4 > 2 = true (+1)
- Shift: A[2] = 4 (+1)
- Compare: 3 > 2 = true (+1)
- Shift: A[1] = 3 (+1)
- Subtotal: 6 operations.

$i=4$, key is 1:
- Compare: 5 > 1 = true (+1)
- Shift: A[4] = 5 (+1)
- Compare: 4 > 1 = true (+1)
- Shift: A[3] = 4 (+1)
- Compare: 3 > 1 = true (+1)
- Shift: A[2] = 3 (+1)
- Compare: 2 > 1 = true (+1)
- Shift: A[1] = 2 (+1)
- Subtotal: 8 operations.

**Total Operations:** 2 + 4 + 6 + 8 = 20.



#### b. Counting operations with i starting at 2 and 3:

**Starting at $i=2$**
* Step $i = 2$:
    * 4 Operations
    * `[3, 5, 4, 2, 1]`
* Step $i = 3$:
    * 6 Operations
    * `[2, 3, 5, 4, 1]`
* Step $i = 4$:
    * 8 Operations
    * `[1, 2, 3, 5, 4]`

**Total:** $4+6+8=18$ operations.

**Starting at $i=3$**
* Step $i = 3$:
    * 6 Operations
    * `[2, 5, 4, 3, 1]`
* Step $i = 4$:
    * 8 Operations
    * `[1, 2, 5, 4, 3]`

**Total:** $6+8=14$ operations.

#### c. For (b), does the algorithm still sort the entire array? 

**No,** because Insertion Sort assumes that everything before $i$ is already sorted. The array will end up being partially sorted, but any unsorted elements will persist in skipped indices.



---

## Finding capital "X" presence in string:

#### a. Time complexity:
$$O(N)$$
The algorithm iterates through the entire string linearly, checking each character once. Since the step count grows linearly along with string size, the time complexity is $O(N)$.

#### b. Modify to improve best and average case scenarios:
Adding a `break` block after "X" is found will improve algorithm efficiency. After "X" is found, there is no need to check the rest of the characters. The algorithm will still be $O(N)$, but it will improve the best and average case scenarios. Without a `break` block, the algorithm will check the entire string in any case. With a break, it will stop at an average of $N/2$ if "X" is somewhere within the string and not at the edges. Best case is 1 step if "X" is at the beginning, and worst is N if "X" is at the end of the string.



| Checks for scenario | With `break` | Without `break` |
| --- | --- | --- |
| Best | 1 | N |
| Average | ~ $N/2$ | N |
| Worst | N | N |

Code:
```js
function containsX(string) {
    let foundX = false;
    for(let i = 0; i < string.length; i++) { 
        if (string[i] === "X") {
            foundX = true;
            break;  // <-- Add 'break' here for early exit
        }
    }
    return foundX; 
}