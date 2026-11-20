#include <iostream>
#include <stack>
using namespace std;

// Print stack elements and restore them using a temp stack
void printStack(stack<int>& s) {
    stack<int> temp;

    // 1. Pop, print, and save into temp
    while (!s.empty()) {
        cout << s.top() << " ";
        temp.push(s.top());
        s.pop();
    }
    cout << endl;

    // 2. Restore elements back into original stack
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
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

