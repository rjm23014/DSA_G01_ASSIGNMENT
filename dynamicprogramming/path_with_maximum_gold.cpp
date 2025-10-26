// Problem: Path With Maximum Gold
// Link: https://leetcode.com/problems/path-with-maximum-gold/

#include <vector>
#include <algorithm>
using namespace std;

// Path With Maximum Gold
// Problem: Given a grid, find the maximum gold collectable moving in 4 directions without revisiting cells.

// Approach 1 - Brute Force:
// Explore all paths starting from each cell with gold using DFS and backtracking.
// Time Complexity: O(3^(m*n)) - each cell branches up to 3 directions (except the origin) in worst case.
// Space Complexity: O(m*n) - recursion stack in worst case.

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        int maxGold = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    maxGold = max(maxGold, dfs(grid, i, j));
                }
            }
        }
        return maxGold;
    }

private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) 
            return 0;
        
        int gold = grid[i][j];
        grid[i][j] = 0; // mark visited
        
        int left = dfs(grid, i, j - 1);
        int right = dfs(grid, i, j + 1);
        int up = dfs(grid, i - 1, j);
        int down = dfs(grid, i + 1, j);
        
        grid[i][j] = gold; // backtrack
        
        return gold + max({left, right, up, down});
    }
};

// Approach 2 - Optimized:
// The problem inherently requires exploring all paths, but optimization here is the same backtracking with some pruning possible.
// Using the same DFS approach but with minor micro-optimizations is typical; 
// no fundamentally faster algorithm due to the problem constraints.
// Time Complexity: O(3^(m*n))
// Space Complexity: O(m*n)

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        int maxGold = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, dfs(grid, i, j, m, n));
                }
            }
        }
        return maxGold;
    }

private:
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;
        
        int original = grid[i][j];
        grid[i][j] = 0; // visited
        
        int res = 0;
        // Move in 4 directions using direction array for brevity
        static const int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for (auto& d : dirs) {
            int x = i + d[0], y = j + d[1];
            res = max(res, dfs(grid, x, y, m, n));
        }
        
        grid[i][j] = original; // backtrack
        
        return original + res;
    }
};
