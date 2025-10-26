// Problem: Combination Sum Ii
// Link: https://leetcode.com/problems/combination-sum-ii/description/

#include <vector>
#include <algorithm>
using namespace std;

// Combination Sum II
// Problem: Find all unique combinations in candidates where numbers sum to target, each number used once.

// Approach 1 - Brute Force:
// Use backtracking without sorting or pruning duplicates. Explore all subsets and add those that sum to target.
// Time Complexity: O(2^n * n) - generate all subsets and copy combinations
// Space Complexity: O(n) - recursion stack and temp combination array

class Solution {
public:
    void backtrack(int index, int target, vector<int>& candidates, vector<int>& combo, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(combo);
            return;
        }
        if (target < 0 || index == (int)candidates.size()) return;
        // Choose current element
        combo.push_back(candidates[index]);
        backtrack(index + 1, target - candidates[index], candidates, combo, res);
        combo.pop_back();
        // Skip current element
        backtrack(index + 1, target, candidates, combo, res);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combo;
        backtrack(0, target, candidates, combo, res);
        // The brute force approach will have duplicates since no sorting or pruning is done,
        // duplicates can be removed afterward if needed but this violates "clean" brute force.
        return res;
    }
};

// Approach 2 - Optimized:
// Sort candidates and use backtracking with pruning duplicates by skipping repeated values at the same recursion level.
// Only explore candidates that do not exceed the remaining target.
// Time Complexity: O(n * 2^n) in worst case due to exploration of subsets, pruning reduces actual runtime
// Space Complexity: O(n) recursion stack and temporary combination

class Solution {
public:
    void backtrack(int start, int target, const vector<int>& candidates, vector<int>& combo, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(combo);
            return;
        }
        for (int i = start; i < (int)candidates.size(); ++i) {
            if (candidates[i] > target) break; // early stopping since candidates are sorted
            if (i > start && candidates[i] == candidates[i - 1]) continue; // skip duplicates
            combo.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates, combo, res);
            combo.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combo;
        backtrack(0, target, candidates, combo, res);
        return res;
    }
};
