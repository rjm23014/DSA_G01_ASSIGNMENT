// Problem: 91?Leftpaneltabvalue=Problem
// Link: https://classroom.codingninjas.com/app/classroom/me/21313/content/451415/offering/6582572/problem/91?leftPanelTabValue=PROBLEM

#include <vector>
#include <string>
using namespace std;

// Decode Ways
// Problem: Count the number of ways to decode a string of digits as letters (A=1...Z=26)

// Approach 1 - Brute Force:
// Count by exploring all splits into valid 1 or 2-digit codes (recursion)
// Time Complexity: O(2^n) — worst-case exponential
// Space Complexity: O(n) — recursion stack

class Solution {
public:
    int numDecodings(string s) {
        return helper(s, 0);
    }

    int helper(const string& s, int idx) {
        if (idx == s.size()) return 1;
        if (s[idx] == '0') return 0;
        int res = helper(s, idx + 1);
        if (idx + 1 < s.size() && (s[idx] == '1' || (s[idx] == '2' && s[idx+1] <= '6')))
            res += helper(s, idx + 2);
        return res;
    }
};

// Approach 2 - Optimized:
// Use dynamic programming to store intermediate results
// Time Complexity: O(n)
// Space Complexity: O(n) — can be optimized to O(1) with variables

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        vector<int> dp(n + 1, 0);
        dp[n] = 1; // Base case: one way to decode empty string
        // dp[i] = ways to decode s[i..n)
        
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') continue; // No way to start with '0'
            dp[i] = dp[i+1];
            if (i+1 < n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))
                dp[i] += dp[i+2];
        }
        return dp[0];
    }
};
