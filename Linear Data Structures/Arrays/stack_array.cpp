#include <iostream>
using namespace std;

#define SIZE 3
void push(int);
void pop();
void display();
int stack[SIZE], top = -1;
int main(){
    int v,ch;
    while(1){
        cin>>ch;
        switch(ch){
            case 1:
                cin>>v;
                push(v);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"Wrong selection";
                break;
        }
        
    }
    return 0;
}

void push(int v){
    if(top == SIZE-1){
        cout<<"Overflow!!"<<endl;
    }
    else{
        top++;
        stack[top] = v;
    }
}

void pop(){
    if(top == -1){
        cout<<"Underflow!!"<<endl;
    }
    else{
        cout<<"Deleted element from stack is:"<<stack[top];
        top--;
    }   
}

void display(){
    if(top == -1){
        cout<<"Stack is empty!!"<<endl;
    }
    else{
        for(int i = top;i>=0;i--){
            cout<<"|"<<stack[i]<<"|"<<endl; 
       }
    }
}