#include <iostream>
#include <stack>
using namespace std;

// Print stack elements
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;

    // push elements
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.emplace(50);

    cout << "Top element: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;

    cout << "Stack: ";
    printStack(s);

    // remove top element
    s.pop();
    cout << "Top after pop: " << s.top() << endl;

    // check if empty
    if (s.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    // swap with another stack
    stack<int> s2;
    s2.push(100);
    s2.push(200);

    s.swap(s2);
    cout << "Top after swap: " << s.top() << endl;

    return 0;
}
