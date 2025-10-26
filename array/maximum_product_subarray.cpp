// Problem: Maximum Product Subarray
// Link: https://leetcode.com/problems/maximum-product-subarray/description/

#include <vector>
#include <algorithm>
using namespace std;

// Maximum Product Subarray
// Problem: Find the contiguous subarray within an array that has the largest product

// Approach 1 - Brute Force:
// Compute the product of every possible subarray and track the maximum product found.
// Time Complexity: O(N^2)
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = (int)nums.size();
        int maxProd = nums[0];
        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                maxProd = max(maxProd, prod);
            }
        }
        return maxProd;
    }
};

// Approach 2 - Optimized:
// Track maximum and minimum product ending at current index to handle negatives efficiently.
// Update global max product on each iteration.
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnding = nums[0], minEnding = nums[0], maxProd = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] < 0) 
                swap(maxEnding, minEnding);
            maxEnding = max(nums[i], maxEnding * nums[i]);
            minEnding = min(nums[i], minEnding * nums[i]);
            maxProd = max(maxProd, maxEnding);
        }
        return maxProd;
    }
};
