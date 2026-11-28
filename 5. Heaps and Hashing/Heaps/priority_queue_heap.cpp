#include <iostream>
#include <queue>
using namespace std;

// Simple Priority Queue implementation using Max Heap
class PriorityQueue {
    int arr[100];
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

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

public:
    PriorityQueue() { size = 0; }

    void push(int val) {
        if (size >= 100) {
            cout << "Queue full\n";
            return;
        }

        int i = size;
        arr[i] = val;
        size++;

        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    int pop() {
        if (size <= 0) return -1;
        int topVal = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return topVal;
    }

    int top() {
        if (size <= 0) return -1;
        return arr[0];
    }

    bool empty() { return size == 0; }
};

int main() {
    PriorityQueue pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    cout << "Custom Priority Queue (popped in priority order): ";
    while (!pq.empty()) {
        cout << pq.pop() << " ";
    }
    cout << endl;

    // STL priority_queue for comparison
    priority_queue<int> stlPq;
    stlPq.push(30);
    stlPq.push(10);
    stlPq.push(50);
    stlPq.push(20);

    cout << "STL priority_queue: ";
    while (!stlPq.empty()) {
        cout << stlPq.top() << " ";
        stlPq.pop();
    }
    cout << endl;

    return 0;
}
