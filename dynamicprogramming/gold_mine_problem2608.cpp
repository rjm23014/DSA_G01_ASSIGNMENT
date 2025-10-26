// Problem: Gold Mine Problem2608
// Link: https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1

#include <vector>
#include <algorithm> // for max()
using namespace std;

// Gold Mine Problem
// Problem: Find max gold collected starting at any row in col 0, moving right, up-right, or down-right.

// Approach 1 - Brute Force (Backtracking/DFS)
// Recursively explore all valid paths from each cell in first column, tracking max gold.
// Time Complexity: O(3^(n*m))  (exponential, due to 3-way recursion)
// Space Complexity: O(n*m)     (call stack depth)

class Solution {
public:
    int collectGold(vector<vector<int>>& mat) {
        int maxGold = 0;
        int n = mat.size(), m = mat[0].size();

        // Try every starting cell in first column
        for (int i = 0; i < n; ++i) {
            maxGold = max(maxGold, dfs(mat, i, 0, n, m));
        }
        return maxGold;
    }

private:
    int dfs(vector<vector<int>>& mat, int x, int y, int n, int m) {
        // Base case: out of bounds
        if (x < 0 || x >= n || y >= m) return 0;

        // Max from right, up-right, down-right moves
        int right = dfs(mat, x, y + 1, n, m);
        int upRight = dfs(mat, x - 1, y + 1, n, m);
        int downRight = dfs(mat, x + 1, y + 1, n, m);

        return mat[x][y] + max({right, upRight, downRight});
    }
};

// Approach 2 - Optimized (Dynamic Programming)
// Fill DP table from right to left, each cell storing max gold collectable from there to end.
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)     (can be optimized to O(n))

class Solution {
public:
    int collectGold(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Start from rightmost column, move left
        for (int col = m - 1; col >= 0; --col) {
            for (int row = 0; row < n; ++row) {
                // Base value is the cell's gold
                int maxGold = mat[row][col];
                int nextMax = 0;

                // Only if not last column
                if (col + 1 < m) {
                    nextMax = dp[row][col + 1]; // right
                    if (row - 1 >= 0) nextMax = max(nextMax, dp[row - 1][col + 1]); // up-right
                    if (row + 1 < n) nextMax = max(nextMax, dp[row + 1][col + 1]);  // down-right
                }

                dp[row][col] = maxGold + nextMax;
            }
        }

        // Max is from first column
        int maxCollected = 0;
        for (int row = 0; row < n; ++row)
            maxCollected = max(maxCollected, dp[row][0]);

        return maxCollected;
    }
};
