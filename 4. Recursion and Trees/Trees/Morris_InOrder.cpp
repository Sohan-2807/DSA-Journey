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
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    return root;
}

// Morris In-Order Traversal (O(1) auxiliary space)
void morrisInOrder(Node* root) {
    Node* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            cout << curr->data << " ";
            curr = curr->right;
        } else {
            Node* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = nullptr;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main() {
    Node* root = createTree();

    cout << "Morris In-Order Traversal: ";
    morrisInOrder(root);
    cout << endl;

    return 0;
}
