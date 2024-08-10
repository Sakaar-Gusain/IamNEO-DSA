#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};


void insertEnd(struct Node **head_ref, int element){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = element;
    new_node->next = NULL; 

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    else{
        while(last->next != NULL){
            last=last->next;
        }
        last->next = new_node;
    }
}

int main(){
    struct Node *head = NULL;
    int n, elements;
    cin>>n;
    for (int i =0;i<n;i++ ){
        cin>>elements;
        insertEnd(&head,elements);
    }
}