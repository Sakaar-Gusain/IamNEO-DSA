// circular linked list creation
#include<bits/stdc++.h> 
using namespace std; 
struct Node { 
    int data;
    Node* next; 
    Node(int val) : data(val), next(nullptr) {} 
}; 
//Function to insert node at the beginning 
void insertAtBeginning(Node*& head, int data) { 
    Node* newNode = new Node(data); 
    if(!head) { 
        //List is empty, new node points to itself 
        newNode->next = newNode; 
        head = newNode; 
    } 
    else { 
        Node* temp = head; 
        //Find the last Node 
        while(temp->next != head) { 
            temp = temp->next; 
        } 
        //Point the new node to current head 
        newNode->next = head; 
        //Point the last to new node; 
        temp->next = newNode; 
        //update head to new node 
        head = newNode; 
    }
} 
//Fuction to print the circular linked List 
void printCircularList(Node* head) { 
    if(!head) 
    return; 
    Node* temp = head; 
    do { 
        cout<<temp->data<<" "; 
        temp = temp->next; 
    } 
    while(temp!=head); 
    cout<<endl; 
} 
    
int main() { 
    Node* head = nullptr; 
    //Inser elemts at beginning 
    insertAtBeginning(head, 10); 
    insertAtBeginning(head, 20); 
    insertAtBeginning(head, 30); 
    cout<<"Circular Linkd List:"; 
    printCircularList(head); 
    return 0;
}