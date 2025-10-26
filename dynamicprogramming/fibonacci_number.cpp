// Problem: Fibonacci Number
// Link: https://leetcode.com/problems/fibonacci-number/

#include <vector>
using namespace std;

// Fibonacci Number
// Problem: Return the nth Fibonacci number where F(0) = 0, F(1) = 1

// Approach 1 - Brute Force:
// Simple recursive implementation directly based on definition
// Time Complexity: O(2^n) due to repeated calculations
// Space Complexity: O(n) for recursion stack

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fib(n - 1) + fib(n - 2);
    }
};

// Approach 2 - Optimized:
// Iterative dynamic programming approach using two variables
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int prev = 0, curr = 1;
        for (int i = 2; i <= n; i++) {
            int next = prev + curr;
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
