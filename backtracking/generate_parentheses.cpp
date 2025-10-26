// Problem: Generate Parentheses
// Link: https://leetcode.com/problems/generate-parentheses/description/

#include <vector>
#include <string>
using namespace std;

// Generate Parentheses
// Problem: Generate all combinations of well-formed parentheses given n pairs.

// Approach 1 - Brute Force:
// Generate all possible strings of '(' and ')' of length 2n,
// then check each string for validity.
// Time Complexity: O(2^(2n) * n) — generate and validate all strings
// Space Complexity: O(2^(2n) * n) — to store all combinations and recursion stack

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current(2 * n, ' ');

        function<void(int)> generateAll = [&](int pos) {
            if (pos == 2 * n) {
                if (isValid(current))
                    result.push_back(current);
                return;
            }
            current[pos] = '(';
            generateAll(pos + 1);
            current[pos] = ')';
            generateAll(pos + 1);
        };

        auto isValid = [&](const string& s) {
            int balance = 0;
            for (char c : s) {
                if (c == '(') balance++;
                else balance--;
                if (balance < 0) return false;
            }
            return balance == 0;
        };

        generateAll(0);
        return result;
    }
};

// Approach 2 - Optimized:
// Use backtracking to build valid strings by adding '(' or ')' only when valid
// Time Complexity: O(4^n / sqrt(n)) (Catalan number count of valid strings)
// Space Complexity: O(n) for recursion stack and building current string

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
private:
    void backtrack(vector<string>& result, string& current, int open, int close, int max) {
        if ((int)current.size() == 2 * max) {
            result.push_back(current);
            return;
        }
        if (open < max) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, max);
            current.pop_back();
        }
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, max);
            current.pop_back();
        }
    }
};
