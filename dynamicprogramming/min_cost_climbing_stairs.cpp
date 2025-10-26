// Problem: Min Cost Climbing Stairs
// Link: https://leetcode.com/problems/min-cost-climbing-stairs/

#include <vector>
#include <algorithm>
#include <optional>

// Min Cost Climbing Stairs
// Problem: Find the minimum cost to reach the top of a staircase by paying the cost of each step, with the option to climb one or two steps at a time.

// Approach 1 - Brute Force (Memoization):
// [Brief explanation: Recursive approach with memoization to avoid redundant calculations.]
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution1 {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        
        // Initialize memo vector
        std::vector<int> memo(n, -1);

        // Helper function for memoization
        std::function<int(int)> dfs = [&](int i) {
            if (i >= n) return 0; // Base case: beyond the top, no cost
            if (memo[i] != -1) return memo[i]; // Return memoized value if available

            return memo[i] = cost[i] + std::min(dfs(i + 1), dfs(i + 2));
        };

        // Consider starting from step 0 or step 1
        return std::min(dfs(0), dfs(1));
    }
};

// Approach 2 - Optimized (Dynamic Programming):
// [Brief explanation: Bottom-up DP to efficiently calculate minimum costs iteratively.]
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution2 {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        
        if (n == 1) return cost[0]; // Special case for single step

        // Initialize DP variables
        int dp1 = cost[0], dp2 = cost[1];

        // Iterate through remaining steps
        for (int i = 2; i < n; ++i) {
            int dp = std::min(dp1, dp2) + cost[i];
            dp1 = dp2; // Shift window
            dp2 = dp;
        }

        // Return minimum cost for the last two steps
        return std::min(dp1, dp2);
    }
};
