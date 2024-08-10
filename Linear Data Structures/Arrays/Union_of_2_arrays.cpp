/*Given two sorted arrays of size n and m respectively, find their union. 
The Union of two arrays can be defined as the common and distinct elements in the two arrays.
Return the elements in sorted order.
Example 1:
Input: 
n = 5, arr1[] = {1, 2, 3, 4, 5}  
m = 5, arr2 [] = {1, 2, 3, 6, 7}
Output: 
1 2 3 4 5 6 7
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> findUnion(vector<int> arr1, vector<int> arr2, int n, int m) {
    set<int> s;
    for(int i = 0; i < n; i++) s.insert(arr1[i]);
    for(int j = 0; j < m; j++) s.insert(arr2[j]);
    
    return vector<int>(s.begin(), s.end());
}

int main() {
    vector<int> arr1 = {1, 2, 4, 5, 6};
    vector<int> arr2 = {2, 3, 5, 7};
    int n = arr1.size();
    int m = arr2.size();

    vector<int> unionArray = findUnion(arr1, arr2, n, m);

    cout << "Union of the two arrays is: ";
    for(int i : unionArray) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
