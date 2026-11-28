#include <iostream>
using namespace std;

// Bottom-up Heap Construction in O(N) time
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Build heap by heapifying from the lowest non-leaf nodes upward
void buildHeap(int arr[], int n) {
    // Last non-leaf node is at index (n/2 - 1)
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before buildHeap: ";
    display(arr, n);

    buildHeap(arr, n);

    cout << "Array after buildHeap (Max-Heap): ";
    display(arr, n);

    return 0;
}
