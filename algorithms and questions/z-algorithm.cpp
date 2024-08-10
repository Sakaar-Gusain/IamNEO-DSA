/*
Z-algorithm
string text = "AAAAAA";
string pattern = "AAA";
Expected Output: Pattern found at index 0
                 Pattern found at index 1
                 Pattern found at index 2
                 Pattern found at index 3

Test Case :
string text = "ABCABCABC";
string pattern = "ABC";
Expected Output:Pattern found at index 0
                Pattern found at index 3
                Pattern found at index 6

Test Case :
string text = "AABAACAADAABAABA";
string pattern = "AABA";
Expected Output:Pattern found at index 0
                Pattern found at index 9
                Pattern found at index 12
*/

#include<bits/stdc++.h>
using namespace std;
void getZarr(string str, int Z[]);
 
void search(string text, string pattern)
{
    string concat = pattern + "$" + text;
    int l = concat.length();
    int Z[l];
    getZarr(concat, Z);
    for(int i=0; i< l;++i)
    {
        if(Z[i] == pattern.length())
        cout<<"Patern found at index "<< i - pattern.length() - 1<<endl;
        
    }
}

void getZarr(string str, int Z[])
{
    int n = str.length();
    int L,R,K;
    L = R = 0;
    for(int i = 1 ; i<n; ++i)
    {
        if(i > R)
        {
            L = R = i;
            while(R < n && str[R - L] == str[R])
            R++;
            Z[i] = R - L;
            R--;
        }
        else
        {
            K = i - L;
            if(Z[K] < R - i + 1)
            Z[i] = Z[K];
            else
            {
                L = i;
                while(R < n && str[R-L] == str[R])
                R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
    
}

int main()
{
    string text = "BAABAA";
    string pattern = "AAB";
    search(text, pattern);
}