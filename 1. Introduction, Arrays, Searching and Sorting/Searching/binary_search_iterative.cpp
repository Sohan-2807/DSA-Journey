#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> sortedArr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;

    int idx = binarySearch(sortedArr, target);
    if (idx != -1) {
        cout << "Target " << target << " found at index " << idx << endl;
    } else {
        cout << "Target " << target << " not found in array" << endl;
    }

    return 0;
}
