#include <iostream>
using namespace std;

// Max Heap implementation using an array
class MaxHeap {
    int arr[100];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    // Insert an element into the heap: O(log N)
    void insert(int val) {
        if (size >= 100) {
            cout << "Heap overflow" << endl;
            return;
        }

        // Insert at the end and bubble up (shift-up)
        int i = size;
        arr[i] = val;
        size++;

        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Restore max-heap property rooted at index i: O(log N)
    void heapify(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    // Remove and return maximum element (root): O(log N)
    int extractMax() {
        if (size <= 0) {
            cout << "Heap underflow" << endl;
            return -1;
        }
        if (size == 1) {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);

        return root;
    }

    // Return the maximum element without deleting: O(1)
    int getMax() {
        if (size <= 0) {
            cout << "Heap is empty" << endl;
            return -1;
        }
        return arr[0];
    }

    void display() {
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    h.insert(40);
    h.insert(20);
    h.insert(30);
    h.insert(35);
    h.insert(25);
    h.insert(80);
    h.insert(15);

    cout << "Max Heap elements: ";
    h.display();

    cout << "Maximum element: " << h.getMax() << endl;

    cout << "Extracted max: " << h.extractMax() << endl;
    cout << "Heap after extraction: ";
    h.display();

    cout << "Extracted max: " << h.extractMax() << endl;
    cout << "Heap after extraction: ";
    h.display();

    return 0;
}
