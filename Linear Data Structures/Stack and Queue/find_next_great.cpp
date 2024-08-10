#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int top = -1;
int stack[MAX_SIZE];

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX_SIZE - 1;
}

void push(int x) {
    if (isFull()) {
        // Stack overflow
        return;
    } else {
        top++;
        stack[top] = x;
    }
}

int pop() {
    if (isEmpty()) {
        // Stack underflow
        return -1;
    } else {
        int element = stack[top];
        top--;
        return element;
    }
}

void printNGE(int arr[], int n) {
    int i, next;
    int element, nge;

    push(arr[0]);

    for (i = 1; i < n; i++) {
        next = arr[i];

        if (!isEmpty()) {
            element = pop();

            while (element < next) {
                cout << element << " " << next << endl;

                if (isEmpty())
                    break;

                element = pop();
            }

            if (element > next)
                push(element);
        }

        push(next);
    }

    while (!isEmpty()) {
        element = pop();
        nge = -1;
        cout << element << " " << nge << endl;
    }
}

int main() {
    int n;

    cin >> n;

    int arr[n];  // Note: Variable Length Arrays are not part of standard C++, but they may work in some compilers.

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    printNGE(arr, n);

    return 0;
}
/*

#include <iostream>
#include <stack>

using namespace std;

void findNext(int a[], int n, int ng[]) {
    stack<int> s;
    
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= a[i]) {
            s.pop();
        }
        if (!s.empty()) {
            ng[i] = s.top();
        } else {
            ng[i] = -1;
        }
        s.push(a[i]);
    }
}

int main() {
    int size;
    cin >> size;
    
    int A[size];
    int NG[size];
    for (int i = 0; i < size; ++i) {
        cin >> A[i];
    }
    
    findNext(A, size, NG);
    
    for (int i = 0; i < size; ++i) {
        cout << A[i] << " " << NG[i] << endl;
    }
    return 0;
}
*/