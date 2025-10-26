// Problem: Maximum Depth Of Binary Tree
// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <vector>
#include <algorithm>
using namespace std;

// Maximum Depth of Binary Tree
// Problem: Find the number of nodes along the longest path from the root to the farthest leaf.

// Approach 1 - Brute Force: Recursive DFS (depth-first search)
// Recursively traverse the tree, compute depth for each subtree, and return the maximum.
// Time Complexity: O(n)  Each node is visited once
// Space Complexity: O(h) where h is the tree height, due to call stack (O(n) worst-case for skewed tree)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return 1 + max(l, r); // 1 for current node + max of left/right subtrees[1]
    }
};

// Approach 2 - Optimized: Iterative BFS (level order traversal)
// Traverse the tree level by level and count the number of levels.
// Time Complexity: O(n)
// Space Complexity: O(n) (width of the tree at the deepest level)

#include <queue>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            depth++;
        }
        return depth;
    }
};
