// Problem: Number Of Closed Islands
// Link: https://leetcode.com/problems/number-of-closed-islands/

#include <vector>
using namespace std;

// Number Of Closed Islands
// Problem: Count the number of closed islands (0s completely surrounded by 1s) in a 2D grid.

// Approach 1 - Brute Force:
// DFS each unvisited land (0), mark visited, check if island touches border
// Time Complexity: O(m*n), each cell visited at most once
// Space Complexity: O(m*n) due to recursive call stack in worst case

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && dfs(grid, i, j, m, n))
                    count++;
            }
        }
        return count;
    }

private:
    // Returns true if this island is closed (does not touch boundary)
    bool dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n) 
            return false;  // touch boundary means not closed
        if (grid[i][j] == 1 || grid[i][j] == 2) 
            return true;   // water or visited land considered closed here

        grid[i][j] = 2; // mark visited land

        bool up = dfs(grid, i - 1, j, m, n);
        bool down = dfs(grid, i + 1, j, m, n);
        bool left = dfs(grid, i, j - 1, m, n);
        bool right = dfs(grid, i, j + 1, m, n);

        return up && down && left && right;
    }
};

// Approach 2 - Optimized:
// First, flood fill all lands connected to the boundaries (not closed).
// Then, count islands on remaining lands.
// Time Complexity: O(m*n), each cell visited at most twice
// Space Complexity: O(m*n) due to recursion stack in worst case

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Flood fill lands connected to borders (convert to water)
        for (int i = 0; i < m; i++) {
            dfsFill(grid, i, 0, m, n);
            dfsFill(grid, i, n - 1, m, n);
        }
        for (int j = 0; j < n; j++) {
            dfsFill(grid, 0, j, m, n);
            dfsFill(grid, m - 1, j, m, n);
        }

        int closedCount = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    dfsFill(grid, i, j, m, n);
                    closedCount++;
                }
            }
        }
        return closedCount;
    }

private:
    // Flood fill land cells starting at (i, j) to water (1)
    void dfsFill(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 0)
            return;
        grid[i][j] = 1;
        dfsFill(grid, i - 1, j, m, n);
        dfsFill(grid, i + 1, j, m, n);
        dfsFill(grid, i, j - 1, m, n);
        dfsFill(grid, i, j + 1, m, n);
    }
};
