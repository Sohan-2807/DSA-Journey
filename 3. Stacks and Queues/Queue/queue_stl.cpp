#include <iostream>
#include <queue>
#include <deque>
#include <vector>
using namespace std;

int main() {
    // 1. std::queue (FIFO)
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.emplace(40);

    cout << "Queue front: " << q.front() << endl;
    cout << "Queue back: " << q.back() << endl;
    cout << "Queue size: " << q.size() << endl;

    cout << "Queue elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    // 2. std::deque (Double ended queue)
    deque<int> dq;

    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(10);

    cout << "\nDeque front: " << dq.front() << endl;
    cout << "Deque back: " << dq.back() << endl;
    cout << "Deque at index 1: " << dq[1] << endl;

    dq.pop_front();
    dq.pop_back();

    cout << "Deque elements: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    // 3. std::priority_queue (Max-Heap)
    priority_queue<int> maxPq;
    maxPq.push(30);
    maxPq.push(10);
    maxPq.push(50);

    cout << "\nMax-heap top: " << maxPq.top() << endl;
    cout << "Max-heap elements: ";
    while (!maxPq.empty()) {
        cout << maxPq.top() << " ";
        maxPq.pop();
    }
    cout << endl;

    // 4. std::priority_queue (Min-Heap)
    priority_queue<int, vector<int>, greater<int>> minPq;
    minPq.push(30);
    minPq.push(10);
    minPq.push(50);

    cout << "\nMin-heap top: " << minPq.top() << endl;
    cout << "Min-heap elements: ";
    while (!minPq.empty()) {
        cout << minPq.top() << " ";
        minPq.pop();
    }
    cout << endl;

    return 0;
}
