#include <iostream>
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
    int data;
    cout << "Enter data (-1 for NULL): ";
    cin >> data;

    if (data == -1) {
        return nullptr;
    }

    Node* root = createNode(data);

    cout << "Enter left child of " << data << ":" << endl;
    root->left = createTree();

    cout << "Enter right child of " << data << ":" << endl;
    root->right = createTree();

    return root;
}

void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    cout << "Create Binary Tree:" << endl;
    Node* root = createTree();

    cout << "\nPreorder Traversal (Recursive): ";
    preOrder(root);
    cout << endl;

    return 0;
}
