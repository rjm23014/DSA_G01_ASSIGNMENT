// Problem: Subsets
// Link: https://leetcode.com/problems/subsets/description/

#include <vector>
using namespace std;

// Subsets
// Problem: Given an array of distinct integers, return all possible subsets (the power set).

// Approach 1 - Brute Force:
// Use backtracking to explore all combinations by including or excluding each element.
// Time Complexity: O(2^n * n) — 2^n subsets, each copied up to n elements
// Space Complexity: O(2^n * n) — storing all subsets plus recursion stack

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
private:
    void backtrack(const vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }
        // Exclude nums[index]
        backtrack(nums, index + 1, current, result);
        // Include nums[index]
        current.push_back(nums[index]);
        backtrack(nums, index + 1, current, result);
        current.pop_back(); // backtrack
    }
};

// Approach 2 - Optimized:
// Use iterative approach: start with empty subset, for each num, add it to all existing subsets to form new subsets.
// Time Complexity: O(2^n * n) — same as brute force due to copying subsets
// Space Complexity: O(2^n * n) — for storing all subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        for (int num : nums) {
            int n = result.size();
            for (int i = 0; i < n; ++i) {
                vector<int> subset = result[i];
                subset.push_back(num);
                result.push_back(move(subset));
            }
        }
        return result;
    }
};
