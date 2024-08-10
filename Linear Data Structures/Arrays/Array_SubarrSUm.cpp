/*continuous subarray that adds to a given number S and return left-right index values*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> subarraySum(int N, int S, vector<int>& A) {
    int start = 0, end = 0, currentSum = 0;

    while (end <= N) {
        // If currentSum exceeds the sum, then remove the starting elements
        while (currentSum > S && start < end) {
            currentSum -= A[start];
            start++;
        }
        
        // If currentSum becomes equal to S, then return the start and end indices
        if (currentSum == S) {
            return {start + 1, end};
        }
        
        // Add this element to currentSum
        if (end < N) {
            currentSum += A[end];
        }
        end++;
    }

    // If no subarray is found, return -1
    return {-1};
}

int main() {
    int N, S;
    cout << "Enter the size of the array: ";
    cin >> N;
    cout << "Enter the sum S: ";
    cin >> S;

    vector<int> A(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> result = subarraySum(N, S, A);

    if (result.size() == 1 && result[0] == -1) {
        cout << "-1" << endl;
    } else {
        cout << result[0] << " " << result[1] << endl;
    }

    return 0;
}
