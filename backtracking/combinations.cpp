// Problem: Combinations
// Link: https://leetcode.com/problems/combinations/description/

#include <vector>
#include <utility>

using namespace std;

// Combinations
// Problem: Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// Approach 1 - Brute Force (Iterative):
// This approach is not efficient for large inputs. It generates all subsets of size k from the set of numbers [1, n].
// Time Complexity: O(2^n) - because we generate all subsets and check for size k.
// Space Complexity: O(2^n) - storing all subsets.

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Generate all subsets iteratively and check if size is k
        for (int mask = 0; mask < (1 << n); mask++) {
            current.clear();
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i))) {
                    current.push_back(i + 1); // Add 1 because numbers range from 1 to n
                }
            }
            if (current.size() == k) {
                result.push_back(current);
            }
        }
        
        return result;
    }
};

// Approach 2 - Optimized (Backtracking):
// This approach efficiently generates combinations by using backtracking to include or exclude numbers in the current combination.
// Time Complexity: O(C(n, k) * k) - generating all combinations and copying them into the result.
// Space Complexity: O(C(n, k)) - storing all combinations.

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        
        backtrack(1, n, k, current, result);
        
        return result;
    }
    
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        if (k == 0) {
            result.push_back(current); // Found a valid combination
            return;
        }
        
        for (int i = start; i <= n - k + 1; i++) {
            current.push_back(i);
            backtrack(i + 1, n, k - 1, current, result);
            current.pop_back(); // Backtrack
        }
    }
};
