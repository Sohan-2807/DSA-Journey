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


void preOrder(Node* root) {
    // Base Case: empty node / reached beyond a leaf
    if (root == nullptr) {
        return;
    }

    // 1. Visit Root
    cout << root->data << " ";

    // 2. Traverse Left Subtree
    preOrder(root->left);

    // 3. Traverse Right Subtree
    preOrder(root->right);
}

int main() {
   

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Preorder Traversal (Recursive): ";
    preOrder(root);
    cout << endl;

    return 0;
}
