#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Floyd's Tortoise and Hare Cycle Detection Algorithm
bool detectCycle(Node* head) {
    if (!head || !head->next) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Loop detected
        }
    }
    return false;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // Create a loop: 40 -> 20
    head->next->next->next->next = head->next;

    if (detectCycle(head)) {
        cout << "Cycle detected in the linked list!" << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}
