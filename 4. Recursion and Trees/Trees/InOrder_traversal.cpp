#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// 1. In-order traversal (Recursive): Left -> Root -> Right
void inOrderRecursive(Node* root) {
    if (root == nullptr) return;

    inOrderRecursive(root->left);
    cout << root->data << " ";
    inOrderRecursive(root->right);
}

// 2. In-order traversal (Iterative using Stack)
void inOrderStack(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != nullptr || !st.empty()) {
        // Reach leftmost node of current node
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        // Current must be null at this point
        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        // Visit right subtree
        curr = curr->right;
    }
}

int main() {
    // Construct sample binary tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "In-order Traversal (Recursive): ";
    inOrderRecursive(root);
    cout << endl;

    cout << "In-order Traversal (Stack/Iterative): ";
    inOrderStack(root);
    cout << endl;

    return 0;
}

