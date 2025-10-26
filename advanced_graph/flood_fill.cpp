// Problem: Flood Fill
// Link: https://leetcode.com/problems/flood-fill/description/

#include <vector>
#include <queue>
using namespace std;

// Flood Fill
// Problem: Flood-fill a 2D image from (sr, sc) with newColor, changing all connected same-color pixels.

// Approach 1 - Brute Force: Recursive DFS
// Start from (sr, sc), recursively fill in all 4-directionally connected same-color pixels.
// Time Complexity: O(mn), where m is rows, n is columns (each cell visited once)
// Space Complexity: O(mn) (recursion stack in worst case)

class Solution {
    vector<vector<int>> img;
    int oldColor;
    int newColor;
    int rows, cols;

    void dfs(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || img[r][c] != oldColor)
            return;  // Out of bounds or not the target color
        img[r][c] = newColor;
        dfs(r+1, c);
        dfs(r-1, c);
        dfs(r, c+1);
        dfs(r, c-1);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        img = image;
        oldColor = img[sr][sc];
        newColor = color;
        rows = img.size();
        cols = img[0].size();
        if (oldColor != newColor)
            dfs(sr, sc);
        return img;
    }
};

// Approach 2 - Optimized: BFS using queue (iterative, avoids stack overflow)
// Use a queue to process all connected same-color pixels level by level.
// Time Complexity: O(mn) (each cell visited once)
// Space Complexity: O(mn) (queue in worst case)

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int oldColor = image[sr][sc];
        if (oldColor == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == oldColor) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};
