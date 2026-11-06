#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

// Convert Infix to Prefix (Polish notation)
string infixToPrefix(string infix) {
    // 1. Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // 2. Swap '(' and ')'
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // 3. Obtain postfix of reversed expression
    stack<char> st;
    string result = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        } else if (c == '(') {
            st.push('(');
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        } else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    // 4. Reverse the postfix result to get prefix
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string infix = "(A-B/C)*(A/K-L)";
    cout << "Infix: " << infix << endl;
    cout << "Prefix: " << infixToPrefix(infix) << endl;

    return 0;
}

