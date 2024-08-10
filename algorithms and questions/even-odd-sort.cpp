//Even-odd sorting
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

// Function to reverse a linked list
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

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to arrange even and odd numbers
Node* arrangeEvenOdd(Node* head) {
    Node* evenHead = nullptr;
    Node* oddHead = nullptr;

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data % 2 == 0) {
            insertAtEnd(&evenHead, temp->data);
        } else {
            insertAtEnd(&oddHead, temp->data);
        }
        temp = temp->next;
    }

    // Reverse the even list
    evenHead = reverseList(evenHead);

    // Concatenate the even and odd lists
    if (evenHead == nullptr) return oddHead;
    if (oddHead == nullptr) return evenHead;

    Node* resultHead = evenHead;
    while (evenHead->next != nullptr) {
        evenHead = evenHead->next;
    }
    evenHead->next = oddHead;

    return resultHead;
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

    Node* resultHead = arrangeEvenOdd(head);

    cout << "The rearranged list is: ";
    printList(resultHead);

    return 0;
}
