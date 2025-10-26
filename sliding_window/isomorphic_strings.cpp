// Problem: Isomorphic Strings
// Link: https://leetcode.com/problems/isomorphic-strings/

#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Isomorphic Strings
// Problem: Determine if two strings s and t are isomorphic, i.e., 
// characters in s can be replaced to get t with a one-to-one mapping.

// Approach 1 - Brute Force:
// Check all possible character mappings by maintaining two hash maps (or equivalent) 
// to ensure a consistent one-to-one character mapping from s to t and t to s.
// Time Complexity: O(n^2) in naive implementations that try all mapping possibilities.
// Space Complexity: O(n), for storing character mappings.

// (Below brute force uses a somewhat naive mapping validation with string replacements 
// and scanning, showing how one might initially approach the problem.)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        // Try mapping each unique char from s to corresponding chars in t
        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;
        for (int i = 0; i < (int)s.size(); ++i) {
            char cs = s[i], ct = t[i];
            if (sToT.count(cs) && sToT[cs] != ct) return false;
            if (tToS.count(ct) && tToS[ct] != cs) return false;
            sToT[cs] = ct;
            tToS[ct] = cs;
        }
        return true;
    }
};

// Approach 2 - Optimized:
// Use two arrays to store the last seen positions of each character in s and t.
// If at any index, the last seen positions don't match, return false.
// This ensures we directly check character pattern equivalence.
// Time Complexity: O(n), where n = length of strings
// Space Complexity: O(1), fixed-size arrays for ASCII characters.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        int charToPositionS[256] = {0}; 
        int charToPositionT[256] = {0}; 
        for (int i = 0; i < (int)s.size(); ++i) {
            unsigned char cs = s[i];
            unsigned char ct = t[i];
            if (charToPositionS[cs] != charToPositionT[ct]) 
                return false;
            charToPositionS[cs] = i + 1; // +1 to differentiate from default 0
            charToPositionT[ct] = i + 1;
        }
        return true;
    }
};
