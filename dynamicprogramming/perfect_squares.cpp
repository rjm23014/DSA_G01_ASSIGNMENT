// Problem: Perfect Squares
// Link: https://leetcode.com/problems/perfect-squares/

#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Perfect Squares
// Problem: Given n, find the least number of perfect square numbers that sum to n.

// Approach 1 - Brute Force:
// Use DFS with memoization to try subtracting every perfect square <= n from n recursively.
// Time Complexity: O(n * sqrt(n)) in worst case due to memoization pruning
// Space Complexity: O(n) for recursion stack and memo

class Solution {
public:
    int numSquares(int n) {
        vector<int> memo(n + 1, -1);
        return dfs(n, memo);
    }
private:
    int dfs(int n, vector<int>& memo) {
        if (n == 0) return 0;
        if (memo[n] != -1) return memo[n];
        int res = n; // worst case: 1^2 added n times
        for (int i = 1; i * i <= n; ++i) {
            res = min(res, 1 + dfs(n - i*i, memo));
        }
        return memo[n] = res;
    }
};

// Approach 2 - Optimized:
// Use bottom-up DP to build up from 0 to n by trying all perfect squares <= current number.
// Time Complexity: O(n * sqrt(n))
// Space Complexity: O(n)

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j*j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
};
