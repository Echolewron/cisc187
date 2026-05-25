#include <iostream>
#include <vector>

using namespace std;


void sortReadings(vector<float>& readings) {

    vector<int> frequency_table(21, 0);  // frequency array containing 21 possible readings

    for (float& temp : readings) {
        int index = (int)(temp * 10) - 970; // Converts temperature to integer index
        frequency_table[index]++;   // Increases frequency for given temperature by one at each occurrencee
    }

    int output_index = 0;


    for (int i = 0; i < frequency_table.size(); i++) {
        float temp = ((float)i + 970.0) / 10.0;
        while (frequency_table[i] > 0) {
            readings[output_index] = temp;
            frequency_table[i]--;
            output_index++;
        }
    }

}

int main() {
    vector<float> readings = {98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1};

    sortReadings(readings);

    for (float& temp : readings) {
        cout << temp << " ";
    }
    cout << endl;
}