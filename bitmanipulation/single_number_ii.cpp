// Problem: Single Number Ii
// Link: https://leetcode.com/problems/single-number-ii/description/

#include <vector>
#include <unordered_map>
using namespace std;

// Single Number II
// Problem: Find the element that appears once where all others appear thrice

// Approach 1 - Brute Force:
// Use a hash map to count frequency of each number.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto& [key, val] : freq) {
            if (val == 1) return key;
        }
        return -1; // should not reach if input satisfies problem constraints
    }
};

// Approach 2 - Optimized:
// Use bit manipulation to count bits at every position modulo 3,
// The remaining bits form the single number.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int bitCount = 0;
            for (int num : nums) {
                bitCount += (num >> i) & 1;
            }
            bitCount %= 3;
            result |= (bitCount << i);
        }
        return result;
    }
};
