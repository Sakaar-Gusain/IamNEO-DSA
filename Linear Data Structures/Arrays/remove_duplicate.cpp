//Replace Elements with Greatest Element on Right Side

#include <bits/stdc++.h>
using namespace std;

int remove_duplicate(vector<int>& arr) {
    int n=arr.size();
    int j=1;
    for (int i=1;i<n;i++){
        if(arr[i] != arr[i-1]){
            arr[j]=arr[i+1];
            j++;
        }
    }
    return j;
}

int main(){
    int n=10;
    vector<int> arr={0,0,1,1,1,2,2,3,3,4};

    cout<<"Original: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    remove_duplicate(arr);

    cout<<"After Replacing: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}