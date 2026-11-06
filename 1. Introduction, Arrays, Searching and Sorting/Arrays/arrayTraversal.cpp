#include <iostream>
using namespace std;

void traverseArray(int arr[], int n) {
    cout << "Index\tValue\tAddress" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << arr[i] << "\t" << (void*)&arr[i] << endl;
    }
}

int main() {
    int arr[] = {12, 24, 36, 48, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Linear Array Traversal and Memory Representation:" << endl;
    traverseArray(arr, n);

    return 0;
}

