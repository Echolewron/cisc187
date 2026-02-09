# Array Data Structure
[YouTube Video](https://youtu.be/6gpw0MHOdbg)

## 1. Explain how to create an array of 100 elements.
In C++, you first need to tell the computer what data type you want to store in the array and the size of an array:
```cpp
int main() {
    int array[100]; // Integer array of size 100
}
```

## 2. What will be the size of each element of an array?
Size of each element in an array is the same as the size of the data type that it stores. If an integer is 4 bytes long, then in an integer array, each element is also 4 bytes long.
```cpp
#include <iostream>
using namespace std;

int main() {
    int array[10];
    cout << sizeof(array[0]) << " bytes" << endl; // 4 bytes
}
```

## 3. For an array containing 100 elements, provide the number of steps the following operations would take:

### Reading
If reading by index, then just 1 step.
```cpp
array[5] // 1 step
```

### Searching for a value not contained within the array
100 steps. Searches all 100 elements, then fails.

### Insertion at the beginning of the array
101 steps. Shifts all 100 elements right (100 steps), write a new value at 0 (+1 step).

### Insertion at the end of the array
1 step. Write a value at the next slot (1 step).

### Deletion at the beginning of the array
100 steps. Remove one element (+1 step). Shift 99 elements left (+99 steps).

### Deletion at the end of the array
1 step. Remove last element (1 step).

## 4. How many steps would it take to find all the “apples”? 
For an array of size N, it would take **N steps** because computer needs to check every element in an array.

## 5. How to find the memory address of an array.
In C++, to find the memory address of an array, you can simply use array name itself:
```cpp
#include <iostream>
using namespace std;

int main() {
    int array[10];

    cout << array << endl;      // 0x7829fff890
    cout << &array[0] << endl;  // 0x7829fff890
}
```
In fact, address of an array in C++ is same as the address of its first element. `array` and `&array[0]` point to the same starting address.
