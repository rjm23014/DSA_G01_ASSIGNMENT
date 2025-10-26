// Problem: Longest Palindromic Subsequence
// Link: https://leetcode.com/problems/longest-palindromic-subsequence/

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Longest Palindromic Subsequence
// Problem: Given a string s, find the length of the longest subsequence that is a palindrome.

// Approach 1 - Brute Force:
// Generate all possible subsequences, check for palindrome, keep track of max.
// Time Complexity: O(2^n)
// Space Complexity: O(n) excluding recursion stack

class Solution {
    void getAllSubseqs(const string& s, int idx, string curr, int& max_len) {
        if (idx == s.size()) {
            if (equal(curr.begin(), curr.end(), curr.rbegin()) && curr.size() > max_len)
                max_len = curr.size();
            return;
        }
        getAllSubseqs(s, idx + 1, curr + s[idx], max_len); // include
        getAllSubseqs(s, idx + 1, curr, max_len);          // exclude
    }
public:
    int longestPalindromeSubseq(string s) {
        int max_len = 0;
        getAllSubseqs(s, 0, "", max_len);
        return max_len;
    }
};

// Approach 2 - Optimized (Dynamic Programming, O(n^2) Space):
// Use DP table: dp[i][j] = length of longest palindromic subsequence in s[i..j].
// Fill diagonal (single char = 1), then fill for increasing substring lengths.
// If chars match, dp[i][j] = dp[i+1][j-1] + 2; else, max of dp[i+1][j] or dp[i][j-1].
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; --i) {         // Start from end, fill up
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};
