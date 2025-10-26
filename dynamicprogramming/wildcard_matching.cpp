// Problem: Wildcard Matching
// Link: https://leetcode.com/problems/wildcard-matching/

#include <string>
#include <vector>
using namespace std;

// Wildcard Matching
// Problem: Implement wildcard pattern matching with '?' and '*' supporting full string match

// Approach 1 - Brute Force:
// Recursive backtracking tries all match possibilities with '*' and '?'.
// Time Complexity: Exponential, worst O(2^(m+n)) due to branching on '*'
// Space Complexity: O(m + n) due to recursion stack depth where m and n are lengths of s and p respectively

class Solution {
public:
    bool isMatch(string s, string p) {
        return dfs(s, p, 0, 0);
    }
private:
    bool dfs(const string& s, const string& p, int i, int j) {
        // If pattern is consumed, string must be consumed too
        if (j == (int)p.size()) return i == (int)s.size();
        // If string is consumed, pattern must be all '*'
        if (i == (int)s.size()) {
            for (int k = j; k < (int)p.size(); k++)
                if (p[k] != '*') return false;
            return true;
        }
        if (p[j] == '*') {
            // '*' matches empty or one or more chars
            return dfs(s, p, i, j + 1) || dfs(s, p, i + 1, j);
        }
        if (p[j] == '?' || p[j] == s[i]) {
            return dfs(s, p, i + 1, j + 1);
        }
        return false;
    }
};

// Approach 2 - Optimized:
// Dynamic Programming with memoization or bottom-up fills a table dp indicating substring matches.
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = (int)s.size(), n = (int)p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true; // empty pattern matches empty string

        // pattern prefixes with '*' can match empty string
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') dp[i][0] = dp[i - 1][0];
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[i - 1] == '*') {
                    // '*' matches empty sequence (dp[i-1][j]) or non-empty sequence (dp[i][j-1])
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else if (p[i - 1] == '?' || p[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};
