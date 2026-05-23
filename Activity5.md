# Implementing a Hash Table with Separate Chaining

## Experimental Analysis

Here I am testing the written hash table using:
1. Random strings
2. Sequential keys
3. Same prefix keys

I will be recording the following as follows:

* Total collisions
* Maximum bucket size (using algorithm below)
```cpp
    int max_bucket() const {
        int max = 0;
        for (auto& link : table) {
            if (link.size() > max) {
                max = link.size();
            }
        }
        return max;
    }
```

* Averagee bucket length. Which is equal to the `loadFactor()`

### Random strings

Here I am generating about 1000 random numbers as a string key.
<details>
<summary>Click to see the code</summary>

```cpp
for (int i = 0; i < 1000; i++) {
    map.insert(to_string(rand()), i);
}
```
</details>


Results:



```
HashTable 0xc6e3dffdc0:
Capacity: 1408
Number of elements: 987
Load factor: 0.700994
Total collisions: 286

Maximum bucket size: 5
Average bucket length: 0.700994
```

### Sequential keys


Here I am writing sequential keys, student1, student2, and so on:
<details>
<summary>How it's generated</summary>

```cpp
for (int i = 0; i < 1000; i++) {
    map.insert("student" + to_string(i), i);
}
```
</details>

Results:
```
HashTable 0xd79b3ff6e0:
Capacity: 1408
Number of elements: 1000
Load factor: 0.710227
Total collisions: 331

Maximum bucket size: 3
Average bucket length: 0.710227
```


### Same prefix keys
