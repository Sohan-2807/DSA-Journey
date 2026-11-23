#include <iostream>
#include <vector>
using namespace std;

// Find pair with target sum in a sorted array using Two Pointers
// Time Complexity: O(n), Space Complexity: O(1)
bool hasPairWithSum(const vector<int>& arr, int target, int& val1, int& val2) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            val1 = arr[left];
            val2 = arr[right];
            return true;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}

int main() {
    vector<int> arr = {1, 2, 4, 7, 11, 15};
    int target = 15;

    int v1 = 0, v2 = 0;
    if (hasPairWithSum(arr, target, v1, v2)) {
        cout << "Found pair with sum " << target << ": " << v1 << " + " << v2 << endl;
    } else {
        cout << "No pair found with sum " << target << endl;
    }

    return 0;
}
