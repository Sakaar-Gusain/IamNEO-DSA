#include <iostream>
using namespace std;
struct Node{
    int data;
    int priority;
    Node* prev;
    Node* next;

    Node(int d, int p) : data(d), priority(p), next(nullptr), prev(nullptr) {}
};

class PriorityQ{
private:
    Node* head;
    
public:
    PriorityQ() : head(nullptr) {}

    void insert(int data, int priority){
        Node* newNode = new Node(data, priority);
        if(!head){
            head = newNode;
        }
        else if(head->priority){
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp->next && temp->next->priority >=priority){
                temp=temp->next;
            }
            newNode->next = temp->next;
            if(temp->next){
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    void del_high(){
        if(!head){
            cout<<"Empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head){
            head->prev = nullptr;
        }
        delete temp;
    }
    void show(){
        if(!head){
            cout<<"List empty"<<endl;
            return;
        }
        Node* temp = head;
        while (temp){
            cout<<"("<<temp->data<<","<<temp->priority<<")";
            temp=temp->next;
        }

        cout<<endl;
    
    }
    

    ~PriorityQ(){
        while(head){
            del_high();
        }
    } 
};

int main(){
    PriorityQ p;

    p.insert(100,3);
    p.insert(101,2);
    p.insert(103,5);
    p.insert(104,1);

    cout<<"Before deletion"<<endl;
    p.show();

    p.del_high();

    cout<<"After deletion"<<endl;
    p.show();
    return 0;
}