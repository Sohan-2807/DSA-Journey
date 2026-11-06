#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() {
        top = -1;
    }

    bool push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow" << endl;
            return false;
        }
        arr[++top] = x;
        return true;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return (top < 0);
    }

    void display() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack elements (top to bottom): ";
    s.display();

    cout << "Top element is: " << s.peek() << endl;

    cout << "Popped element: " << s.pop() << endl;
    cout << "Stack after pop: ";
    s.display();

    return 0;
}

