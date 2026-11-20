#include <iostream>
#include <stack>
#include <string>
using namespace std;

// C++ STL std::stack Built-in Methods & Operations Guide
// Under the hood: Container Adapter (default underlying container: std::deque)
// Header required: #include <stack>

void printStack(stack<int> s) {
    // Passed by value so original stack is preserved
    cout << "[Top -> Bottom]: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    cout << "=========================================" << endl;
    cout << "   C++ STL std::stack Built-in Methods   " << endl;
    cout << "=========================================" << endl;

    // 1. Initialization
    stack<int> s;

    // 2. empty() - Check if stack is empty (returns bool)
    cout << "\n1. Initial empty() check: " << (s.empty() ? "true (Stack is empty)" : "false") << endl;

    // 3. push(val) - Inserts element at the top
    cout << "\n2. Pushing elements: 10, 20, 30, 40..." << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // 4. emplace(val) - Constructs and inserts element in-place (often more efficient than push)
    s.emplace(50);
    cout << "Emplaced element: 50" << endl;

    // 5. size() - Returns number of elements
    cout << "\n3. Current size(): " << s.size() << endl;

    // 6. top() - Returns reference to the topmost element (without removing it)
    cout << "4. Current top() element: " << s.top() << endl;

    // Display stack contents
    cout << "\n5. Stack Traversal: ";
    printStack(s);

    // 7. pop() - Removes the topmost element (returns void)
    cout << "\n6. Calling pop() to remove top element..." << endl;
    s.pop(); // removes 50
    cout << "New top() after 1 pop: " << s.top() << endl;
    cout << "New size() after 1 pop: " << s.size() << endl;

    cout << "Stack after pop: ";
    printStack(s);

    // 8. swap() - Exchanges contents of two stacks of the same type
    stack<int> s2;
    s2.push(100);
    s2.push(200);

    cout << "\n7. Testing swap():" << endl;
    cout << "Before swap - Stack 1 top: " << s.top() << ", Stack 2 top: " << s2.top() << endl;
    s.swap(s2);
    cout << "After swap  - Stack 1 top: " << s.top() << ", Stack 2 top: " << s2.top() << endl;

    // 9. Practical Application: String Reversal using STL stack
    string str = "HELLO";
    stack<char> charStack;
    for (char c : str) charStack.push(c);

    string reversedStr = "";
    while (!charStack.empty()) {
        reversedStr += charStack.top();
        charStack.pop();
    }
    cout << "\n8. Practical Mini-App: String Reversal" << endl;
    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reversedStr << endl;

    return 0;
}
