// Problem: Target Sum
// Link: https://leetcode.com/problems/target-sum/

#include <vector>
#include <unordered_map>

// Target Sum
// Problem: Find the number of ways to assign '+' or '-' to each array element such that their sum equals target

// Approach 1 - Brute Force:
// Backtracking: Recursively try both signs for each number, count valid expressions.
// Time Complexity: O(2^n)
// Space Complexity: O(n) for recursion stack

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(nums, 0, 0, target);
    }

    int backtrack(vector<int>& nums, int idx, int sum, int target) {
        if (idx == nums.size()) return sum == target ? 1 : 0;
        return backtrack(nums, idx + 1, sum + nums[idx], target) +
               backtrack(nums, idx + 1, sum - nums[idx], target);
    }
};

// Approach 2 - Optimized:
// DP after problem transformation: The problem reduces to finding subsets with sum (sum_all - target) / 2 (if possible).
// Use DP table to count subset sums. Handles edge case where total sum < abs(target) or (sum_all - target) is odd.
// Time Complexity: O(n * k), where k = (sum_all + target) / 2
// Space Complexity: O(n * k) for 2D DP, O(k) for 1D DP

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum_all = accumulate(nums.begin(), nums.end(), 0);
        if (target > sum_all || (sum_all + target) % 2 != 0 || target < -sum_all)
            return 0;
        int positive_sum = (sum_all + target) / 2;
        if (positive_sum < 0) return 0;
        vector<int> dp(positive_sum + 1, 0);
        dp[0] = 1;
        for (int num : nums)
            for (int s = positive_sum; s >= num; --s)
                dp[s] += dp[s - num];
        return dp[positive_sum];
    }
};
