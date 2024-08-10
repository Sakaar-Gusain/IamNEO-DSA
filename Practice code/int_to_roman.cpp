#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
        vector<pair<int, string>> value = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        string result;

        for(const auto& pair: value){
            while(num >= pair.first){
                num -=pair.first;
                result += pair.second;
            }
        }
        return result;
}

int main(){
    int a= 3749;
    int b= 58;
    int c=45;

    cout<<intToRoman(a)<<endl;
    cout<<intToRoman(b)<<endl;
    cout<<intToRoman(c)<<endl;

    return 0;
}