// Problem: Word Break
// Link: https://leetcode.com/problems/word-break/

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// Word Break
// Problem: Determine if string s can be segmented into a sequence of dictionary words.

// Approach 1 - Brute Force:
// Recursively try every prefix to see if it's in the dictionary, then recurse on the suffix.
// Time Complexity: O(2^n) in the worst case due to exponential branching.
// Space Complexity: O(n) for recursion stack.

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(s, dict);
    }
private:
    bool dfs(const string& s, const unordered_set<string>& dict) {
        if (s.empty()) return true;
        for (int i = 1; i <= (int)s.size(); ++i) {
            if (dict.count(s.substr(0, i)) && dfs(s.substr(i), dict))
                return true;
        }
        return false;
    }
};

// Approach 2 - Optimized:
// Use DP to store whether s[0:i] can be segmented.
// For each position i, check j < i if s[j:i] is in dict and dp[j] is true.
// Time Complexity: O(n^3) due to substring creation and DP iteration.
// Space Complexity: O(n) for dp array and O(m) for dictionary storage.

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = (int)s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // empty string can be segmented

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
