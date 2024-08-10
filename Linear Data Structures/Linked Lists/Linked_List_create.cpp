#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertEnd(Node*& head, int data){
    Node* newNode = createNode(data);
    if(head == nullptr){
        head = newNode;
    }
    else{
        Node* temp = head;  
        while(temp->next !=nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(Node* head){
    Node* temp= head;
    while(temp != nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = nullptr;

    insertEnd(head,10);
    insertEnd(head,20);
    insertEnd(head,30);

    display(head);
    return 0;
}
