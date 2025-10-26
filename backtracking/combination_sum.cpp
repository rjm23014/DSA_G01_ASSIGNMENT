// Problem: Combination Sum
// Link: https://leetcode.com/problems/combination-sum/description/

#include <vector>
#include <algorithm>
using namespace std;

// Combination Sum
// Problem: Find all unique combinations in candidates where chosen numbers sum to target. Numbers can be used unlimited times.

// Approach 1 - Brute Force:
// Use backtracking to explore all combinations without pruning beyond sum checks.
// Time Complexity: O(N^(target/min_element)) in worst case, N = candidates size
// Space Complexity: O(target/min_element) for recursion stack and path storage

class Solution {
public:
    vector<vector<int>> res;
    vector<int> current;

    void backtrack(const vector<int>& candidates, int target, int start) {
        if (target == 0) {
            res.push_back(current);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < (int)candidates.size(); i++) {
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i); // allow reuse of same element
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        current.clear();
        backtrack(candidates, target, 0);
        return res;
    }
};

// Approach 2 - Optimized:
// Sort candidates to stop early when sum exceeds target, reducing unnecessary recursion.
// Time Complexity: Still O(N^(target/min_element)) worst case but pruned branches improve average case.
// Space Complexity: O(target/min_element) recursion stack + output storage

class Solution {
public:
    vector<vector<int>> res;
    vector<int> current;

    void backtrack(const vector<int>& candidates, int target, int start) {
        if (target == 0) {
            res.push_back(current);
            return;
        }

        for (int i = start; i < (int)candidates.size() && candidates[i] <= target; i++) {
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        current.clear();
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return res;
    }
};
