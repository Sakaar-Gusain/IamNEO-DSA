// to merge two circular lists
#include<bits/stdc++.h> 
using namespace std; 
struct Node { 
    int data; 
    Node* next; 
    Node(int val) : data(val), next(nullptr) {} 
}; 
    //function to merge 2 circular linkedlists 
Node* mergecircularLists(Node* head1, Node* head2){ 
    if(!head1) 
    return head2; 
    if(!head2) 
    return head1; 
    //to find Last node of circular linked linkedlists 
    Node* temp1 = head1; 
    while(temp1->next !=head1) { 
        temp1 = temp1->next; 
    } //to find Last node of second circular Linkedlist 
    Node* temp2 = head2; 
    while(temp2->next !=head2) { 
        temp2 = temp2->next; 
    } 
    //connecting the last node of first list to the head of second list; 
    temp1->next = head2; 
    //connecting the last node of second list to head of first list; 
    temp2->next = head1; 
    return head1; 
} 
void printcircularList(Node* head) { 
    if(!head) 
    return; 
    Node* temp = head; 
    do { 
        cout<<temp->data<<" "; 
        temp = temp->next; 
    }
    while(temp != head); { 
        cout<<endl; 
    }
} 
Node* createcircularList(int arr[], int n) { 
    if(n==0) 
    return nullptr; 
    Node* head = new Node(arr[0]); 
    Node* tail = head; 
    for(int i =1; i<n; i++) { 
        tail->next = new Node(arr[i]); 
        tail=tail->next; 
    } 
    tail->next = head; 
    return head; 
} 

int main() { 
    int arr1[] = {1,2,3}; 
    int arr2[] = {8,5,6}; 
    Node* head1 = createcircularList(arr1, 3); 
    Node* head2 = createcircularList(arr2, 3); 
    cout<<"List 1:"; printcircularList(head1); 
    cout<<"List 2:"; printcircularList(head2); 
    Node* mergedHead = mergecircularLists(head1, head2); 
    cout<<"Merged List: "; printcircularList(mergedHead); 
    return 0;
}