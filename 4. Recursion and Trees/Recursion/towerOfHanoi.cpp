#include <iostream>
using namespace std;

// Tower of Hanoi recursive function
// n: number of disks, fromRod: source, toRod: destination, auxRod: auxiliary
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 0) return;

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);

    // Move nth disk from source to destination
    cout << "Move disk " << n << " from rod " << fromRod << " to rod " << toRod << endl;

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int n = 3;
    cout << "Tower of Hanoi solution for " << n << " disks:" << endl;
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}

