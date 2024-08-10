//stack using array
#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
class Stack{
    int top;
public:
int a[MAX]; // maximum size of stack array
Stack() { top = -1; } // stack is empty
bool push(int x);
int pop();
int peek();
bool isEmpty();
};

bool Stack::push(int x){
    if(top>=(MAX-1)){
        cout << "Stack Overflow";
        return false;
    }
    else{
        a[++top] = x;
        cout<<x<<" Inserted into stack\n";
        return true;
    }
}
int Stack::peek(){
    if(top<0){
        cout<<"Stack is empty";
    }
    else{
        int x = a[top];
        return x;
    }
}
int Stack::pop()
{
    if(top < 0)
    {
        cout<<"Stack Underflow\n";
    }
    else
    {
        int x = a[top--];
        return x;
    }
}
 

bool Stack::isEmpty(){
    return(top<0);
}

int main(){
    class Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout<<s.pop()<<"Element is popped\n";
    cout<<"Top element is:"<<s.peek()<<endl;

    while(!s.isEmpty()){
        cout<<s.peek()<<" ";
        s.pop();
    }
}