// Problem: Longest Common Subsequence
// Link: https://leetcode.com/problems/longest-common-subsequence/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Longest Common Subsequence
// Problem: Given two strings, return the length of their longest common subsequence.

// Approach 1 - Brute Force:
// Recursive approach that explores all subsequences by pairing characters or skipping them.
// Time Complexity: O(2^(m+n)) where m and n are lengths of text1 and text2 respectively.
// Space Complexity: O(m+n) for recursion stack.

class Solution {
public:
    int lcsRec(const string& text1, const string& text2, int i, int j) {
        if (i < 0 || j < 0) return 0;
        if (text1[i] == text2[j]) {
            return 1 + lcsRec(text1, text2, i - 1, j - 1);
        }
        return max(lcsRec(text1, text2, i - 1, j), lcsRec(text1, text2, i, j - 1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        return lcsRec(text1, text2, (int)text1.size() - 1, (int)text2.size() - 1);
    }
};

// Approach 2 - Optimized:
// Dynamic Programming (bottom-up tabulation) approach uses a 2D table to store results of subproblems.
// Time Complexity: O(m*n)
// Space Complexity: O(m*n), where m and n are lengths of text1 and text2.

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = (int)text1.size(), n = (int)text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};
