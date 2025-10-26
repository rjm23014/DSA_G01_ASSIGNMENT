// Problem: Unique Binary Search Trees
// Link: https://leetcode.com/problems/unique-binary-search-trees/description/

#include <vector>
using namespace std;

// Unique Binary Search Trees
// Problem: Given n, count the number of structurally unique BSTs with values 1 to n.

// Approach 1 - Brute Force:
// Recursively choose each value as root and multiply counts of left and right subtrees.
// Time Complexity: O(2^n) due to overlapping subproblems and recomputation.
// Space Complexity: O(n) for recursion stack.

class Solution {
public:
    int countTrees(int start, int end) {
        if (start > end) return 1; // Empty tree count as 1
        int total = 0;
        for (int root = start; root <= end; ++root) {
            int left = countTrees(start, root - 1);
            int right = countTrees(root + 1, end);
            total += left * right;
        }
        return total;
    }
    
    int numTrees(int n) {
        return countTrees(1, n);
    }
};

// Approach 2 - Optimized:
// Use DP to store number of unique BSTs for 0..i nodes. 
// For each i, number of trees is sum of dp[j-1]*dp[i-j] for j=1..i.
// Time Complexity: O(n^2) due to double loop.
// Space Complexity: O(n) for DP array.

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // One empty tree
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        
        return dp[n];
    }
};
