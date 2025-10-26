// Problem: Super Egg Drop
// Link: https://leetcode.com/problems/super-egg-drop/

#include <vector>
#include <climits>
using namespace std;

// Super Egg Drop
// Problem: Find the minimum number of moves to determine the highest floor from which eggs won't break, given K eggs and N floors.

// Approach 1 - Brute Force:
// Use top-down DP with binary search; 
// for each floor, simulate egg break and no break, and choose minimum max drops.
// Time Complexity: O(K * N^2) as we try each floor for each state.
// Space Complexity: O(K * N) for memoization.

class Solution {
    vector<vector<int>> memo;
    int dp(int k, int n) {
        if (n <= 1 || k == 1) return n;
        if (memo[k][n] != -1) return memo[k][n];

        int res = INT_MAX;
        // Try dropping egg from each floor x in [1..n]
        for (int x = 1; x <= n; ++x) {
            int breakCase = dp(k - 1, x - 1);
            int noBreakCase = dp(k, n - x);
            int worst = 1 + max(breakCase, noBreakCase);
            res = min(res, worst);
        }
        return memo[k][n] = res;
    }
public:
    int superEggDrop(int k, int n) {
        memo.assign(k + 1, vector<int>(n + 1, -1));
        return dp(k, n);
    }
};


// Approach 2 - Optimized:
// Use DP with knowledge of moves vs floors covered (math-based DP).
// dp[m][k] = max floors we can check with m moves and k eggs:
// dp[m][k] = dp[m-1][k-1] + dp[m-1][k] + 1;
// Increment moves m until dp[m][k] >= n.
// Time Complexity: O(K * log N)
// Space Complexity: O(K * log N)

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<int> dp(k + 1, 0);
        int moves = 0;
        while (dp[k] < n) {
            ++moves;
            for (int i = k; i > 0; --i) {
                dp[i] = dp[i] + dp[i - 1] + 1;
            }
        }
        return moves;
    }
};
