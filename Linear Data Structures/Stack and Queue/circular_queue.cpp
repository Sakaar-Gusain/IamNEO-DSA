//code for circular queue
#include <iostream>
using namespace std;

class Queue{
    int rear, front;
    int size;
    int *arr;
    public:
    Queue(int s){
        front = rear=-1;
        size = 5;
        arr = new int(s);
    }

    void enQ(int value);
    int deQ();
    void display();
};

void Queue::enQ(int value){
    if((front == 0 && rear == size-1)||((rear+1)%size == front)){
        cout << "\nQueue is full" << endl;
        return;
    }
    else if(front == -1){
        front = rear = 0;
        arr[rear] = value;
    }
    else if(rear == size-1 && front !=0){
        rear = 0;
        arr[rear] = value;
    }
    else{
        rear++;
        arr[rear] = value;
    }
}

int Queue:: deQ(){
    if(front == -1){
        cout<<"\nQueue is empty";
        return INT_MIN;
    }
    int data = arr[front];
    arr[front] = -1;

    if(front == rear){
        front = -1;
        rear = -1;
    }
    else if(front == size-1){
        front = 0;
    }
    else
    front++;
    return data;
    
}

void Queue::display(){
    if(front == -1){
        cout<<"\nQueue empty";
        return;
    }
    if (rear>=front){
        for(int i=front;i<=rear;i++){
            cout<<arr[i];
        }
    }
    else{
        for (int i = front;i<size;i++){
            cout<<arr[i];
        }
        for (int i = 0;i<=rear;i++){
            cout<<arr[i];
        }
    }
}

int main(){
    Queue q(5);

    q.enQ(1);
    q.enQ(2);
    q.enQ(3);
    q.enQ(4);
    q.enQ(-1);
    q.display();
    cout<<"\nDeleted value "<<q.deQ()<<endl;
    cout<<"\nDeleted value "<<q.deQ()<<endl;
    q.display();
    q.enQ(9);
    q.enQ(20);
    q.enQ(5);

}