// Problem: Counting Bits
// Link: https://leetcode.com/problems/counting-bits/

#include <vector>
#include <bitset>
using namespace std;

// Counting Bits
// Problem: Given an integer n, return an array of length n + 1 counting the number of 1's in the binary representation of each i (0 <= i <= n).

// Approach 1 - Brute Force:
// For each number 0..n, use built-in __builtin_popcount (counts set bits in an integer).
// Time Complexity: O(n log n) (for each of n numbers, log n bits are processed)
// Space Complexity: O(n) (output space, excluding input)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; ++i)
            ans[i] = __builtin_popcount(i);
        return ans;
    }
};

// Approach 2 - Optimized (Dynamic Programming):
// f(i) = f(i >> 1) + (i & 1). This leverages previously computed values for i/2.
// Time Complexity: O(n) (single pass)
// Space Complexity: O(n) (output space, excluding input)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; ++i)
            ans[i] = ans[i >> 1] + (i & 1); // ans[i] = ans[i/2] + (i%2)
        return ans;
    }
};
