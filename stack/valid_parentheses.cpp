// Problem: Valid Parentheses
// Link: https://leetcode.com/problems/valid-parentheses/description/

#include <vector>
#include <stack>
#include <string>
using namespace std;

// Valid Parentheses
// Problem: Determine if a string of parentheses is valid by ensuring each opening bracket is closed in the correct order and type.

// Approach 1 - Brute Force (Recursive with Helper):
// This approach is not typically used for this problem due to its inefficiency.
// Time Complexity: O(2^n)
// Space Complexity: O(n)

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        std::function<bool(int, std::unordered_map<char, char>)> helper
            = [&](int i, std::unordered_map<char, char> pairs) {
                if (i == n) return true;
                if (pairs.find(s[i]) != pairs.end()) {
                    return helper(i + 1, pairs);
                }
                for (char c : {'(', '{', '['}) {
                    if (i + 1 < n && s[i + 1] == pairs[c]) {
                        return helper(i + 2, pairs);
                    }
                }
                return false;
            };
        std::unordered_map<char, char> pairs = {{')', '('}, {'}', '{'}, {']', '['}};
        return helper(0, pairs);
    }
};

// Approach 2 - Optimized (Stack):
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pairs = {{')', '('}, {'}', '{'}, {']', '['}};
        for (char c : s) {
            if (pairs.find(c) != pairs.end()) {
                if (st.empty() || st.top() != pairs[c]) {
                    return false;
                }
                st.pop();
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
