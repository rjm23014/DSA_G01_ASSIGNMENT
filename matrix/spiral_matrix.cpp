// Problem: Spiral Matrix
// Link: https://leetcode.com/problems/spiral-matrix/description/

#include <vector>
using namespace std;

// Spiral Matrix
// Problem: Return all elements of an m x n matrix in spiral order.

// Approach 1 - Brute Force:
// Simulate movement in four directions with boundary checks. Keep track of visited cells in a separate boolean matrix to avoid revisiting.
// Time Complexity: O(m*n)
// Space Complexity: O(m*n) for visited matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> result;
        int total = m * n;

        // Directions: right, down, left, up
        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int dirIdx = 0;  // start moving right
        int i = 0, j = 0;

        for (int step = 0; step < total; ++step) {
            result.push_back(matrix[i][j]);
            visited[i][j] = true;
            int ni = i + dirs[dirIdx][0], nj = j + dirs[dirIdx][1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || visited[ni][nj]) {
                dirIdx = (dirIdx + 1) % 4;  // change direction clockwise
                ni = i + dirs[dirIdx][0];
                nj = j + dirs[dirIdx][1];
            }
            i = ni; j = nj;
        }
        return result;
    }
};

// Approach 2 - Optimized:
// Use four pointers (top, bottom, left, right) to mark boundaries and shrink them as we move in spiral order. No extra space for visited matrix.
// Time Complexity: O(m*n)
// Space Complexity: O(1) excluding output vector

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;

        int top = 0, bottom = (int)matrix.size() - 1;
        int left = 0, right = (int)matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            for (int col = left; col <= right; ++col)
                result.push_back(matrix[top][col]);
            ++top;

            for (int row = top; row <= bottom; ++row)
                result.push_back(matrix[row][right]);
            --right;

            if (top <= bottom) {
                for (int col = right; col >= left; --col)
                    result.push_back(matrix[bottom][col]);
                --bottom;
            }

            if (left <= right) {
                for (int row = bottom; row >= top; --row)
                    result.push_back(matrix[row][left]);
                ++left;
            }
        }
        return result;
    }
};
