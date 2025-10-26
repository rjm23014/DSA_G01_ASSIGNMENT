// Problem: Count Total Set Bits 1587115620
// Link: https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

#include <bits/stdc++.h>
using namespace std;

// Count Total Set Bits
// Problem: Count total set bits in binary representation from 1 to n

// Approach 1 - Brute Force:
// Iterate through every number from 1 to n, count set bits individually using __builtin_popcount
// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution {
  public:
    int countSetBits(int n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            result += __builtin_popcount(i);  // built-in optimized counting of bits
        }
        return result;
    }
};

// Approach 2 - Optimized:
// Use a recursive approach leveraging the properties of numbers and set bits, dividing the problem by highest power of 2
// Time Complexity: O(log n)
// Space Complexity: O(log n) due to recursion stack

class Solution {
  public:
    int countSetBits(int n) {
        if (n == 0) return 0;

        // x = largest power of 2 less than or equal to n
        int x = 0;
        while ((1 << (x + 1)) <= n) x++;

        int power_x = 1 << x; 

        // Bits set in numbers from 1 to 2^x - 1 = x * 2^(x-1)
        int bits_up_to_2x = x * (power_x >> 1);

        // MSB set bits from 2^x to n = n - 2^x + 1
        int msb_count = n - power_x + 1;

        // Remaining bits after removing MSB bits counted
        int rest = n - power_x;

        // Recursively count set bits in remainder
        return bits_up_to_2x + msb_count + countSetBits(rest);
    }
};
