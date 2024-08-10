//rainwater problem
#include <iostream>
#include <algorithm> // for std::max and std::min

using namespace std;

int maxWater(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        int left = arr[i];
        for (int j = 0; j < i; j++) {
            left = max(left, arr[j]);
        }
        int right = arr[i];
        for (int j = i + 1; j < n; j++) {
            right = max(right, arr[j]);
        }
        res += min(left, right) - arr[i];
    }
    return res;
}

int main() {
    int arr[] = {3, 0, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the length of the array
    std:cout << "Maximum water that can be trapped: " << maxWater(arr, n) << endl;
    return 0;
}
