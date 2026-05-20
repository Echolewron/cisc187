#include <iostream>
#include <vector>

using namespace std;

int findMissingInt(vector<int> array) {
    int expected_sum = array.size() * (array.size() + 1) / 2;
    int sum = 0;

    for (const int& num : array) {
        sum += num;
    }

    return expected_sum - sum;
} 

int main() {
    vector<int> array = {8, 2, 3, 9, 4, 7, 5, 0, 6};

    cout << findMissingInt(array) << endl;
}