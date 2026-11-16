#include <iostream>
using namespace std;

// Structure for a BST Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a value into the BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return createNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

// Function to search for a key in the BST
// Returns true if found, false otherwise
bool search(Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == nullptr) {
        return false;
    }
    if (root->data == key) {
        return true;
    }

    // Key is smaller than root's data -> search left subtree
    if (key < root->data) {
        return search(root->left, key);
    }
    // Key is greater than root's data -> search right subtree
    else {
        return search(root->right, key);
    }
}

// In-order traversal to display elements in sorted order
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    Node* root = nullptr;

    /*
            Constructing following BST:
                       50
                     /    \
                   30      70
                  /  \    /  \
                20   40  60   80
    */
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    for (int val : values) {
        root = insert(root, val);
    }

    cout << "BST Elements (In-order): ";
    inOrder(root);
    cout << endl << endl;

    // Search operations
    int key1 = 40;
    int key2 = 90;

    if (search(root, key1)) {
        cout << "Element " << key1 << " is FOUND in the BST." << endl;
    } else {
        cout << "Element " << key1 << " is NOT FOUND in the BST." << endl;
    }

    if (search(root, key2)) {
        cout << "Element " << key2 << " is FOUND in the BST." << endl;
    } else {
        cout << "Element " << key2 << " is NOT FOUND in the BST." << endl;
    }

    return 0;
}
