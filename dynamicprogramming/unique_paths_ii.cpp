// Problem: Unique Paths Ii
// Link: https://leetcode.com/problems/unique-paths-ii/

#include <vector>
using namespace std;

// Unique Paths II
// Problem: Count unique paths from top-left to bottom-right in grid with obstacles (1 = obstacle).

// Approach 1 - Brute Force:
// DFS recursion to explore all paths avoiding obstacles, with memoization to avoid recomputation.
// Time Complexity: O(m*n) due to memoization pruning repeated states
// Space Complexity: O(m*n) for recursion stack and memo table

class Solution {
public:
    int m, n;
    vector<vector<int>> grid, memo;

    int dfs(int r, int c) {
        if (r >= m || c >= n || grid[r][c] == 1) return 0;       // Out of bounds or obstacle
        if (r == m - 1 && c == n - 1) return 1;                  // Reached destination
        if (memo[r][c] != -1) return memo[r][c];                 // Return cached result

        int down = dfs(r + 1, c);
        int right = dfs(r, c + 1);
        return memo[r][c] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid = obstacleGrid;
        m = (int)grid.size();
        n = (int)grid[0].size();
        memo.assign(m, vector<int>(n, -1));
        return dfs(0, 0);
    }
};

// Approach 2 - Optimized:
// Dynamic Programming bottom-up tabulation to build number of ways to each cell.
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = (int)obstacleGrid.size();
        int n = (int)obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (obstacleGrid[0][0] == 1) return 0;
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0; // no paths through obstacle
                    continue;
                }
                if (i == 0 && j == 0) continue;  // start cell already set

                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] += up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
};
