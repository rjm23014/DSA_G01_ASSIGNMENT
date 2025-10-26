// Problem: Unique Paths
// Link: https://leetcode.com/problems/unique-paths/

#include <vector>
using namespace std;

// Unique Paths
// Problem: Count the number of unique paths from the top-left to the bottom-right in an m x n grid,
// where only moves to the right or down are allowed.

// Approach 1 - Brute Force:
// Use backtracking to explore every path recursively.
// Time Complexity: O(2^(m+n))
// Space Complexity: O(m+n) for recursion stack

class Solution {
public:
    int uniquePaths(int m, int n) {
        return dfs(0, 0, m, n);
    }
private:
    int dfs(int r, int c, int m, int n) {
        if (r == m - 1 && c == n - 1) return 1; // reached bottom-right
        if (r >= m || c >= n) return 0;         // out of bounds
        // move down + move right
        return dfs(r + 1, c, m, n) + dfs(r, c + 1, m, n);
    }
};

// Approach 2 - Optimized:
// Use dynamic programming to store number of ways to reach each cell.
// dp[i][j] = dp[i-1][j] + dp[i][j-1]
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1)); // first row & col initialized to 1
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
