// Problem: N Queens
// Link: https://leetcode.com/problems/n-queens/description/

#include <vector>
#include <string>
using namespace std;

// N Queens
// Problem: Place n queens on an n x n chessboard so that no two queens attack each other,
// return all distinct board configurations.

// Approach 1 - Brute Force:
// Place queens column by column, check safety by scanning rows, columns, and diagonals each time.
// Time Complexity: O(n^3) in worst case due to repeated safety checks for each cell and recursion.
// Space Complexity: O(n^2) for the board and recursion stack.

class Solution {
    bool isSafe(int row, int col, const vector<string>& board, int n) {
        // Check left side row
        for (int c = 0; c < col; c++)
            if (board[row][c] == 'Q')
                return false;
        // Check upper left diagonal
        for (int r = row, c = col; r >= 0 && c >= 0; r--, c--)
            if (board[r][c] == 'Q')
                return false;
        // Check lower left diagonal
        for (int r = row, c = col; r < n && c >= 0; r++, c--)
            if (board[r][c] == 'Q')
                return false;
        return true;
    }
    
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, board, ans, n);
        return ans;
    }
};

// Approach 2 - Optimized:
// Use three arrays to mark attacked rows and diagonals, so safety check is O(1).
// Time Complexity: O(n!) - pruning reduces the search space considerably.
// Space Complexity: O(n) for auxiliary arrays and O(n^2) for board storage.

class Solution {
    void solve(int col, vector<string>& board, vector<vector<string>>& ans,
               vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                
                solve(col + 1, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);
                
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);
        solve(0, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);
        return ans;
    }
};
