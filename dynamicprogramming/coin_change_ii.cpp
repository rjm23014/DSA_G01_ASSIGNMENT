// Problem: Coin Change Ii
// Link: https://leetcode.com/problems/coin-change-ii/

#include <vector>
#include <limits.h>
using namespace std;

// 518. Coin Change II
// Problem: Count the number of ways to make up a given amount using an infinite number of coins of each denomination.

// Approach 1 - Brute Force (Recursive, all combinations):
// Recursively count all possible combinations by either including or excluding each coin.
// Time Complexity: O(2^n) [exponential, each coin is either chosen or not]
// Space Complexity: O(n) [recursion depth]

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
