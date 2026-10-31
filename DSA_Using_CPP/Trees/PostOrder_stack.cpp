#include <iostream>
#include <stack>
using namespace std;

// Definition of a Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

/**
 * Postorder Traversal (Iterative using 2 Stacks):
 * Order: Left Subtree -> Right Subtree -> Root
 *
 * Algorithm:
 * 1. Push root to st1.
 * 2. While st1 is not empty:
 *    a. Pop top node from st1 and push it onto st2.
 *    b. Push left child of popped node to st1 (if exists).
 *    c. Push right child of popped node to st1 (if exists).
 * 3. Pop and print all nodes from st2.
 *
 * Why this works:
 * - In st1, we visit nodes in order: Root -> Right -> Left.
 * - Pushing them into st2 reverses this order to: Left -> Right -> Root!
 *
 * Time Complexity:  O(N)
 * Space Complexity: O(N)
 */
void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);

        // Push left child to st1 first
        if (curr->left != nullptr) {
            st1.push(curr->left);
        }

        // Push right child to st1 second
        if (curr->right != nullptr) {
            st1.push(curr->right);
        }
    }

    // Nodes in st2 are in Left -> Right -> Root order
    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

int main() {
   

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Postorder Traversal (Using Stack): ";
    postOrder(root);
    cout << endl;

    return 0;
}

