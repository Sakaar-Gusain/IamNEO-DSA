#include <iostream>
using namespace std;

int main(){
    int p,r=0,remainder;
    cin>>p;

    while(p !=0){
        remainder = p%10;
        r = r*10 + remainder;
        p/=10;
    }

    if (p==r){
        cout<<"palindrome";
    }
    else{
        cout<<"not palindrome";
    }
    return 0;
}