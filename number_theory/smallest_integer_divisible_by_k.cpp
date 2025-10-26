// Problem: Smallest Integer Divisible By K
// Link: https://leetcode.com/problems/smallest-integer-divisible-by-k/description/

#include <unordered_set>
// No other headers necessary
using namespace std;

// Smallest Integer Divisible by K
// Problem: Find the length of the smallest positive integer N composed only of digit '1' that is divisible by K, or return -1 if none exists.

// Approach 1 - Brute Force:
// Construct each number having all '1's (1, 11, 111, ...) up to a limit, and check divisibility directly.
// Time Complexity: O(K^2) in worst case due to large integer construction and modulo operations (not practical).
// Space Complexity: O(K) due to storing the number or operations on it.

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        // Directly constructing the repunit is infeasible for large K, so simulate number using string for clarity here
        if (K == 1) return 1;
        string repunit = "1";
        for (int length = 1; length <= 10000; ++length) { // limit for example, not reliable for large K
            // Convert string to modulo integer using iterative mod
            long long remainder = 0;
            for (char c : repunit) {
                remainder = (remainder * 10 + (c - '0')) % K;
            }
            if (remainder == 0) return length;
            repunit += '1';
        }
        return -1;
    }
};

// Approach 2 - Optimized:
// Use modular arithmetic and track remainders to avoid large number construction.
// At each step, remainder = (remainder * 10 + 1) % K.
// If remainder repeats, no solution exists (returns -1).
// Time Complexity: O(K)
// Space Complexity: O(1)

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        // If K divisible by 2 or 5, no repunit divisible by K exists
        if (K % 2 == 0 || K % 5 == 0) return -1;

        int remainder = 0;
        for (int length = 1; length <= K; ++length) {
            remainder = (remainder * 10 + 1) % K;
            if (remainder == 0) return length;
        }
        return -1;
    }
};
