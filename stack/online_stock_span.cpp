// Problem: Online Stock Span
// Link: https://leetcode.com/problems/online-stock-span/description/

#include <stack>
#include <utility>
using namespace std;

// Online Stock Span
// Problem: Return the maximum number of consecutive days the stock price was less than or equal to today's price.

// Approach 1 - Brute Force:
// For each price, traverse backward comparing with previous prices until a greater price is found.
// Time Complexity: O(n^2) in worst case (if prices keep increasing)
// Space Complexity: O(n) to store prices

class StockSpanner {
    vector<int> prices;
public:
    StockSpanner() {
        prices.clear();
    }

    int next(int price) {
        prices.push_back(price);
        int span = 1;
        int i = (int)prices.size() - 2;
        while (i >= 0 && prices[i] <= price) {
            span++;
            i--;
        }
        return span;
    }
};

// Approach 2 - Optimized:
// Use a stack storing pairs of (price, span) to jump over consecutive smaller or equal prices.
// For each new price, pop from stack all prices <= current price and accumulate their spans.
// Time Complexity: O(n) amortized, each price pushed and popped at most once.
// Space Complexity: O(n) for the stack.

class StockSpanner {
    stack<pair<int,int>> st; // pair(price, span)
public:
    StockSpanner() {
        // empty stack initially
    }

    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.emplace(price, span);
        return span;
    }
};
