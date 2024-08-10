//parenthesis balancing using stack
#include <bits/stdc++.h>
using namespace std;

bool BalanceParenthesis(const string& expr){
    stack<char> s;
    char x;

    for (char ch: expr){
        if(ch =='(' || ch == '[' || ch == '{'){
            s.push(ch);
            continue;
        }

        if(s.empty())
        return false;

        switch(ch){
            case ')':
            x = s.top();
            s.pop();
            if(x == '{' || x == '[')
            return false;
            break;

            case '}':
            x = s.top();
            s.pop();
            if(x == '(' || x == '[')
            return false;
            break;

            case ']':
            x = s.top();
            s.pop();
            if(x == '(' || x == '{')
            return false;
            break;
        }
    }
    return s.empty();
}

int main(){
    string expr;
    getline(cin,expr);
    if(BalanceParenthesis(expr)){
        cout << "Balanced";
    }
    else{
        cout << "Not Balanced";
    }
    return 0;
}