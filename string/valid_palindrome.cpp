// Problem: Valid Palindrome
// Link: https://leetcode.com/problems/valid-palindrome/description/

#include <string>
#include <cctype>
using namespace std;

// Valid Palindrome
// Problem: Check if a string is a palindrome considering only alphanumeric characters and ignoring case.

// Approach 1 - Brute Force:
// Clean the string by extracting only alphanumeric characters and converting them to lowercase,
// then check if the cleaned string is a palindrome.
// Time Complexity: O(n)
// Space Complexity: O(n) for the cleaned string

class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        for (char c : s) {
            if (isalnum(c)) {
                filtered.push_back(tolower(c));
            }
        }
        int left = 0, right = (int)filtered.size() - 1;
        while (left < right) {
            if (filtered[left] != filtered[right]) {
                return false;
            }
            ++left; --right;
        }
        return true;
    }
};

// Approach 2 - Optimized:
// Use two pointers to compare characters in-place without extra space,
// skip non-alphanumeric characters, and compare case-insensitively.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = (int)s.size() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) ++left;
            while (left < right && !isalnum(s[right])) --right;
            if (tolower(s[left]) != tolower(s[right])) return false;
            ++left; --right;
        }
        return true;
    }
};
