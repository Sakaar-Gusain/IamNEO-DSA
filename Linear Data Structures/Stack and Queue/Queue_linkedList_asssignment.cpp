/*
Fathima has been tasked with developing a program to manage a queue of customers waiting in line at a 
service center. Help her write a program that will simulate a queue data structure using a linked list. 

Here is a description of the scenario and the required operations:

Enqueue: Add a customer to the end of the queue.
Dequeue: Remove and discard a customer from the front of the queue.
Display waiting customers: Display the front and rear customer IDs in the queue.


Write a program that enqueues all the customers into the queue, performs a dequeue operation, and 
then prints the front and rear elements.

Input format :
The first line of input consists of an integer N, representing the number of customers to be 
inserted into the queue.
The second line consists of N space-separated integers, representing the customer IDs.

Output format :
The output prints "Front: X, Rear: Y" where X is the front element and Y is the rear elements, after 
performing a dequeue operation.

Input 1 :
5
112 104 107 116 109
Output 1 :
Front: 104, Rear: 109

Input 2 :
8
102 104 106 108 115 116 123 125
Output 2 :
Front: 104, Rear: 125
*/


#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr){}
};

class Q{
public:
    Q(): front(nullptr), rear(nullptr){}
    void enqueue(int data){
        Node* newNode=new Node(data);
        if(rear==nullptr){
            front=rear=newNode;
            return;
        }
        rear->next=newNode;
        rear=newNode;
    }
    
    void dequeue(){
        if(front==nullptr){
            return;
        }
        Node* temp=front;
        front=front->next;
        if(front==nullptr){
            rear=nullptr;
        }
        delete temp;
    }
    
    int getF(){
        if(front != nullptr){
            return front->data;
        }
        return -1;
    }
    
    int getR(){
        if(rear != nullptr){
            return rear->data;
        }
        return -1;
    }
private:
    Node* front;
    Node* rear;
};

int main(){
    int n;
    cin>>n;
    
    Q q;
    for(int i=0;i<n;++i){
        int id;
        cin>>id;
        q.enqueue(id);
    }
    q.dequeue();
    cout<<"Front: "<<q.getF()<<", Rear: "<<q.getR()<<endl;
    return 0;
}