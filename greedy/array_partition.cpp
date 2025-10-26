// Problem: Array Partition
// Link: https://leetcode.com/problems/array-partition/description/

#include <vector>
#include <algorithm> // For sort()
using namespace std;

// Array Partition
// Problem: Given an array of 2n integers, group into n pairs (a1, b1), ..., (an, bn) to maximize the sum of min(a1, b1) + ... + min(an, bn).

// Approach 1 - Brute Force:
// Try all possible pair permutations (NP-hard in general), but impractical for n>4.
// Time Complexity: O((2n!)/(n! * 2^n)) — Permutations + pairs
// Space Complexity: O(2n) — Recursion stack if implemented

class Solution {
public:
    // Not practical to implement for n>4, so just conceptual here.
    // int arrayPairSum(vector<int>& nums) {
    //     // Brute force: try all pairings, compute sum of mins
    //     // Would require generating all possible pairings, which is non-trivial and inefficient.
    // }
};

// Approach 2 - Optimized:
// Sort the array, then sum every alternate element (0th, 2nd, 4th, ...).
// This pairs adjacent elements after sorting, minimizing "waste" per pair and maximizing the sum of mins[1][2].
// Time Complexity: O(n log n) — Due to sort
// Space Complexity: O(1) — In-place sort

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());         // Sort in ascending order
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) // Sum every alternate element
            sum += nums[i];
        return sum;
    }
};
