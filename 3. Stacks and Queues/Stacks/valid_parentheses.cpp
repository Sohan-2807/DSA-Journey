#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValidParentheses(const string& s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string test1 = "{[()]}";
    string test2 = "{[(])}";

    cout << test1 << " -> " << (isValidParentheses(test1) ? "Valid" : "Invalid") << endl;
    cout << test2 << " -> " << (isValidParentheses(test2) ? "Valid" : "Invalid") << endl;

    return 0;
}
