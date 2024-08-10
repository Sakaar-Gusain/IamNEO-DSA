#include <iostream>

struct Node {
    int coefficient;
    int exponent;
    Node* next;
    Node(int coef, int exp) : coefficient(coef), exponent(exp), next(nullptr) {}
};

class Polynomial {
public:
    Node* head;

    Polynomial() : head(nullptr) {}

    void insertTerm(int coefficient, int exponent) {
        Node* newNode = new Node(coefficient, exponent);
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

    void display() {
        if (!head) {
            std::cout << "Empty polynomial!";
            return;
        }
        Node* temp = head;
        while (temp) {
            std::cout << temp->coefficient << "x^" << temp->exponent;
            temp = temp->next;
            if (temp) {
                std::cout << " + ";
            }
        }
        std::cout << std::endl;
    }

    Polynomial multiply(Polynomial& other) {
        Polynomial result;
        for (Node* ptr1 = head; ptr1 != nullptr; ptr1 = ptr1->next) {
            for (Node* ptr2 = other.head; ptr2 != nullptr; ptr2 = ptr2->next) {
                result.insertTerm(ptr1->coefficient * ptr2->coefficient, ptr1->exponent + ptr2->exponent);
            }
        }
        return result;
    }
};

int main() {
    int n, m;

    std::cin >> n;
    if (n == 0) {
        std::cout << "Empty polynomial(s)!" << std::endl;
        return 0;
    }

    Polynomial poly1;
    for (int i = 0; i < n; ++i) {
        int coef, exp;
        std::cin >> coef >> exp;
        poly1.insertTerm(coef, exp);
    }

    std::cin >> m;
    if (m == 0) {
        std::cout << "Empty polynomial(s)!" << std::endl;
        return 0;
    }

    Polynomial poly2;
    for (int i = 0; i < m; ++i) {
        int coef, exp;
        std::cin >> coef >> exp;
        poly2.insertTerm(coef, exp);
    }

    std::cout << "Polynomial 1:" << std::endl;
    poly1.display();
    std::cout << "Polynomial 2:" << std::endl;
    poly2.display();

    Polynomial result = poly1.multiply(poly2);

    std::cout << "Result of polynomial multiplication:" << std::endl;
    result.display();

    return 0;
}
