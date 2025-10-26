// Problem: Regular Expression Matching
// Link: https://leetcode.com/problems/regular-expression-matching/

#include <string>
#include <vector>
using namespace std;

// Regular Expression Matching
// Problem: Implement regex matching with '.' (any single char) and '*' (zero or more of preceding char)

// Approach 1 - Brute Force:
// Use simple recursion exploring all possibilities for '*' matching zero or more chars in s.
// Time Complexity: Exponential - roughly O(2^(m+n)) in worst case, m = s.size(), n = p.size()
// Space Complexity: O(m+n) recursion stack depth

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        return dfs(s, 0, p, 0);
    }
private:
    bool dfs(const string &s, int i, const string &p, int j) {
        if (j == p.size()) return i == s.size();

        bool matchFirst = (i < (int)s.size()) && (p[j] == s[i] || p[j] == '.');

        if (j + 1 < (int)p.size() && p[j + 1] == '*') {
            // '*' can match zero occurrences or at least one if first chars match
            return dfs(s, i, p, j + 2) || (matchFirst && dfs(s, i + 1, p, j));
        } else {
            // direct match, advance both pointers
            return matchFirst && dfs(s, i + 1, p, j + 1);
        }
    }
};

// Approach 2 - Optimized:
// Use DP with memoization (top-down) to store results of subproblems and avoid recomputation.
// Time Complexity: O(m*n), m = s.size(), n = p.size()
// Space Complexity: O(m*n) memo table + recursion stack

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        memo.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dfs(s, 0, p, 0);
    }
private:
    vector<vector<int>> memo;

    bool dfs(const string &s, int i, const string &p, int j) {
        if (memo[i][j] != -1) return memo[i][j] == 1;

        if (j == p.size()) 
            return memo[i][j] = (i == s.size());

        bool matchFirst = (i < (int)s.size()) && (p[j] == s[i] || p[j] == '.');

        bool ans;
        if (j + 1 < (int)p.size() && p[j + 1] == '*') {
            ans = dfs(s, i, p, j + 2) || (matchFirst && dfs(s, i + 1, p, j));
        } else {
            ans = matchFirst && dfs(s, i + 1, p, j + 1);
        }
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
};
