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

// Insert a node into BST
Node* insertBST(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else if (val > root->data) {
        root->right = insertBST(root->right, val);
    }
    return root;
}

// Search for a value in BST
bool searchBST(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;

    if (key < root->data) {
        return searchBST(root->left, key);
    }
    return searchBST(root->right, key);
}

// Find minimum value node in a subtree (used for deletion)
Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Delete a node from BST
Node* deleteBST(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data) {
        root->left = deleteBST(root->left, key);
    } else if (key > root->data) {
        root->right = deleteBST(root->right, key);
    } else {
        // Case 1: Leaf node (no child)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: One child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children (find inorder successor)
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

// In-order traversal of BST (produces sorted order)
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    Node* root = nullptr;

    // Insertion
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values) {
        root = insertBST(root, v);
    }

    cout << "BST In-order (sorted order): ";
    inOrder(root);
    cout << endl;

    // Searching
    cout << "Search 40 in BST: " << (searchBST(root, 40) ? "Found" : "Not Found") << endl;
    cout << "Search 90 in BST: " << (searchBST(root, 90) ? "Found" : "Not Found") << endl;

    // Deletion
    cout << "\nDeleting leaf node 20..." << endl;
    root = deleteBST(root, 20);
    inOrder(root);
    cout << endl;

    cout << "Deleting node with one child 30..." << endl;
    root = deleteBST(root, 30);
    inOrder(root);
    cout << endl;

    cout << "Deleting node with two children 50..." << endl;
    root = deleteBST(root, 50);
    inOrder(root);
    cout << endl;

    return 0;
}

