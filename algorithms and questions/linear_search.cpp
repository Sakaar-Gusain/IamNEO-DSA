//linear search
#include <bits/stdc++.h>

using namespace std;

int linear_search(int arr[], int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int n,key;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>key;
    int index=linear_search(a,n,key);
    if(index==-1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<"Element found at index "<<index<<endl;
    }
}