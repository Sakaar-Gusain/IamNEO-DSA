//double linked list:
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode-> prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insertAtBeginning(Node** headRef, int data){
    Node* newNode = createNode(data);
    //Making next of new node as head and prev as null
    newNode->next = *headRef;
    newNode->prev = nullptr;
    

    if (*headRef !=nullptr){
        (*headRef)-> prev = newNode;
    }
    *headRef = newNode;
}

void printList(Node* node){
    Node* last;
    cout<<"Doubly linked list in forward direction";

    while(node !=nullptr){
        cout<<node->data<<" ";
        last = node;
        node = node ->next;
    }
    cout<<endl;

    cout<<"Doubly linked list in reverse direction";
    while (last !=nullptr){
        cout<<last->data<<" ";
        last = last->prev;
    }
    cout<<endl;
}

int main(){
    Node* head = nullptr;

    insertAtBeginning(&head,10);
    insertAtBeginning(&head,20);
    insertAtBeginning(&head,30);
    printList(head);   
    return 0;
    
}