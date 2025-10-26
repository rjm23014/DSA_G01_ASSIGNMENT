// Problem: Nth Fibonacci Number1335
// Link: https://www.geeksforgeeks.org/problems/nth-fibonacci-number1335/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <iostream>
using namespace std;

// Nth Fibonacci Number1335
// Problem: Find the nth Fibonacci number

// Approach 1 - Brute Force:
// Recursive implementation directly applying the definition
// Time Complexity: O(2^n) due to repeated calculations
// Space Complexity: O(n) recursion stack space

class Solution {
public:
    int nthFibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return nthFibonacci(n - 1) + nthFibonacci(n - 2);
    }
};

// Approach 2 - Optimized:
// Iterative approach with two pointers to calculate Fibonacci numbers
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int nthFibonacci(int n) {
        if (n == 0) return 0;
        int prev2 = 0, prev1 = 1, curr;
        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
