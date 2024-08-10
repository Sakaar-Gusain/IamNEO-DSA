#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Stack {
    Node* top;
public:
    Stack() : top(nullptr) {}
    ~Stack();
    void push(int x);
    int pop();
    int peek();
    int size();
    bool isEmpty();
};

// Destructor to clean up the memory
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

// Push an element onto the stack
void Stack::push(int x) {
    Node* newNode = new Node(x);
    newNode->next = top;
    top = newNode;
}

// Pop an element from the stack
int Stack::pop() {
    if (isEmpty()) {
        throw out_of_range("Stack Underflow");
    }
    int poppedValue = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return poppedValue;
}

// Peek at the top element of the stack
int Stack::peek() {
    if (isEmpty()) {
        throw out_of_range("Stack is Empty");
    }
    return top->data;
}

// Get the size of the stack
int Stack::size() {
    int count = 0;
    Node* current = top;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Check if the stack is empty
bool Stack::isEmpty() {
    return top == nullptr;
}

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element is: " << s.peek() << endl;
    cout << "Stack size is: " << s.size() << endl;
    cout << "Popped element is: " << s.pop() << endl;
    cout << "Stack size is: " << s.size() << endl;
    cout << "Is stack empty: " << (s.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}
