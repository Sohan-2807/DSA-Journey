#include <iostream>
#include <queue>    // For std::queue and std::priority_queue
#include <deque>    // For std::deque
#include <vector>
using namespace std;

// C++ STL Queue, Deque & Priority Queue Built-in Methods Guide
// Headers: #include <queue>, #include <deque>

void testQueueSTL() {
    cout << "\n=========================================" << endl;
    cout << "       1. C++ STL std::queue Methods     " << endl;
    cout << "=========================================" << endl;

    // std::queue follows FIFO (First-In, First-Out)
    queue<int> q;

    // empty()
    cout << "empty(): " << (q.empty() ? "true (Empty)" : "false") << endl;

    // push() and emplace()
    q.push(10);
    q.push(20);
    q.push(30);
    q.emplace(40);
    cout << "Pushed elements: 10, 20, 30, 40" << endl;

    // size()
    cout << "size(): " << q.size() << endl;

    // front() & back()
    cout << "front() [first element to be removed]: " << q.front() << endl;
    cout << "back()  [last element inserted]:        " << q.back() << endl;

    // pop()
    cout << "\nCalling pop() to remove front element (" << q.front() << ")..." << endl;
    q.pop();
    cout << "New front() after pop: " << q.front() << endl;
    cout << "New size() after pop:  " << q.size() << endl;

    // Traversal (by value copy)
    cout << "Traversing remaining queue elements: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // swap()
    queue<int> q2;
    q2.push(999);
    q.swap(q2);
    cout << "After swap with q2 - q.front(): " << q.front() << ", q2.front(): " << q2.front() << endl;
}

void testDequeSTL() {
    cout << "\n=========================================" << endl;
    cout << "       2. C++ STL std::deque Methods     " << endl;
    cout << "=========================================" << endl;

    // std::deque (Double-Ended Queue) allows O(1) insertion/deletion at BOTH ends
    deque<int> dq;

    // push_back() and push_front()
    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(10);
    dq.push_front(5);
    // Deque is now: 5, 10, 20, 30
    cout << "After push_front(5, 10) & push_back(20, 30): ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    // front() and back()
    cout << "front(): " << dq.front() << ", back(): " << dq.back() << endl;

    // Random access using operator[] and at()
    cout << "Element at index 1 using dq[1]:    " << dq[1] << endl;
    cout << "Element at index 2 using dq.at(2): " << dq.at(2) << endl;

    // pop_front() and pop_back()
    dq.pop_front(); // removes 5
    dq.pop_back();  // removes 30
    cout << "After pop_front() and pop_back(): ";
    for (int x : dq) cout << x << " ";
    cout << endl;
    cout << "Current size: " << dq.size() << endl;
}

void testPriorityQueueSTL() {
    cout << "\n=========================================" << endl;
    cout << "   3. C++ STL std::priority_queue Methods " << endl;
    cout << "=========================================" << endl;

    // A. Default: Max-Heap (Highest value always at top)
    cout << "--- A. Max-Heap (Default Priority Queue) ---" << endl;
    priority_queue<int> maxPQ;

    maxPQ.push(30);
    maxPQ.push(10);
    maxPQ.push(50);
    maxPQ.push(20);

    cout << "Inserted: 30, 10, 50, 20" << endl;
    cout << "top() element: " << maxPQ.top() << " (Largest element)" << endl;
    cout << "size(): " << maxPQ.size() << endl;

    cout << "Popping elements in priority order: ";
    while (!maxPQ.empty()) {
        cout << maxPQ.top() << " ";
        maxPQ.pop();
    }
    cout << endl; // Output: 50 30 20 10

    // B. Min-Heap: Smallest value always at top
    // Syntax: priority_queue<Type, Container, Comparator>
    cout << "\n--- B. Min-Heap (Using std::greater<int>) ---" << endl;
    priority_queue<int, vector<int>, greater<int>> minPQ;

    minPQ.push(30);
    minPQ.push(10);
    minPQ.push(50);
    minPQ.push(20);

    cout << "Inserted: 30, 10, 50, 20" << endl;
    cout << "top() element: " << minPQ.top() << " (Smallest element)" << endl;

    cout << "Popping elements in ascending order: ";
    while (!minPQ.empty()) {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }
    cout << endl; // Output: 10 20 30 50
}

int main() {
    testQueueSTL();
    testDequeSTL();
    testPriorityQueueSTL();
    return 0;
}
