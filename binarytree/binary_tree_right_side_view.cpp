// Problem: Binary Tree Right Side View
// Link: https://leetcode.com/problems/binary-tree-right-side-view/

#include <vector>
#include <queue>
using namespace std;

// Binary Tree Right Side View
// Problem: Return the values of the nodes visible from the right side of a binary tree.

// Approach 1 - Brute Force:
// Level order traversal (BFS) to process nodes level by level,
// append the last node's value of each level to result.
// Time Complexity: O(N) - each node visited once
// Space Complexity: O(N) - queue storage for worst case (complete binary tree)

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (i == levelSize - 1) res.push_back(node->val); // rightmost node of current level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};

// Approach 2 - Optimized:
// Use DFS (preorder traversal) prioritizing right subtree.
// Track current depth and add the first node visited at each depth.
// This ensures the rightmost node at each depth is recorded.
// Time Complexity: O(N) - visits each node once
// Space Complexity: O(H) - recursion stack, where H is tree height

class Solution {
public:
    vector<int> res;
    
    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        if (depth == (int)res.size()) res.push_back(node->val);
        dfs(node->right, depth + 1);
        dfs(node->left, depth + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        res.clear();
        dfs(root, 0);
        return res;
    }
};
