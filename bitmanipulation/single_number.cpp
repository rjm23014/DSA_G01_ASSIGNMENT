// Problem: Single Number
// Link: https://leetcode.com/problems/single-number/description/

#include <vector>
#include <unordered_map>
using namespace std;

// Single Number
// Problem: Find the element that appears only once in an array where every other element appears twice.

// Approach 1 - Brute Force:
// Use a hash map to count occurrences of each number and find the one with count 1.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            ++count[num];
        }
        for (const auto& [num, cnt] : count) {
            if (cnt == 1) return num;
        }
        return -1; // Should never reach here given problem constraints
    }
};

// Approach 2 - Optimized:
// Use XOR operation properties to cancel out duplicate numbers and isolate the single number.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num; // XOR duplicates cancel out, single number remains
        }
        return result;
    }
};
