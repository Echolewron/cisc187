#include <iostream>
#include <vector>

using namespace std;

int highestProduct(vector<int> array) {

    int high1 = 0;
    int high2 = 0;

    int low1 = 0;
    int low2 = 0;

    // Find 2 greatest positive and 2 greatest negative numbers in the array
    for (int& num : array) {
        if (num >= high1) {
            high2 = high1;
            high1 = num;
        } else if (num > high2) {
            high2 = num;
        }

        if (num <= low1) {
            low2 = low1;
            low1 = num;
        } else if (num < low2) {
            low2 = num;
        }
    }

    // Calculate product of two greatest positive and negative numbers
    high1 = high1 * high2;
    low1 = low1 * low2;

    // Return the greater product
    if (high1 > low1) {
        return high1;
    }

    return low1;

}

int main() {

    vector<int> array = {5, -10, -6, 9, 4};

    cout << highestProduct(array) << endl;

}