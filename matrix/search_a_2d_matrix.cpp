// Problem: Search A 2D Matrix
// Link: https://leetcode.com/problems/search-a-2d-matrix/description/

#include <vector>
using namespace std;

// Search a 2D Matrix
// Problem: Given a 2D matrix with sorted rows and columns, determine if target exists in the matrix.

// Approach 1 - Brute Force:
// Check each element in the entire matrix linearly.
// Time Complexity: O(m*n)
// Space Complexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == target)
                    return true;
        return false;
    }
};

// Approach 2 - Optimized:
// Treat the matrix as a flattened sorted array and perform binary search.
// Convert 1D mid index to 2D indices to access matrix elements.
// Time Complexity: O(log(m*n))
// Space Complexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
