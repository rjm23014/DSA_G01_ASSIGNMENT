// Problem: Find Pivot Index
// Link: https://leetcode.com/problems/find-pivot-index/description/

#include <vector>
#include <numeric> // for accumulate
using namespace std;

// Find Pivot Index
// Problem: Find the index where the sum of elements to the left equals the sum of elements to the right.

// Approach 1 - Brute Force:
// Check each index by summing left and right parts separately.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            int leftSum = 0, rightSum = 0;
            for (int l = 0; l < i; ++l)
                leftSum += nums[l];
            for (int r = i + 1; r < n; ++r)
                rightSum += nums[r];
            if (leftSum == rightSum)
                return i;
        }
        return -1;
    }
};

// Approach 2 - Optimized:
// Use total sum and prefix sum while iterating. For each index,
// left sum = prefix sum, right sum = total sum - prefix sum - current element.
// Check if they are equal in O(n).
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int prefix = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (prefix == total - prefix - nums[i])
                return i;
            prefix += nums[i];
        }
        return -1;
    }
};
