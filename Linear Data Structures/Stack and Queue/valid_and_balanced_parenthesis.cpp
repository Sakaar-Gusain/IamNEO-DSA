/* Check for valid and balanced parenthesis (stack application)
Input:
Enter a string: (abc[def{ghi}jkl])
Output: 
The parentheses are valid and balanced


Example2:
Input:
Enter a string: (abc[def{ghi}jkl]
Output: 
The parentheses are not balanced
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isBalanced(const string& e){
    stack<char> s;
    
    for(char c:e){
        if(c=='('||c=='{'||c=='['){
            s.push(c);
        }
        else if(c==')'||c=='}'||c==']'){
            if(s.empty()){
                return false;
            }
            char t=s.top();
            s.pop();
            if((c=='(' && t != ')')||(c=='{' && t !='}')||(c=='[' && t!=']')){
                return false;
            }
        }
    }
    return s.empty();
}

int main(){
    string e;
    getline(cin,e);
    if(isBalanced(e)){
        cout<<"The parentheses are valid and balanced"<<endl;
    }
    else{
        cout<<"The parentheses are not balanced"<<endl;
    }
    return 0;
}