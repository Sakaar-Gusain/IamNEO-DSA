/*stock market profit checker*/
#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    
    int maxProfit = 0;
    
    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) {
            maxProfit += prices[i] - prices[i - 1];
        }
    }
    
    return maxProfit;
}
int main() {
    int n;
    cout << "Enter the number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the stock prices for each day: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int profit = maxProfit(prices);
    cout << "Maximum Profit: " << profit << endl;

    return 0;
}
