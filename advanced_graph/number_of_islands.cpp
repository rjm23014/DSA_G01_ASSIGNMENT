// Problem: Number Of Islands
// Link: https://leetcode.com/problems/number-of-islands/description/

#include <vector>
#include <queue>
using namespace std;

// Number Of Islands
// Problem: Given a 2D grid of '1's (land) and '0's (water), count the number of islands formed by connected lands (horizontally or vertically).

// Approach 1 - Brute Force:
// Use DFS to explore and mark visited land cells by changing them to '0'.
// For each '1' found, increment island count and DFS to sink the entire island.
// Time Complexity: O(m*n) (where m = rows, n = columns)
// Space Complexity: O(m*n) worst case for recursion stack if grid is all land.

class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;

        grid[i][j] = '0'; // mark visited by sinking
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};

// Approach 2 - Optimized:
// Use BFS instead of DFS to iteratively traverse islands.
// This avoids potential stack overflow issues with deep recursion but same time complexity.
// Time Complexity: O(m*n)
// Space Complexity: O(min(m,n)) for BFS queue in worst case (one layer of queue).

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        int count = 0;
        const vector<pair<int,int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    grid[i][j] = '0';
                    queue<pair<int,int>> q;
                    q.emplace(i, j);
                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        for (auto& d : directions) {
                            int nx = x + d.first;
                            int ny = y + d.second;
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                                grid[nx][ny] = '0';
                                q.emplace(nx, ny);
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
