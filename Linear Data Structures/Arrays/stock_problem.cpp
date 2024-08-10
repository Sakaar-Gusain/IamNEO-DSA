/*
The cost of stock on each day is given in an array A[] of size N. Find all the segments of days on 
which you buy and sell the stock such that the sum of difference between sell and buy prices is 
maximized. Each segment consists of indexes of two elements, first is index of day on which you 
buy stock and second is index of day on which you sell stock.
Note: Since there can be multiple solutions, the driver code will print 1 if your answer is 
correct, otherwise, it will return 0. In case there's no profit the driver code will print the string 
"No Profit" for a correct solution.

Example 1:

Input:
N = 7
A[] = {100,180,260,310,40,535,695}
Output:
1
Explanation:
One possible solution is (0 3) (4 6)
We can buy stock on day 0,
and sell it on 3rd day, which will 
give us maximum profit. Now, we buy 
stock on day 4 and sell it on day 6.
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> A, int n) {
        vector<vector<int>> result;

        int i = 0;
        while (i < n - 1) {
            // Find the local minima (buy point)
            while (i < n - 1 && A[i + 1] <= A[i]) {
                i++;
            }
            if (i == n - 1) {
                break;
            }
            int buy = i;
            i++;

            // Find the local maxima (sell point)
            while (i < n && A[i] >= A[i - 1]) {
                i++;
            }
            int sell = i - 1;

            result.push_back({buy, sell});
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // Hardcoded input
    vector<int> A = {100, 180, 260, 310, 40, 535, 695};
    int n = A.size();
    
    // Get the result of the stockBuySell function
    vector<vector<int>> result = sol.stockBuySell(A, n);

    // Check if there are any profitable segments
    if (result.empty()) {
        cout << "No Profit" << endl;
    } else {
        for (const auto& segment : result) {
            cout << "(" << segment[0] << " " << segment[1] << ") ";
        }
        cout << endl;
    }

    return 0;
}
