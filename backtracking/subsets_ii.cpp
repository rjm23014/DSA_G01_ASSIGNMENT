// Problem: Subsets Ii
// Link: https://leetcode.com/problems/subsets-ii/description/

#include <vector>
#include <algorithm>
using namespace std;

// Subsets II
// Problem: Given array nums (may have duplicates), return all subsets, avoiding duplicates in the solution set.

// Approach 1 - Brute Force (Generate all, sort, and deduplicate)
// Generates all subsets, sorts to group duplicates, then removes them.
// Time Complexity: O(n * 2^n * log(2^n)) — Each subset copy and sort dominates
// Space Complexity: O(n * 2^n)

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result{{}};
        for (int i = 0; i < nums.size(); ) {
            int value = nums[i];
            int count = 0;
            // Count duplicates
            while (i < nums.size() && nums[i] == value) {
                i++;
                count++;
            }
            int result_size = result.size();
            // Add subsets for each possible count of duplicates
            for (int k = 0; k < result_size; ++k) {
                vector<int> original = result[k];
                for (int c = 1; c <= count; ++c) {
                    original.push_back(value);
                    result.push_back(original);
                }
            }
        }
        return result;
    }
};

// Approach 2 - Optimized (Backtracking with duplicate handling)
// Uses DFS to build subsets, skips duplicate elements to avoid duplicate subsets.
// Time Complexity: O(n * 2^n) — Each subset is generated in O(1) amortized time
// Space Complexity: O(n * 2^n)

class Solution {
    void dfs(vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& result) {
        result.push_back(path);
        for (int i = index; i < nums.size(); ++i) {
            // Skip duplicates — critical for avoiding duplicate subsets
            if (i > index && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            dfs(nums, i + 1, path, result);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> result;
        dfs(nums, 0, path, result);
        return result;
    }
};
