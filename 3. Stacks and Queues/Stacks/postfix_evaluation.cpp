#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Evaluate postfix expression
int evaluatePostfix(string exp) {
    stack<int> st;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        // If operand, push onto stack
        if (isdigit(c)) {
            st.push(c - '0');
        }
        // If operator, pop two operands, apply operator, push result
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }

    return st.top();
}

int main() {
    string exp = "231*+9-";
    // Expression represents: 2 + (3 * 1) - 9 = -4
    cout << "Postfix expression: " << exp << endl;
    cout << "Evaluated Result: " << evaluatePostfix(exp) << endl;

    string exp2 = "53+82-*";
    // Expression represents: (5 + 3) * (8 - 2) = 48
    cout << "\nPostfix expression: " << exp2 << endl;
    cout << "Evaluated Result: " << evaluatePostfix(exp2) << endl;

    return 0;
}

