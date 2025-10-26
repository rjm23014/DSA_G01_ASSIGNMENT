// Problem: Intro To Dp.Html
// Link: https://cp-algorithms.com/dynamic_programming/intro-to-dp.html

#include <vector>
using namespace std;

// Intro To Dynamic Programming
// Problem: Compute the nth Fibonacci number using brute force and optimized dynamic programming

// Approach 1 - Brute Force:
// Naive recursive solution, recomputes overlapping subproblems
// Time Complexity: O(2^n)
// Space Complexity: O(n) stack space

class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        return fib(n - 1) + fib(n - 2);
    }
};

// Approach 2 - Optimized:
// Top-down memoization, caches already computed values
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};
