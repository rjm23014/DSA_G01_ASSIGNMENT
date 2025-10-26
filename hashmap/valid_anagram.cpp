// Problem: Valid Anagram
// Link: https://leetcode.com/problems/valid-anagram/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Valid Anagram
// Problem: Check if two strings are anagrams of each other.

// Approach 1 - Brute Force:
// Sort both strings and compare equality.
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(n) because sorted copies of strings are created

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// Approach 2 - Optimized:
// Use a frequency count vector for characters and compare counts in one pass.
// Time Complexity: O(n), where n is string length
// Space Complexity: O(1), fixed size vector of 26 for lowercase English letters

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        for (char c : t) {
            if (--count[c - 'a'] < 0) return false;
        }
        return true;
    }
};
