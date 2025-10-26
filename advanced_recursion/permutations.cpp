// Problem: Permutations
// Link: https://leetcode.com/problems/permutations/description/

#include <vector>
#include <algorithm> // For next_permutation

using namespace std;

// Permutations
// Problem: Given an array nums of distinct integers, return all the possible permutations.

// Approach 1 - Brute Force by generating next permutation
// Generate permutations in lex order using std::next_permutation, requires original input to be sorted.
// Time Complexity: O(n! * n)
// Space Complexity: O(n! * n) to store all results, or O(n) with output excluded

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        // Start with sorted array for next_permutation
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
};

// Approach 2 - Optimized Backtracking
// Use backtracking with a visited array to generate all permutations recursively.
// Time Complexity: O(n! * n)
// Space Complexity: O(n! * n) to store all results, or O(n) depth of recursion stack

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm(nums.size());
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, perm, res, 0);
        return res;
    }

private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& perm, vector<vector<int>>& res, int idx) {
        if (idx == nums.size()) {
            res.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                perm[idx] = nums[i];
                backtrack(nums, used, perm, res, idx + 1);
                used[i] = false; // Backtrack
            }
        }
    }
};
