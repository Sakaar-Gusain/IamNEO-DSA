//change from roman to numbers

#include <bits/stdc++.h>
using namespace std;

int check_roman(string s, map<char, int> m){
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(i+1<s.size() && m[s[i]]<m[s[i+1]]){
            ans-=m[s[i]];
        }
        else{
            ans+=m[s[i]];
            
        }
    }
    return ans;
}

int main(){
    map <char, int> m= {{'I',1},{'V',5},{'X',10},{'L', 50},{'C',100},{'D', 500},{'M',1000}};
    string s;
    cout<<"Enter roman value:";
    cin>>s;

    bool isValid = true;
    for (char c: s){
        if(m.find(c) == m.end()){
            isValid = false;
            break;
        }
    }
    if(isValid){
        cout<<check_roman(s, m)<<endl;
    }
    else{
        cout<<"Invalid characters found."<<endl;
    }
    return 0;
}