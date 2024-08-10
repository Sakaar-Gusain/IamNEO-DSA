//single linked list
#include <iostream>
using namespace std;

// Define the node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main() {
    int n;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    Node* head = nullptr;
    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtEnd(&head, value);
    }

    cout << "The linked list is: ";
    printList(head);

    cout<<"reversed list:";
    head = reverseList(head);
    printList(head);
    return 0;
}
