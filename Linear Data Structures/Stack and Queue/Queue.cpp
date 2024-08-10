//queue
#include<bits/stdc++.h>
using namespace std;
struct Queue{
    int front,rear,capacity;
    int* queue;
    Queue(int c){
        front = rear = 0;
        capacity = c;
        queue = new int[c];
    }
    void qEnqueue(int data){
        if(capacity==front){
            cout<<"Queue full";
            return;
        }
        else{
            queue[front] = data;
            front++;
        }
        return;
    }
    void qDequeue(){
        if(front==rear){
            cout<<"Queue empty";
            return;
        }
        else{
            for(int i =0;i<front-1;i++){
                queue[i] = queue[i+1];
            }
            front--;
        }
        return;
    }
    void qDisplay(){
        int i;
        if(rear == front){
            cout<<"Queue empty";
            return;
        }
        for(i = rear;i<front;i++){
            cout<<"<---"<<queue[i];
        }
        return;
    }

    void QFront(){
        if(rear == front){
            cout<<"Queue empty";
        }
        cout<<" "<<queue[rear];
        return;
    }
};

int main(void){
    Queue q(4);
    q.qDisplay();

    q.qEnqueue(20);
    q.qEnqueue(30);
    q.qEnqueue(40);
    q.qEnqueue(50);

    q.qDisplay();
    q.QFront();
    return 0;
}