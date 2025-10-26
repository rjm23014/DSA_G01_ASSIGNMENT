// Problem: Coin Change
// Link: https://leetcode.com/problems/coin-change/

#include <vector>
#include <algorithm>
using namespace std;

// Coin Change
// Problem: Find the fewest number of coins required to make up a given amount. Return -1 if it's not possible.

// Approach 1 - Brute Force:
// Use recursion to try all combinations by picking any coin if it does not exceed the remaining amount.
// Time Complexity: O(S^n), where S = amount, n = number of coin types (exponential)
// Space Complexity: O(S) for recursion stack

class Solution {
public:
    int coinChange(const vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        
        int minCoins = INT_MAX;
        for (int coin : coins) {
            int res = coinChange(coins, amount - coin);
            if (res >= 0 && res < minCoins) {
                minCoins = res + 1;
            }
        }
        return (minCoins == INT_MAX) ? -1 : minCoins;
    }
};

// Approach 2 - Optimized:
// Bottom-up Dynamic Programming builds the solution from 0 to amount.
// dp[i] = minimum coins to make amount i.
// Time Complexity: O(n * amount), where n = number of coins
// Space Complexity: O(amount)

class Solution {
public:
    int coinChange(const vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount + 1, amount + 1); // amount+1 as sentinel for "infinity"
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
