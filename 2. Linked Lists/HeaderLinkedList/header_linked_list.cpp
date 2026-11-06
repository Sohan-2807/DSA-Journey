#include <iostream>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;
    Node(int val = 0) {
        data = val;
        next = nullptr;
    }
};

// 1. Grounded Header Linked List (Header node points to list, ends at nullptr)
class GroundedHeaderList {
    Node* header;

public:
    GroundedHeaderList() {
        header = new Node(-1); // Header node contains metadata (e.g. -1 or node count)
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        Node* temp = header;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = header->next; // Skip header
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// 2. Circular Header Linked List (Header node points to list, last node points back to header)
class CircularHeaderList {
    Node* header;

public:
    CircularHeaderList() {
        header = new Node(-1);
        header->next = header;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        Node* temp = header;
        while (temp->next != header) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = header;
    }

    void display() {
        Node* temp = header->next;
        while (temp != header) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "(Header)" << endl;
    }
};

int main() {
    cout << "--- Grounded Header Linked List ---" << endl;
    GroundedHeaderList gList;
    gList.insert(10);
    gList.insert(20);
    gList.insert(30);
    gList.display();

    cout << "\n--- Circular Header Linked List ---" << endl;
    CircularHeaderList cList;
    cList.insert(100);
    cList.insert(200);
    cList.insert(300);
    cList.display();

    return 0;
}

