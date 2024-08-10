#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string& expr) {
    stack<int> s;
    for (char ch : expr) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else if (!isspace(ch)) {  // ignore spaces
            if (s.size() < 2) {
                throw invalid_argument("Insufficient operands in expression");
            }
            int val1 = s.top(); s.pop();
            int val2 = s.top(); s.pop();
            switch (ch) {
                case '+':
                    s.push(val2 + val1);
                    break;
                case '-':
                    s.push(val2 - val1);
                    break;
                case '*':
                    s.push(val2 * val1);
                    break;
                case '/':
                    if (val1 == 0) {
                        throw invalid_argument("Division by zero");
                    }
                    s.push(val2 / val1);
                    break;
                default:
                    throw invalid_argument("Invalid operator");
            }
        }
    }
    if (s.size() != 1) {
        throw invalid_argument("Invalid postfix expression");
    }
    return s.top();
}

int main() {
    string expr;
    getline(cin, expr);
    try {
        int result = evaluatePostfix(expr);
        cout << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
