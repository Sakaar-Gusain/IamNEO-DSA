/* Swaping first and last in cll
Input 1 :
10
3 4 5 6 7 8 1 2 3 9

Output:
Before Swap: 3 4 5 6 7 8 1 2 3 9 
After Swap: 9 4 5 6 7 8 1 2 3 3 
*/
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* addE(Node* head, int data){
    if(head != nullptr){
        return head;
    }
    
    Node* temp = new Node;
    temp->data=data;
    head=temp;
    head->next=head;
    return head;
}

Node* addB(Node* head, int data){
    if(head ==nullptr){
        return addE(head,data);
    }
    Node* temp=new Node;
    temp->data=data;
    temp->next=head->next;
    head->next=temp;
    
    return head;
}

void traverse(Node* head){
    if(head ==nullptr){
        cout<<"List is Empty"<<endl;
        return;
    }
    
    Node* p =head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p !=head);
    cout<<endl;
}

Node* exchange(Node* head){
    if(head ==nullptr || head->next ==head){
        return head;
    }
    
    Node* p=head;
    while(p->next->next != head){
        p=p->next;
    }
    p->next->next=head->next;
    head->next=p->next;
    p->next=head;
    head=head->next;
    return head;
}

int main(){
    int m;
    cin>>m;
    int arr[m];
    
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    
    Node* head =nullptr;
    head=addE(head, arr[0]);
    for(int i=m-1;i>0;i--){
        head = addB(head, arr[i]);
    }
    
    cout<<"Before Swap: ";
    traverse(head);
    
    cout<<"After Swap: ";
    head=exchange(head);
    traverse(head);
    return 0;
}