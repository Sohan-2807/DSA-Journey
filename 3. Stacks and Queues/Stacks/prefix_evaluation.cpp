#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Evaluate prefix expression (Polish Notation)
// Prefix is evaluated by scanning from RIGHT to LEFT
int evaluatePrefix(string exp) {
    stack<int> st;

    // Traverse from right to left
    for (int i = exp.length() - 1; i >= 0; i--) {
        char c = exp[i];

        // Skip whitespace
        if (c == ' ') continue;

        // If character is operand, push onto stack
        if (isdigit(c)) {
            st.push(c - '0');
        }
        // If character is operator, pop 2 operands and apply operator
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (st.empty()) return -1;
            int op1 = st.top(); st.pop(); // First operand
            if (st.empty()) return -1;
            int op2 = st.top(); st.pop(); // Second operand

            switch (c) {
                case '+': st.push(op1 + op2); break;
                case '-': st.push(op1 - op2); break;
                case '*': st.push(op1 * op2); break;
                case '/': st.push(op1 / op2); break;
            }
        }
    }

    return st.top();
}

int main() {
    // Example 1: + 9 * 2 6 = 9 + (2 * 6) = 21
    string exp1 = "+9*26";
    cout << "Prefix expression: " << exp1 << endl;
    cout << "Evaluated Result: " << evaluatePrefix(exp1) << endl;

    // Example 2: - + 2 * 3 1 9 = (2 + (3 * 1)) - 9 = -4
    string exp2 = "-+2*319";
    cout << "\nPrefix expression: " << exp2 << endl;
    cout << "Evaluated Result: " << evaluatePrefix(exp2) << endl;

    // Example 3: * + 5 3 - 8 2 = (5 + 3) * (8 - 2) = 8 * 6 = 48
    string exp3 = "*+53-82";
    cout << "\nPrefix expression: " << exp3 << endl;
    cout << "Evaluated Result: " << evaluatePrefix(exp3) << endl;

    return 0;
}
