#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* createTree() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    return root;
}

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
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}

int main() {
    Node* root = createTree();

    cout << "In-order Traversal (Recursive): ";
    inOrderRecursive(root);
    cout << endl;

    cout << "In-order Traversal (Stack/Iterative): ";
    inOrderStack(root);
    cout << endl;

    return 0;
}
