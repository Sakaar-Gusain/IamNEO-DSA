//Double ended queue
#include <iostream>
using namespace std;

class DeQue{
    int *deque;
    int front;
    int rear;
    int size;
    int capacity;
    public:
    DeQue(int c):capacity(c),front(-1),rear(0),size(0){
        deque = new int[capacity];
    }

    ~DeQue(){
        delete[] deque;
    }

    bool isFull(){
        return size = capacity;
    }

    bool isEmpty(){
        return size == 0;
    }

    void insertFront(int value){
        if(isFull()){
            cout<<"DeQue is full";
            return;
        }

        if(front == -1){
            front = 0;
            rear = 0;
        }
        else if(front ==0){
            front = capacity - 1;
        }
        else{
            front = front -1;
        }
        deque[front] = value;
        size++;
    }

    void insertRear(int value){
        if(isFull()){
            cout<<"DeQue is full"<<endl;
            return;
        }
        if(front ==-1){
            front = 0;
            rear = 0;
        }
        else if(rear == capacity-1){
            rear = 0;
        }
        else{
            rear = rear-1;
        }

        deque[rear] = value;
        size++;
    }

    void deleteFront(){
        if(isEmpty()){
            cout<<"DeQue is empty"<<endl;
            return;
        }
        if(front ==rear){
            front = -1;
            rear = -1;
        }
        else if(front == capacity-1){
            front = 0;
        }
        else{
            front = front -1;
        }
        size--;
    }

    void deleteRear(){
        if(isEmpty()){
            cout<<"DeQue is empty"<<endl;
            return;
        }
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else if(rear == 0){
            rear = capacity-1;
        }
        else{
            rear = rear-1;
        }
        size--;
    }

    void display(){
        if(isEmpty()){
            cout<<"Deque empty";
            return;
        }
        int i = front;
        while(true){
            cout<<deque[i]<<" ";
            if(i == rear)
            break;i = (i+1)%capacity;
        }
    }
};

int main(){
    DeQue dq(5);
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(15);
    dq.insertFront(2);
    dq.insertFront(25);
    cout<<"deque after inserting:"<<endl;
    dq.display();

    dq.deleteFront();
    dq.deleteRear();

    dq.display();
    return 0;
}
