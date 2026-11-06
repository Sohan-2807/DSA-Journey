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

void deleteBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is already empty" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "Initial List: ";
    printList(head);

    deleteBeginning(head);
    cout << "After deleting at beginning: ";
    printList(head);

    return 0;
}

