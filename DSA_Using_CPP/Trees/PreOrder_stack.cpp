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
 * Preorder Traversal (Iterative using Stack):
 * Order: Root -> Left Subtree -> Right Subtree
 *
 * Algorithm:
 * 1. Push the root node to the stack.
 * 2. While the stack is not empty:
 *    a. Pop the top node and print its data (Root).
 *    b. Push its RIGHT child to the stack (if exists).
 *    c. Push its LEFT child to the stack (if exists).
 *       (Note: Right child is pushed first so that Left child 
 *        is on top and popped/processed first due to LIFO nature).
 *
 * Time Complexity:  O(N) - visits every node once
 * Space Complexity: O(H) - where H is tree height (O(N) in worst case)
 */
void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();

        // 1. Visit Root
        cout << curr->data << " ";

        // 2. Push right child first
        if (curr->right != nullptr) {
            st.push(curr->right);
        }

        // 3. Push left child so it gets processed next
        if (curr->left != nullptr) {
            st.push(curr->left);
        }
    }
}

int main() {
   

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Preorder Traversal (Using Stack): ";
    preOrder(root);
    cout << endl;

    return 0;
}

