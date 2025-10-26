// Problem: Set Matrix Zeroes
// Link: https://leetcode.com/problems/set-matrix-zeroes/

#include <vector>
using namespace std;

// Set Matrix Zeroes
// Problem: Given an m x n matrix, if an element is 0, set its entire row and column to 0 in place.

// Approach 1 - Brute Force:
// Use extra boolean arrays to record zero rows and columns.
// Then update the matrix accordingly.
// Time Complexity: O(m*n)
// Space Complexity: O(m + n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> zeroRow(m, false);
        vector<bool> zeroCol(n, false);

        // Mark rows and columns that contain zero
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zeroRow[i] = true;
                    zeroCol[j] = true;
                }
            }
        }

        // Set rows to zero
        for (int i = 0; i < m; i++) {
            if (zeroRow[i]) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set columns to zero
        for (int j = 0; j < n; j++) {
            if (zeroCol[j]) {
                for (int i = 0; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Approach 2 - Optimized:
// Use first row and first column as markers, plus two flags for first row and column zero status.
// Modify matrix in-place without extra arrays.
// Time Complexity: O(m*n)
// Space Complexity: O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        // Check if first row has zero
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Check if first column has zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Use first row and column as markers for zero rows and cols
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set matrix cells to zero using markers in first row and column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero first row if needed
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Zero first column if needed
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
