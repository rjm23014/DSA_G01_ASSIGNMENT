// Problem: Check Whether K Th Bit Is Set Or Not 1587115620
// Link: https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

#include <iostream>
using namespace std;

// Check Whether K Th Bit Is Set Or Not
// Problem: Given a number n and a bit position k, determine if the k-th bit of n is set (1) or not (0).
// Note: Bits are zero-indexed from the right (0 is least significant bit).

// Approach 1 - Brute Force:
// Shift the number right k times and check the least significant bit.
// Time Complexity: O(k) because of right shifts.
// Space Complexity: O(1)

class Solution {
public:
    int checkKthBit(int n, int k) {
        // Shift right k times and check last bit
        return (n >> k) & 1;
    }
};

// Approach 2 - Optimized:
// Use bitwise AND with (1 << k) to directly check if k-th bit is set.
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int checkKthBit(int n, int k) {
        // Check if k-th bit is set by AND with mask (1 << k)
        return (n & (1 << k)) != 0 ? 1 : 0;
    }
};
