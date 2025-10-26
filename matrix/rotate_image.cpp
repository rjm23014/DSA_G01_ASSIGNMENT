// Problem: Rotate Image
// Link: https://leetcode.com/problems/rotate-image/

#include <vector>
using namespace std;

// Rotate Image
// Problem: Rotate an n x n 2D matrix 90 degrees clockwise in-place

// Approach 1 - Brute Force:
// Use an extra matrix to store rotated values, then copy back.
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> rotated(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                rotated[j][n - 1 - i] = matrix[i][j];
        matrix = rotated;
    }
};

// Approach 2 - Optimized:
// Rotate matrix in-place by first reversing rows, then taking transpose.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Reverse rows (flip upside down)
        for (int i = 0; i < n / 2; ++i)
            swap(matrix[i], matrix[n - i - 1]);
        // Transpose along main diagonal
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};
