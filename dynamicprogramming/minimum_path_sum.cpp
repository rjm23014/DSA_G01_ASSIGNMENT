// Problem: Minimum Path Sum
// Link: https://leetcode.com/problems/minimum-path-sum/

#include <vector>
#include <algorithm>
using namespace std;

// Minimum Path Sum
// Problem: Given a m x n grid of non-negative numbers, find a path from top-left to bottom-right
// minimizing the sum of all numbers along the path. Movement only right or down.

// Approach 1 - Brute Force:
// Explore every possible path recursively and return the minimum sum.
// Time Complexity: O(2^(m+n)) exponential due to branching
// Space Complexity: O(m+n) recursion stack depth

class Solution {
    int dfs(int i, int j, const vector<vector<int>>& grid) {
        if (i < 0 || j < 0) return INT_MAX; // invalid path
        if (i == 0 && j == 0) return grid[0][0]; // start cell
        return grid[i][j] + min(dfs(i-1, j, grid), dfs(i, j-1, grid));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        return dfs(m-1, n-1, grid);
    }
};

// Approach 2 - Optimized:
// Use dynamic programming to store minimum sums for each cell.
// Build DP table row by row and column by column, each cell = grid value + min(top, left).
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) dp[i][0] = dp[i-1][0] + grid[i][0];
        for (int j = 1; j < n; ++j) dp[0][j] = dp[0][j-1] + grid[0][j];
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};
