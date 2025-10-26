// Problem: Diameter Of Binary Tree
// Link: https://leetcode.com/problems/diameter-of-binary-tree/

#include <algorithm>
#include <cstddef>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Diameter Of Binary Tree
// Problem: Find the length of the longest path between any two nodes in a binary tree.

// Approach 1 - Brute Force:
// Compute height of left and right subtree for every node separately to find diameter through that node.
// Time Complexity: O(n^2) due to repeated height calculations.
// Space Complexity: O(h) for recursion stack, h is tree height.

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diameterThroughRoot = leftHeight + rightHeight;
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        return max(diameterThroughRoot, max(leftDiameter, rightDiameter));
    }

private:
    int height(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
};

// Approach 2 - Optimized:
// Use DFS to calculate height and update diameter simultaneously in one traversal.
// Time Complexity: O(n), each node visited once.
// Space Complexity: O(h), recursion stack space where h is tree height.

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        dfsHeight(root);
        return maxDiameter;
    }

private:
    int maxDiameter;

    int dfsHeight(TreeNode* node) {
        if (!node) return 0;
        int leftHeight = dfsHeight(node->left);
        int rightHeight = dfsHeight(node->right);
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
};
