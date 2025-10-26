// Problem: Path Sum
// Link: https://leetcode.com/problems/path-sum/

#include <iostream>
// No additional headers necessary for this problem
using namespace std;

// Path Sum
// Problem: Check if there exists a root-to-leaf path with sum equals targetSum

// Approach 1 - Brute Force:
// Recursively check all root-to-leaf paths by subtracting current node value from targetSum.
// Time Complexity: O(N) where N is number of nodes (each node visited once)
// Space Complexity: O(H) for recursion stack where H is tree height

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right) // leaf node
            return targetSum == root->val;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

// Approach 2 - Optimized:
// Same approach since brute force is optimal here.
// Optimize by short circuiting when path found in either subtree.
// Time Complexity: O(N)
// Space Complexity: O(H)

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right) 
            return targetSum == root->val;
        if (root->left && hasPathSum(root->left, targetSum - root->val))
            return true;
        if (root->right && hasPathSum(root->right, targetSum - root->val))
            return true;
        return false;
    }
};
