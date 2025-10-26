// Problem: Longest Palindromic Substring
// Link: https://leetcode.com/problems/longest-palindromic-substring/

#include <string>
#include <vector>
using namespace std;

// Longest Palindromic Substring
// Problem: Find the longest contiguous substring that is a palindrome.

// Approach 1 - Brute Force:
// Check every substring and verify if it's a palindrome.
// Time Complexity: O(n^3) due to substring checks and palindromic verification.
// Space Complexity: O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        if (n < 2) return s;

        int maxLen = 1;
        int start = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                bool isPalindrome = true;
                for (int k = 0; k <= (j - i) / 2; ++k) {
                    if (s[i + k] != s[j - k]) {
                        isPalindrome = false;
                        break;
                    }
                }
                if (isPalindrome && (j - i + 1) > maxLen) {
                    maxLen = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

// Approach 2 - Optimized:
// Expand around each character (and between characters) to find palindromes.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        if (n < 2) return s;

        int start = 0, maxLen = 1;

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                --left;
                ++right;
            }
            return right - left - 1; // length of palindrome
        };

        for (int i = 0; i < n; ++i) {
            int len1 = expandAroundCenter(i, i);     // odd length palindrome
            int len2 = expandAroundCenter(i, i + 1); // even length palindrome
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};
