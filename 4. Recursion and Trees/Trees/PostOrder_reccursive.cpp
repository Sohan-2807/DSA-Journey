#include <iostream>
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
 * Postorder Traversal (Purely Recursive):
 * Order: Left Subtree -> Right Subtree -> Root
 *
 * Time Complexity:  O(N) - visits every node once
 * Space Complexity: O(H) - recursion call stack where H is tree height
 */
void postOrder(Node* root) {
    // Base Case: empty node
    if (root == nullptr) {
        return;
    }

    // 1. Traverse Left Subtree
    postOrder(root->left);

    // 2. Traverse Right Subtree
    postOrder(root->right);

    // 3. Visit Root
    cout << root->data << " ";
}

int main() {
   
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Postorder Traversal (Recursive): ";
    postOrder(root);
    cout << endl;

    return 0;
}

