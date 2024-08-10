/*
This C++ code implements Manacher’s Algorithm to find the longest palindromic substring in a given 
string. Manacher’s Algorithm is efficient and runs in linear time O(n)

Test Case 1:
string s = "babad";
// Expected Output: Longest palindromic substring is: bab or aba

Test Case 2:
string s = "cbbd";
// Expected Output: Longest palindromic substring is: bb

Test Case 3:
string s = "a";
// Expected Output: Longest palindromic substring is: a
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
 
string preprocess(const string &s) {
    if (s.empty()) return "^$";
    string ret = "^";
    for (char c : s) {
        ret += "#" + string(1, c);
    }
    ret += "#$";
    return ret;
}
 
string longestPalindrome(const string &s) {
    string T = preprocess(s);
    int n = T.size();
    vector<int> P(n, 0);
    int C = 0, R = 0;
    for (int i = 1; i < n - 1; ++i) {
        int mirr = 2 * C - i;
        if (R > i)
            P[i] = min(R - i, P[mirr]);
 
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            ++P[i];
 
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
 
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
 
    return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
}
 
int main() {
    string s = "aaaaaaad";
    cout << "Longest palindromic substring is: " << longestPalindrome(s) << endl;
    return 0;
}