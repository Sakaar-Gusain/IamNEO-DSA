// Double Linked list
#include<iostream> 
using namespace std; 
struct Node { 
    int data; 
    Node* prev; 
    Node* next; 
}; 
Node* createNode(int data) { 
    Node* newNode = new Node(); 
    newNode->data = data; 
    newNode->prev = nullptr; 
    newNode->next=nullptr; 
    return newNode; 
} 

void insertATBeginning(Node** headRef, int data) { 
    Node* newNode = createNode(data); 
    //Making the next of new node as head and prevoius as null 
    newNode->next = *headRef; 
    newNode->prev = nullptr; 
    //Changing prevoius of head node to new node 
    if(*headRef != nullptr) { 
        (*headRef)->prev= newNode; 
    } //Move the head to point the new 
    *headRef = newNode; 
} 

void printList(Node* node) { 
    Node* last; 
    cout<<"Doubly linked list in forward direction: "; 
    while(node != nullptr) { 
        cout<< node->data <<" "; 
        last = node; node = node->next; 
    } 
    cout<<endl; cout<<"Doubly Linked list in reverse direction "; 
    while(last != nullptr) { 
        cout<< last->data<<" "; 
        last = last->prev; 
    } 
    cout<<endl; 
}


int main() { 
    Node* head = nullptr;  
    insertATBeginning(&head,10); 
    insertATBeginning(&head,20); 
    insertATBeginning(&head,30); 
    printList(head);
}