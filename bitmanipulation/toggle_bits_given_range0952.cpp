// Problem: Toggle Bits Given Range0952
// Link: https://www.geeksforgeeks.org/problems/toggle-bits-given-range0952/1

#include <bits/stdc++.h>
using namespace std;

// Toggle Bits Given Range
// Problem: Given a non-negative number n and two values l and r, toggle the bits in the binary representation of n from the lth to the rth least significant bit.

// Approach 1 - Brute Force:
// Flip each bit from l to r by checking and toggling individually.
// Time Complexity: O(r - l + 1)
// Space Complexity: O(1)

class Solution {
public:
    int toggleBits(int n, int l, int r) {
        for (int i = l; i <= r; i++) {
            // Toggle ith bit using XOR
            n ^= (1 << (i - 1));
        }
        return n;
    }
};

// Approach 2 - Optimized:
// Construct a mask with bits set from l to r, then XOR it with n to toggle all at once.
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int toggleBits(int n, int l, int r) {
        // Create mask with bits l to r set: (1 << (r-l+1)) -1 shifted left by (l-1)
        int mask = ((1 << (r - l + 1)) - 1) << (l - 1);
        return n ^ mask;
    }
};
