// Problem: Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Longest Substring Without Repeating Characters
// Problem: Find the length of the longest substring without repeating characters.

// Approach 1 - Brute Force:
// Check every substring and verify if it contains unique characters.
// Time Complexity: O(n^3) due to substring generation and duplicate checks.
// Space Complexity: O(min(n, m)) where m is charset size for the hash set.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = (int)s.size(), maxLen = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<char> seen;
            for (int j = i; j < n; ++j) {
                if (seen.count(s[j])) break;
                seen.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};

// Approach 2 - Optimized:
// Use sliding window with an index map to track the last occurrence of characters,
// moving the left pointer to avoid duplicates efficiently.
// Time Complexity: O(n), each character visited at most twice.
// Space Complexity: O(min(n, m)) where m is charset size (constant 128 for ASCII).

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;
        int maxLen = 0, left = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            char c = s[right];
            if (lastIndex.count(c) && lastIndex[c] >= left) {
                left = lastIndex[c] + 1;  // Move left pointer past previous occurrence
            }
            lastIndex[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
