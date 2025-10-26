// Problem: Palindromic Substrings
// Link: https://leetcode.com/problems/palindromic-substrings/

#include <string>
#include <vector>
using namespace std;

// Palindromic Substrings
// Problem: Count the number of palindromic substrings in a given string.

// Approach 1 - Brute Force:
// Generate all substrings and check each if it is a palindrome
// Time Complexity: O(n^3) - O(n^2) substrings * O(n) palindrome check
// Space Complexity: O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int n = (int)s.size(), count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                bool isPalindrome = true;
                int left = i, right = j;
                while (left < right) {
                    if (s[left++] != s[right--]) {
                        isPalindrome = false;
                        break;
                    }
                }
                if (isPalindrome) count++;
            }
        }
        return count;
    }
};

// Approach 2 - Optimized:
// Expand around each character (and each gap) to find palindromes,
// counting all palindromic substrings in O(n^2) time with O(1) extra space.
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int n = (int)s.size();
        int count = 0;
        
        for (int center = 0; center < 2 * n - 1; ++center) {
            int left = center / 2;
            int right = left + center % 2; // right = left or left+1 (handles odd/even length)
            
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }
        
        return count;
    }
};
