// Problem: Best Time To Buy And Sell Stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Best Time To Buy And Sell Stock
// Problem: Find the maximum profit from a single buy-sell transaction given daily prices.

// Approach 1 - Brute Force:
// Check all possible buy-sell pairs to find maximum profit.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int n = (int)prices.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                max_profit = max(max_profit, prices[j] - prices[i]);
            }
        }
        return max_profit;
    }
};

// Approach 2 - Optimized:
// Track minimum price so far and calculate max profit if selling today.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int price : prices) {
            if (price < min_price) {
                min_price = price;  // update min buying price
            } else {
                max_profit = max(max_profit, price - min_price); // sell today for max profit
            }
        }
        return max_profit;
    }
};
