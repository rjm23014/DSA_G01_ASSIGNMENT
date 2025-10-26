// Problem: Climbing Stairs
// Link: https://leetcode.com/problems/climbing-stairs/

#include <vector>
using namespace std;

// Climbing Stairs
// Problem: Given n steps, find how many distinct ways to climb to the top
//          You can climb either 1 or 2 steps at a time

// Approach 1 - Brute Force:
// Recursively explore all possible ways to reach step n by trying 1 or 2 steps each time.
// Time Complexity: O(2^n) due to overlapping subproblems and exponential recursion tree
// Space Complexity: O(n) for recursion stack depth

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 1;  // base case: one way to stand on ground
        if (n < 0) return 0;   // invalid step
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// Approach 2 - Optimized:
// Use dynamic programming to build solutions from bottom up,
// storing ways to reach previous steps to avoid recomputation.
// Time Complexity: O(n)
// Space Complexity: O(1) using two variables to track previous results (Fibonacci-like)

class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1; // ways to reach step 0
        int prev1 = 1; // ways to reach step 1
        for (int i = 2; i <= n; ++i) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
