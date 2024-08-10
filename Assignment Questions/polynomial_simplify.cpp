#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

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
            std::cout << "0";
            return;
        }
        Node* temp = head;
        while (temp) {
            std::cout << temp->coefficient << "x^" << temp->exponent;
            temp = temp->next;
            if (temp) {
                std::cout << "+";
            }
        }
        std::cout << std::endl;
    }

    void simplify() {
        if (!head) return;
        std::unordered_map<int, int> terms;
        Node* temp = head;
        while (temp) {
            terms[temp->exponent] += temp->coefficient;
            temp = temp->next;
        }
        
        // Use a vector to store terms and sort by exponent in descending order
        std::vector<std::pair<int, int>> sortedTerms;
        for (const auto& term : terms) {
            if (term.second != 0) {
                sortedTerms.push_back(term);
            }
        }
        std::sort(sortedTerms.begin(), sortedTerms.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.first > b.first;
        });

        // Create a new linked list from sorted terms
        Node* simplifiedHead = nullptr;
        Node* simplifiedTail = nullptr;
        for (const auto& term : sortedTerms) {
            Node* newNode = new Node(term.second, term.first);
            if (!simplifiedHead) {
                simplifiedHead = newNode;
                simplifiedTail = newNode;
            } else {
                simplifiedTail->next = newNode;
                simplifiedTail = newNode;
            }
        }
        head = simplifiedHead;
    }
};

int main() {
    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << "0" << std::endl;
        return 0;
    }

    Polynomial poly;

    for (int i = 0; i < n; ++i) {
        int coefficient, exponent;
        std::cin >> coefficient >> exponent;
        poly.insertTerm(coefficient, exponent);
    }

    std::cout << "Original Polynomial: ";
    poly.display();

    poly.simplify();

    std::cout << "Simplified Polynomial: ";
    poly.display();

    return 0;
}
