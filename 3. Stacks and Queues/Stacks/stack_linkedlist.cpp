#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class StackLinkedList {
    Node* top;

public:
    StackLinkedList() {
        top = nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        Node* temp = top;
        int poppedVal = temp->data;
        top = top->next;
        delete temp;
        return poppedVal;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return;
        }
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    StackLinkedList s;
    s.push(5);
    s.push(15);
    s.push(25);

    cout << "Stack (linked list representation): ";
    s.display();

    cout << "Peek top: " << s.peek() << endl;

    cout << "Popped: " << s.pop() << endl;
    cout << "Stack after pop: ";
    s.display();

    return 0;
}

