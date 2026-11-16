#include<iostream>
using namespace std;

struct Node{
int data;
Node* left;
Node* right;
};

Node* createNode(int data)
{
Node* newNode=new Node();
newNode->data=data;
newNode->left=newNode->right=nullptr;
return newNode;
}

Node* searchNode(Node* root, int key)
{
if (root==Null || root->data==key){
return root;
}
if(root->data<key){
return searchNode(root->right,key);
}

if(root->data>key){
return searchNode(root->left,key);
}
}


int main()
{

    Node* root = nullptr;
    // create a BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

Node* found = searchNode(root, 25);

    // check if the key is found or not
    if (found != nullptr) {
        cout << "Node 25 found in the BST." << endl;
    }
    else {
        cout << "Node 25 not found in the BST." << endl;
    }

    return 0;
}