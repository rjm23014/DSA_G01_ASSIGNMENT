// Problem: Running Sum Of 1D Array
// Link: https://leetcode.com/problems/running-sum-of-1d-array/description/

#include <vector>
using namespace std;

// Running Sum Of 1D Array
// Problem: Given an integer array nums, return the running sum of nums.

// Approach 1 - Brute Force:
// Create a new result array; for each index compute sum of all elements before and including it.
// Time Complexity: O(n^2) due to repeated summations
// Space Complexity: O(n) for the result array
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j <= i; j++) {
                sum += nums[j];
            }
            res[i] = sum;
        }
        return res;
    }
};

// Approach 2 - Optimized:
// Use prefix sums by accumulating running total as we iterate once through nums.
// Time Complexity: O(n) single pass
// Space Complexity: O(n) for the result or O(1) if done in-place
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < (int)nums.size(); i++) {
            nums[i] += nums[i - 1];  // update nums[i] to running sum up to i
        }
        return nums;
    }
};
