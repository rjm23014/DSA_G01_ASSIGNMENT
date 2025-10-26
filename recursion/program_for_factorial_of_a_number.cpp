// Problem: Program For Factorial Of A Number
// Link: https://www.geeksforgeeks.org/program-for-factorial-of-a-number/

#include <iostream>
#include <cstdint> // For unsigned types; not strictly needed for basic factorial
using namespace std;

// Program For Factorial Of A Number
// Problem: Given a non-negative integer n, compute n! (n factorial).

// Approach 1 - Brute Force: Iterative multiplication from 1 to n.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int factorial(int n) {
        int res = 1;
        for (int i = 2; i <= n; ++i) {
            res *= i;
        }
        return res;
    }
};

// Approach 2 - Optimized: Recursive definition, using memoization for repeated calls (not implemented here for clarity).
// Time Complexity: O(n) (due to n function calls on stack)
// Space Complexity: O(n) (recursion stack space)
// Note: For repeated queries, precompute factorials up to the maximum 'n' (not shown here).

class Solution {
public:
    int factorial(int n) {
        return (n == 0 || n == 1) ? 1 : n * factorial(n - 1); // Using ternary for conciseness[2]
    }
};
