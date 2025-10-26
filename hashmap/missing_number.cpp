// Problem: Missing Number
// Link: https://leetcode.com/problems/missing-number/description/

#include <vector>
#include <unordered_set>
using namespace std;

// Missing Number
// Problem: Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing.

// Approach 1 - Brute Force:
// Use a hash set to store all seen numbers, then iterate from 0 to n checking for the first missing.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i <= n; ++i) {
            if (!seen.count(i)) return i;
        }
        return -1; // unreachable given problem constraints
    }
};

// Approach 2 - Optimized:
// XOR all numbers in the array with all indices in [0, n]. Each number cancels out except the missing one.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missing = n;
        for (int i = 0; i < n; ++i) {
            missing ^= i ^ nums[i]; // XOR with each index and element
        }
        return missing;
    }
};
