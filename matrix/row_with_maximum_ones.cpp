// Problem: Row With Maximum Ones
// Link: https://leetcode.com/problems/row-with-maximum-ones/description/

#include <vector>
#include <algorithm> // for std::count
using namespace std;

// Row With Maximum Ones
// Problem: Given an m x n binary matrix mat, find the row index with the maximum count of ones and the count.

// Approach 1 - Brute Force:
// Count ones in each row using simple iteration or std::count and track the maximum.
// Time Complexity: O(m*n), where m = number of rows, n = number of columns
// Space Complexity: O(1)

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxRow = 0, maxCount = 0;
        for (int i = 0; i < (int)mat.size(); ++i) {
            int countOnes = count(mat[i].begin(), mat[i].end(), 1);
            if (countOnes > maxCount) {
                maxCount = countOnes;
                maxRow = i;
            }
        }
        return {maxRow, maxCount};
    }
};

// Approach 2 - Optimized:
// Use the fact that each row is binary and count ones by iterating until the first zero from end (if sorted).
// If not sorted, same as brute force because no further optimization is possible.
// Time Complexity: O(m*n) worst case, but could be better if rows are sorted.
// Space Complexity: O(1)

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxRow = 0, maxCount = 0;
        for (int i = 0; i < (int)mat.size(); ++i) {
            int countOnes = 0;
            // Count ones directly without count()
            for (auto val : mat[i]) {
                if (val == 1) ++countOnes;
            }
            if (countOnes > maxCount) {
                maxCount = countOnes;
                maxRow = i;
            }
        }
        return {maxRow, maxCount};
    }
};
