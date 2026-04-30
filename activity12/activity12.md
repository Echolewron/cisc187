# Activity 12: Recursions

### Task #1 Identifying the base case

Base case in the "print_every_other" function is `low > high`

```ruby
def print_every_other(low, high) 
    return if low > high # <-- Right here
    puts low
    print_every_other(low + 2, high)
end
```

### Task #2 Factorial with (n - 2)

`factorial(10)`: $10 * 8 * 6 * 4 * 2 * 0 * -2 * -4 ...$
Though mathematically, this would equal to 0 since we are multiplying by zero, in reality, this will not return anything since program never reaches the base case `n == 1` as it skips over it. This is also known as `Stack Overflow` error.

### Task #3 Fixing summation code

Correct base case that needs to be added is `return low if low <= high`

```ruby
def sum(low, high)
    return low if low <= high   # <- Base case added
    return high + sum(low, high - 1)
end
```


### Task #4 Resursive function to print all numbers in arbitrarily nested array

My implementation is in pseudo-code. It prints each number in an array, but if element is in array and not a number, it dives deeper.

```ruby
def print_all_nums_array(array)
    for num in array
        if num.type == "number"
            print num
        else
            print_all_nums_array(num)
        end
    end
end
```