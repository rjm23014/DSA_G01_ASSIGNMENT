// Problem: Find The Duplicate Number
// Link: https://leetcode.com/problems/find-the-duplicate-number/description/

#include <vector>
#include <unordered_set>

using namespace std;

// Find The Duplicate Number
// Problem: Given an array of n + 1 integers where each integer is in the range [1, n] and there is only one duplicate number, find the duplicate number.

// Approach 1 - Brute Force (HashSet):
// Create a set to track unique numbers. Iterate through the array and return the number that already exists in the set.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                return num; // Duplicate found
            }
            seen.insert(num);
        }
        return 0; // Should not reach here
    }
};

// Approach 2 - Optimized (Floyd's Tortoise and Hare):
// Treat the array as a linked list where each number points to the next index. Use two pointers, slow and fast, to detect the cycle, which starts at the duplicate number.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
    int findDuplicate(vector<int>& nums) {
        // Phase 1: Detect the cycle using tortoise and hare algorithm
        int tortoise = nums[0];
        int hare = nums[0];
        do {
            tortoise = nums[tortoise]; // Move one step at a time
            hare = nums[nums[hare]]; // Move two steps at a time
        } while (tortoise != hare);

        // Phase 2: Find the start of the cycle
        tortoise = nums[0]; // Reset tortoise to the start
        while (tortoise != hare) {
            tortoise = nums[tortoise]; // Move one step at a time
            hare = nums[hare]; // Move one step at a time
        }

        return hare; // Return the duplicate number
    }
};
