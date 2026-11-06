#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Insert at beginning
void insertBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head != nullptr) {
        head->prev = newNode;
        newNode->next = head;
    }
    head = newNode;
}

// Insert at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete at beginning
void deleteBeginning(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

// Delete at end
void deleteEnd(Node*& head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
}

// Search for an element
bool search(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

// Traversal forward and backward
void displayForward(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertBeginning(head, 5);

    cout << "Doubly Linked List (Forward): ";
    displayForward(head);

    cout << "Searching for 20: " << (search(head, 20) ? "Found" : "Not Found") << endl;

    deleteBeginning(head);
    cout << "After deleteBeginning: ";
    displayForward(head);

    deleteEnd(head);
    cout << "After deleteEnd: ";
    displayForward(head);

    return 0;
}

