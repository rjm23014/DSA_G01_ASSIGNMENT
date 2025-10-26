// Problem: 0 1 Knapsack Problem0945
// Link: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include <vector>
#include <algorithm>
using namespace std;

// 0-1 Knapsack Problem
// Problem: Find maximum value of items with given weights that fit into a knapsack of capacity W.

// Approach 1 - Brute Force:
// Use recursion to consider each item’s inclusion or exclusion.
// Time Complexity: O(2^N) (exponential, all subsets explored)
// Space Complexity: O(N) (recursion call stack)

class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt, int n) {
        if (n == 0 || W == 0) 
            return 0;
        if (wt[n-1] > W) 
            return knapsack(W, val, wt, n-1);
        return max(val[n-1] + knapsack(W - wt[n-1], val, wt, n-1),
                   knapsack(W, val, wt, n-1));
    }
};

// Approach 2 - Optimized:
// Use dynamic programming with tabulation (bottom-up) to avoid recomputation.
// Time Complexity: O(N*W)
// Space Complexity: O(N*W)

class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt, int n) {
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (wt[i-1] <= w) {
                    dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
                } else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        return dp[n][W];
    }
};
