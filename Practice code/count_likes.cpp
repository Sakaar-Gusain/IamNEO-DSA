//To count number of topics both a and b liked or disliked. 0 is dislike and 1 is like
//Input first line has string for A's likes and dislikes
//Input second line has string for B's likes and dislikes
//Output shows likes or dislikes of A or B
#include <bits/stdc++.h>
#include <string>

using namespace std;

int count(string a, string b){
    int count=0;
    for(int i=0;i<b.length();i++){
        if(a[i]==b[i]){
            count +=1;
        }
    }
    return count;
}

int main(){
    string a,b;
    cin>>a;
    cin>>b;

    cout<<count(a,b)<<endl;
    return 0;
}