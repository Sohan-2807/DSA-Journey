#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Kadane's Algorithm to find the maximum sum of a contiguous subarray
// Time Complexity: O(n), Space Complexity: O(1)
int maxSubArraySum(const vector<int>& nums) {
    int maxSoFar = INT_MIN;
    int currMax = 0;

    for (int num : nums) {
        currMax += num;
        if (currMax > maxSoFar) {
            maxSoFar = currMax;
        }
        if (currMax < 0) {
            currMax = 0;
        }
    }
    return maxSoFar;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Input array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    int maxSum = maxSubArraySum(nums);
    cout << "Maximum contiguous subarray sum: " << maxSum << endl;

    return 0;
}
