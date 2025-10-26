// Problem: Sudoku Solver
// Link: https://leetcode.com/problems/sudoku-solver/description/

#include <vector>
using namespace std;

// Sudoku Solver
// Problem: Fill a 9x9 Sudoku board so each row, column, and 3x3 sub-box contains digits 1-9 exactly once.

// Approach 1 - Brute Force:
// Backtracking by trying digits 1-9 in empty cells and checking validity each time.
// Time Complexity: O(9^(m)) where m is number of empty cells (worst case)
// Space Complexity: O(m) for recursion stack

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
private:
    bool backtrack(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true;       // all rows processed
        if (col == 9) return backtrack(board, row + 1, 0);  // move to next row
        if (board[row][col] != '.') return backtrack(board, row, col + 1);

        for (char c = '1'; c <= '9'; ++c) {
            if (isValid(board, row, col, c)) {
                board[row][col] = c;
                if (backtrack(board, row, col + 1)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

    bool isValid(const vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == c) return false;
        }
        return true;
    }
};

// Approach 2 - Optimized:
// Use sets or arrays to track used numbers in rows, cols, and boxes for O(1) validity checks
// Time Complexity: same worst case O(9^(m)) but faster in practice due to pruning and O(1) checks
// Space Complexity: O(9*9) for tracking arrays + O(m) recursion stack

class Solution {
    vector<vector<char>>* boardPtr;
    vector<vector<bool>> rows{9, vector<bool>(9, false)};
    vector<vector<bool>> cols{9, vector<bool>(9, false)};
    vector<vector<bool>> boxes{9, vector<bool>(9, false)};
public:
    void solveSudoku(vector<vector<char>>& board) {
        boardPtr = &board;
        // Initialize tracking structures
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    int num = board[r][c] - '1';
                    rows[r][num] = true;
                    cols[c][num] = true;
                    boxes[boxIndex(r, c)][num] = true;
                }
            }
        }
        backtrack(0, 0);
    }
private:
    bool backtrack(int r, int c) {
        if (r == 9) return true;
        if (c == 9) return backtrack(r + 1, 0);
        if ((*boardPtr)[r][c] != '.') return backtrack(r, c + 1);

        for (int num = 0; num < 9; ++num) {
            if (!rows[r][num] && !cols[c][num] && !boxes[boxIndex(r,c)][num]) {
                (*boardPtr)[r][c] = num + '1';
                rows[r][num] = cols[c][num] = boxes[boxIndex(r,c)][num] = true;

                if (backtrack(r, c + 1)) return true;

                rows[r][num] = cols[c][num] = boxes[boxIndex(r,c)][num] = false;
                (*boardPtr)[r][c] = '.';
            }
        }
        return false;
    }

    int boxIndex(int row, int col) {
        return (row / 3) * 3 + (col / 3);
    }
};
