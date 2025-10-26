// Problem: Coin Change
// Link: https://leetcode.com/problems/coin-change/description/

#include <vector>
#include <algorithm>
using namespace std;

// Coin Change
// Problem: Given coins of different denominations and a total amount, find the minimum number of coins that make up that amount. Return -1 if not possible.

// Approach 1 - Brute Force:
// Use recursion to try every coin for the current amount, reducing the amount recursively.
// Time Complexity: Exponential, O(S^n) where S is amount and n is number of coins.
// Space Complexity: O(S) due to recursion depth.

class Solution {
public:
    int coinChangeHelper(const vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        int res = -1;
        for (int c : coins) {
            int sub = coinChangeHelper(coins, amount - c);
            if (sub == -1) continue;
            int candidate = sub + 1;
            if (res == -1 || candidate < res) res = candidate;
        }
        return res;
    }

    int coinChange(vector<int>& coins, int amount) {
        return coinChangeHelper(coins, amount);
    }
};

// Approach 2 - Optimized:
// Use bottom-up dynamic programming to build minimum coins for amounts up to target.
// dp[i] = minimum coins for amount i; initialize dp array large, dp[0] = 0.
// For each coin, update dp[amount] = min(dp[amount], dp[amount - coin] + 1).
// Time Complexity: O(n * amount), n = number of coins.
// Space Complexity: O(amount).

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int a = 1; a <= amount; ++a) {
            for (int c : coins) {
                if (a - c >= 0) {
                    dp[a] = min(dp[a], dp[a - c] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
