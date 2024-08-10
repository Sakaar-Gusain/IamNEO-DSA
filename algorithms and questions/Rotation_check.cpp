//checking whether s2 is rotation of s1 or not;
#include <iostream>
using namespace std;

int check_rot(string s1,string s2){
    if (s1.length()==s2.length()&&! s1.empty()){
        string c = s1+s2;
        return c.find(s2) !=string::npos;
    }
    return false;
}

int main(){
    string s1,s2;
    cout<<"String1:";
    cin>>s1;

    cout<<"String2:";
    cin>>s2;
    if(check_rot(s1,s2)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;

}