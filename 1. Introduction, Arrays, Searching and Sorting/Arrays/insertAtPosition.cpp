#include <iostream>
using namespace std;

int insertAtPosition(int arr[], int *n, int maxSize, int element, int pos) {
    if (*n >= maxSize) {
        cout << "Array is full" << endl;
        return -1;
    }
    if (pos < 0 || pos > *n) {
        cout << "Invalid position" << endl;
        return -1;
    }

    // Shift elements to the right
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = element;
    (*n)++;
    return 0;
}

int main() {
    int maxSize = 10;
    int arr[maxSize] = {10, 20, 30, 40, 50};
    int n = 5;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertAtPosition(arr, &n, maxSize, 25, 2);

    cout << "After insertion at index 2: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

