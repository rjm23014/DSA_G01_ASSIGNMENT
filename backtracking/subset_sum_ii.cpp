// Problem: Subset Sum Ii
// Link: https://www.geeksforgeeks.org/problems/subset-sum-ii/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <vector>
#include <algorithm>
using namespace std;

// Subset Sum II
// Problem: Given an integer array nums that may contain duplicates, return all possible subsets (the power set) without duplicate subsets.

// Approach 1 - Brute Force:
// Generates all subsets, then filters out duplicates.
// Time Complexity: O(2^n), exponential time due to power set generation.
// Space Complexity: O(n), for recursion stack.

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        vector<vector<int>> result;
        vector<int> currentSet;
        
        // Function to generate all possible subsets
        function<void(int)> generateSubsets = [&](int index) {
            result.push_back(currentSet); // Add current subset
            for (int i = index; i < nums.size(); ++i) {
                // Skip duplicates
                if (i > index && nums[i] == nums[i - 1]) continue;
                currentSet.push_back(nums[i]); // Add element to current subset
                generateSubsets(i + 1); // Recurse to next index
                currentSet.pop_back(); // Backtrack
            }
        };
        
        generateSubsets(0); // Start generating subsets from index 0
        return result;
    }
};

// Approach 2 - Optimized:
// Uses iterative approach to generate subsets without recursion.
// Time Complexity: O(2^n), still exponential but avoids recursion overhead.
// Space Complexity: O(n), for storing current subset.

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result = {{}}; // Initialize with empty subset
        
        for (int i = 0; i < nums.size(); ++i) {
            int count = 0; // Count of same elements
            while (i + count < nums.size() && nums[i + count] == nums[i]) ++count;
            
            int size = result.size();
            for (int j = 0; j < size; ++j) {
                vector<int> subset = result[j];
                for (int k = 1; k <= count; ++k) {
                    subset.push_back(nums[i]); // Add element
                    result.push_back(subset); // Add new subset
                    subset.pop_back(); // Backtrack
                }
            }
            i += count - 1; // Skip duplicates
        }
        
        return result;
    }
};
