#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


int longestSequence(vector<int> array) {

    unordered_set<int> nums_set;
    nums_set.reserve(array.size());

    // Adds each number from array to a set
    for (const int& num : array) {
        nums_set.insert(num);
    }


    int max_sequence = 0;
    for (int num : array) {

        // Checks if the number is the beginning of a sequence, skips if not
        if (nums_set.count(num - 1)) {
            continue;
        }

        // Counts how many numbers are in the sequence
        int sequence_size = 0;
        while (nums_set.count(num)) {
            sequence_size++;
            num++;
        }

        // Updates max sequence size if current sequence is bigger than previous observed
        if (max_sequence < sequence_size) {
            max_sequence = sequence_size;
        }
    }

    return max_sequence;
}


int main() {
    vector<int> array = {10, 5, 12, 3, 55, 30, 4, 11, 2};

    cout << longestSequence(array) << endl;
}