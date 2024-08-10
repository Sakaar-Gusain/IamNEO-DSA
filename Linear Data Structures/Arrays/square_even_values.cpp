//squaring values in even position in array
#include <bits/stdc++.h>
using namespace std;

vector<int> square_even(vector<int>& a, int l){
    if(l == 0){
        return a;
    }
    for(int i=0;i<l;i++){
        if(i%2==0) a[i] = pow(a[i],2);
    }
    return a;
}

int main(){
    int n;
    n = 5;
    vector<int> a(n);
    a = {1,4,6,35,85};

    cout<<"Original:";
    for(int i: a){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"After:";
    square_even(a,n);
    for(int i: a){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;

}