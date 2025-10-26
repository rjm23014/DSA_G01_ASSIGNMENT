// Problem: Two Sum
// Link: https://leetcode.com/problems/two-sum/

#include <vector>
#include <unordered_map>

using namespace std;

// Two Sum
// Problem: Given an array of integers and a target value, find indices of two integers that sum up to the target.

// Approach 1 - Brute Force:
// Brief: Check every possible pair of numbers in the array.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j}; // Return indices of the pair
                }
            }
        }
        // If no solution exists, throw or return an empty vector
        throw runtime_error("No two sum solution");
    }
};

// Approach 2 - Optimized:
// Brief: Use a hash map to store numbers and their indices.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            // Check if complement is already in the map
            if (numToIndex.count(complement)) {
                return {numToIndex[complement], i};
            }
            // Store the current number and its index
            numToIndex[nums[i]] = i;
        }
        // If no solution exists, throw or return an empty vector
        throw runtime_error("No two sum solution");
    }
};
