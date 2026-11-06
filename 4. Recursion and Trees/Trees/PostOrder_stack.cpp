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

void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);

        if (curr->left != nullptr) {
            st1.push(curr->left);
        }
        if (curr->right != nullptr) {
            st1.push(curr->right);
        }
    }

    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

int main() {
    Node* root = createTree();

    cout << "Postorder Traversal (Using Stack): ";
    postOrder(root);
    cout << endl;

    return 0;
}
