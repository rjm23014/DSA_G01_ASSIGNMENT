// Problem: Subsets
// Link: https://leetcode.com/problems/subsets/description/

#include <vector>
using namespace std;

// Subsets
// Problem: Given an integer array of unique elements, return all possible subsets (the power set).

// Approach 1 - Brute Force: Generate all subsets iteratively by expanding the result at each step
// Time Complexity: O(n * 2^n) — n is the input size, 2^n subsets each copied in linear time
// Space Complexity: O(n * 2^n) — to store all subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}}; // Start with the empty subset
        for (int num : nums) {
            int n = ans.size();
            for (int i = 0; i < n; ++i) {
                vector<int> temp = ans[i]; // Copy each existing subset
                temp.push_back(num);       // Add current num to each subset
                ans.push_back(temp);       // Insert new subset into result
            }
        }
        return ans;
    }
};

// Approach 2 - Optimized: Recursive backtracking, exploring include/exclude choices per element
// Time Complexity: O(n * 2^n) — same as above, but explores all subsets via recursion
// Space Complexity: O(n * 2^n) — for the output; O(n) auxiliary for recursion stack

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(nums, 0, current, ans);
        return ans;
    }
private:
    void backtrack(vector<int>& nums, int idx, vector<int>& current, vector<vector<int>>& ans) {
        if (idx == nums.size()) {   // Base case: add the current subset
            ans.push_back(current);
            return;
        }
        backtrack(nums, idx + 1, current, ans);      // Exclude nums[idx]
        current.push_back(nums[idx]);                // Include nums[idx]
        backtrack(nums, idx + 1, current, ans);      // Proceed...
        current.pop_back();                          // Backtrack
    }
};
