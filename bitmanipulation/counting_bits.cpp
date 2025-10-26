// Problem: Counting Bits
// Link: https://leetcode.com/problems/counting-bits/description/

#include <vector>
using namespace std;

// Counting Bits
// Problem: Given an integer n, return an array ans of length n + 1 where ans[i] is the count of 1s in binary representation of i.

// Approach 1 - Brute Force:
// Count bits of every number by checking each bit individually.
// Time Complexity: O(n * log n) because counting bits for i takes at most O(log i) bits.
// Space Complexity: O(n) for the output array.

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            int count = 0, x = i;
            while (x > 0) {
                count += (x & 1);
                x >>= 1;
            }
            res[i] = count;
        }
        return res;
    }
};

// Approach 2 - Optimized:
// Use DP and bit manipulation: 
// f(i) = f(i >> 1) + (i & 1); the count of bits for i is count for i/2 plus last bit.
// Time Complexity: O(n) since each number is processed once.
// Space Complexity: O(n) for the output array.

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};
