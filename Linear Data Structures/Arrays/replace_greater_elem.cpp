//Replace Elements with Greatest Element on Right Side

#include <bits/stdc++.h>
using namespace std;

vector<int> replaceElements(vector<int>& arr) {
    int n=arr.size();
    int maxR=-1;
    for(int i=n-1;i>=0;--i){
        int c=arr[i];
        arr[i]=maxR;
        if(c>maxR){
            maxR=c;
        }
    }
    return arr;
}

int main(){
    int n=5;
    vector<int> arr={17,18,5,4,6,1};

    cout<<"Original: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    replaceElements(arr);

    cout<<"After Replacing: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}