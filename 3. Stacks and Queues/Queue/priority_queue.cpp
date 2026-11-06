#include <iostream>
using namespace std;

// Element with data and priority
struct Element {
    int value;
    int priority;
};

#define MAX 50

class PriorityQueue {
    Element arr[MAX];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    // Insert element with priority
    void enqueue(int value, int priority) {
        if (size >= MAX) {
            cout << "Priority Queue Overflow" << endl;
            return;
        }
        arr[size].value = value;
        arr[size].priority = priority;
        size++;
    }

    // Remove element with highest priority (largest priority number)
    int dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue Underflow" << endl;
            return -1;
        }

        // Find index of highest priority
        int highestIdx = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i].priority > arr[highestIdx].priority) {
                highestIdx = i;
            }
        }

        int highestVal = arr[highestIdx].value;

        // Shift remaining elements
        for (int i = highestIdx; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;

        return highestVal;
    }

    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is Empty" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << "[Val: " << arr[i].value << ", Priority: " << arr[i].priority << "] ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(10, 2);
    pq.enqueue(50, 5);
    pq.enqueue(20, 1);
    pq.enqueue(40, 4);

    cout << "Priority Queue items: ";
    pq.display();

    cout << "Dequeued highest priority element: " << pq.dequeue() << endl;
    cout << "Dequeued next highest priority element: " << pq.dequeue() << endl;

    cout << "Remaining queue: ";
    pq.display();

    return 0;
}

