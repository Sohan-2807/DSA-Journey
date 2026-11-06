#include <iostream>
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

// Morris In-Order Traversal (O(1) auxiliary space)
void morrisInOrder(Node* root) {
    Node* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            cout << curr->data << " ";
            curr = curr->right;
        } else {
            // Find the in-order predecessor of curr
            Node* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            // Create temporary thread to curr
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            }
            // Remove thread and visit curr
            else {
                prev->right = nullptr;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main() {
    // Constructed Binary Tree:
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

    cout << "Morris In-Order Traversal: ";
    morrisInOrder(root);
    cout << endl;

    return 0;
}
