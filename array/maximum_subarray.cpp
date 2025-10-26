// Problem: Maximum Subarray
// Link: https://leetcode.com/problems/maximum-subarray/description/

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Maximum Subarray
// Problem: Given an integer array, find the contiguous subarray with the largest sum and return its sum.

// Approach 1 - Brute Force:
// Check sum of every possible subarray and track the maximum sum found.
// Time Complexity: O(n^3)
// Space Complexity: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int current_sum = 0;
                for (int k = i; k <= j; k++) {
                    current_sum += nums[k];
                }
                max_sum = max(max_sum, current_sum);
            }
        }
        return max_sum;
    }
};

// Approach 2 - Optimized:
// Use Kadane's algorithm to keep track of current subarray sum and update max sum accordingly.
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentMax = nums[0];
        int globalMax = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            currentMax = max(nums[i], currentMax + nums[i]);
            globalMax = max(globalMax, currentMax);
        }
        return globalMax;
    }
};
