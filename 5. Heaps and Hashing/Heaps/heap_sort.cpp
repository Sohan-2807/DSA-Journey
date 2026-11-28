#include <iostream>
using namespace std;

// Down-heapify to maintain max-heap property for subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// In-place Heap Sort algorithm: O(N log N)
void heapSort(int arr[], int n) {
    // Step 1: Build max heap (from last non-leaf node down to 0)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (largest) to end
        swap(arr[0], arr[i]);

        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    display(arr, n);

    heapSort(arr, n);

    cout << "Sorted array: ";
    display(arr, n);

    return 0;
}
