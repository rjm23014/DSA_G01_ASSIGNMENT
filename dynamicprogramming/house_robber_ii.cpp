// Problem: House Robber Ii
// Link: https://leetcode.com/problems/house-robber-ii/

#include <vector>
#include <algorithm>
using namespace std;

// House Robber II
// Problem: Max amount that can be robbed from circular houses without robbing adjacent houses

// Approach 1 - Brute Force:
// Try all subsets ensuring no two adjacent houses (circular adjacency handled by checking all subsets).
// Time Complexity: O(2^n) - exponential brute force
// Space Complexity: O(n) recursion stack

class Solution {
public:
    int robFromTo(const vector<int>& nums, int start, int end) {
        if (start > end) return 0;
        if (start == end) return nums[start];
        // DP array for linear house robber (subproblem)
        vector<int> dp(end - start + 1, 0);
        dp[0] = nums[start];
        if (end - start + 1 > 1)
            dp[1] = max(nums[start], nums[start + 1]);
        for (int i = 2; i <= end - start; ++i) {
            dp[i] = max(dp[i - 1], nums[start + i] + dp[i - 2]);
        }
        return dp.back();
    }

    int rob(const vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Try all valid subsets excluding first, excluding last, and take max
        return max(robFromTo(nums, 0, n - 2), robFromTo(nums, 1, n - 1));
    }
};

// Approach 2 - Optimized:
// Use DP with O(1) space for the linear subproblems and combine two scenarios:
// 1) Rob from house 0 to n-2
// 2) Rob from house 1 to n-1
// Return max of the two avoiding circular adjacency.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int robLinear(const vector<int>& nums, int start, int end) {
        int prevMax = 0, currMax = 0;
        for (int i = start; i <= end; ++i) {
            int temp = currMax;
            currMax = max(currMax, prevMax + nums[i]);
            prevMax = temp;
        }
        return currMax;
    }
    
    int rob(const vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        // Either exclude last house or exclude first house
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }
};
