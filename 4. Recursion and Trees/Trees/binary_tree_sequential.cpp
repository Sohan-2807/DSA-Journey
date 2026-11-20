#include <iostream>
#include <vector>
using namespace std;

// Sequential (Array-based) Representation of a Binary Tree
// Formulas (0-based indexing):
// Root node at index 0
// For any node at index i:
//   Left Child  = 2 * i + 1
//   Right Child = 2 * i + 2
//   Parent      = (i - 1) / 2
// Empty/Null node represented by -1

class SequentialBinaryTree {
    vector<int> tree;
    int capacity;

public:
    SequentialBinaryTree(int cap = 15) {
        capacity = cap;
        tree.assign(capacity, -1);
    }

    // Set root node
    void setRoot(int val) {
        tree[0] = val;
    }

    // Set left child of parent at parentIndex
    void setLeft(int val, int parentIndex) {
        int leftIndex = 2 * parentIndex + 1;
        if (parentIndex >= capacity || tree[parentIndex] == -1) {
            cout << "Parent does not exist at index " << parentIndex << endl;
            return;
        }
        if (leftIndex >= capacity) {
            cout << "Index out of bounds for left child" << endl;
            return;
        }
        tree[leftIndex] = val;
    }

    // Set right child of parent at parentIndex
    void setRight(int val, int parentIndex) {
        int rightIndex = 2 * parentIndex + 2;
        if (parentIndex >= capacity || tree[parentIndex] == -1) {
            cout << "Parent does not exist at index " << parentIndex << endl;
            return;
        }
        if (rightIndex >= capacity) {
            cout << "Index out of bounds for right child" << endl;
            return;
        }
        tree[rightIndex] = val;
    }

    // In-order Traversal: Left -> Root -> Right
    void inOrder(int index = 0) {
        if (index >= capacity || tree[index] == -1) return;
        inOrder(2 * index + 1);
        cout << tree[index] << " ";
        inOrder(2 * index + 2);
    }

    // Pre-order Traversal: Root -> Left -> Right
    void preOrder(int index = 0) {
        if (index >= capacity || tree[index] == -1) return;
        cout << tree[index] << " ";
        preOrder(2 * index + 1);
        preOrder(2 * index + 2);
    }

    // Post-order Traversal: Left -> Right -> Root
    void postOrder(int index = 0) {
        if (index >= capacity || tree[index] == -1) return;
        postOrder(2 * index + 1);
        postOrder(2 * index + 2);
        cout << tree[index] << " ";
    }

    // Print raw array representation
    void printArray() {
        cout << "Array Representation: [ ";
        for (int i = 0; i < capacity; i++) {
            if (tree[i] == -1) cout << "- ";
            else cout << tree[i] << " ";
        }
        cout << "]" << endl;
    }
};

int main() {
    SequentialBinaryTree sbt(15);

    /* Constructing the binary tree:
             1
           /   \
          2     3
         / \     \
        4   5     7
    */
    sbt.setRoot(1);
    sbt.setLeft(2, 0);   // index 1
    sbt.setRight(3, 0);  // index 2
    sbt.setLeft(4, 1);   // index 3
    sbt.setRight(5, 1);  // index 4
    sbt.setRight(7, 2);  // index 6

    cout << "Sequential (Array) Representation of Binary Tree:" << endl;
    sbt.printArray();

    cout << "\nPre-order Traversal:  ";
    sbt.preOrder();
    cout << endl;

    cout << "In-order Traversal:   ";
    sbt.inOrder();
    cout << endl;

    cout << "Post-order Traversal: ";
    sbt.postOrder();
    cout << endl;

    return 0;
}
