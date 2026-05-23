#include <iostream>
#include <vector>

using namespace std;

int GetGreatestStockProfit(vector<int> stock_prices) {

    int min_price = stock_prices[0];
    int max_profit = 0;


    for (const int& day_price : stock_prices) {

        // Update lowest price
        if (day_price < min_price) {
            min_price = day_price;
        }

        // See how much profit is possible if sold from min price to current price
        int potential_profit = day_price - min_price;

        if (potential_profit > max_profit) {
            max_profit = potential_profit;
        }
    }

    return max_profit;

}

int main() {
    
    vector<int> stock_prices = {10, 7, 5, 8, 11, 2, 6};

    cout << GetGreatestStockProfit(stock_prices) << endl;


}