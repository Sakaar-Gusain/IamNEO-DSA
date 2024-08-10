//Queue using linked list
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class Queue{
    private:
    Node* front;
    Node* rear;
    public:
    Queue(){
        front = nullptr;
        rear = nullptr;
    }
    ~Queue(){
        while(front !=nullptr){
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty(){
        return front == nullptr;
    }

    void enqueue(int item){
        Node* newNode = new Node(item);
        if(rear == nullptr){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        cout<<"Enqueued element:"<<item<<endl;
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty\n";
            return INT_MIN;
        }
        int item = front->data;
        Node* temp = front;
        front = front->next;

        if(front == nullptr){
            rear = nullptr;
        }
        delete temp;
        cout<<"Dequeued element:"<<item<<endl;
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is empty";
            return;
        }
        Node*temp = front;
        cout<<"Queue elements";
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    q.dequeue();
    q.display();
    return 0;
}