#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int front, rear;
    int arr[SIZE];

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Circular Queue is Full" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = val;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue is Empty" << endl;
            return -1;
        }
        int val = arr[front];
        if (front == rear) {
            // Queue has only one element, reset
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        return val;
    }

    void display() {
        if (isEmpty()) {
            cout << "Circular Queue is Empty" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);

    cout << "Circular Queue elements: ";
    cq.display();

    cout << "Dequeued: " << cq.dequeue() << endl;
    cout << "Dequeued: " << cq.dequeue() << endl;

    cout << "After dequeuing 2 elements: ";
    cq.display();

    cq.enqueue(50);
    cq.enqueue(60);

    cout << "After circular wrap-around enqueues: ";
    cq.display();

    return 0;
}

