/*to find numbers with even counts in them and print output the count accordingly;
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int D(int n){
    int d=0;
    while(n>0){
        n=n/10;
        d++;
        D(n);
    }
    return d;
}

int counter(vector<int>& nums){
    int count=0;
    for(int i=0;i<nums.size();++i){
        if(D(nums[i])%2==0){
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<int> V(n);

    for(int i=0;i<n;i++){
        cin>>V[i];
    } 

    cout<<"Count:"<<counter(V)<<endl;
    return 0;
}
