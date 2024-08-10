//To put sort scores then showing highest score
#include <iostream>
#include <climits>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    
    LinkedList() : head(nullptr) {}
    
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void sort() {
        if (!head) return;
        bool swapped;
        Node* ptr1;
        Node* lptr = nullptr;
        do {
            swapped = false;
            ptr1 = head;
            while (ptr1->next != lptr) {
                if (ptr1->data > ptr1->next->data) {
                    std::swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    int getMax() {
        if (!head) return INT_MIN;
        int max = head->data;
        Node* temp = head;
        while (temp) {
            if (temp->data > max) {
                max = temp->data;
            }
            temp = temp->next;
        }
        return max;
    }

    void display() {
        Node* temp = head;
        std::cout << "[";
        while (temp) {
            std::cout << temp->data;
            if (temp->next) {
                std::cout << ", ";
            }
            temp = temp->next;
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    int N;
    std::cin >> N;

    if (N == 0) {
        std::cout << "Empty polynomial(s)!" << std::endl;
        return 0;
    }

    LinkedList list;
    for (int i = 0; i < N; ++i) {
        int score;
        std::cin >> score;
        list.insert(score);
    }

    list.sort();
    
    list.display();

    int highestScore = list.getMax();
    std::cout << highestScore << std::endl;

    return 0;
}
