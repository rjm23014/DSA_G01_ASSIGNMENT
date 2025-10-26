// Problem: Binary Tree Preorder Traversal
// Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

#include <vector>
#include <stack>
using namespace std;

// Binary Tree Preorder Traversal
// Problem: Given the root of a binary tree, return the preorder traversal of its nodes' values.

// Approach 1 - Brute Force (Recursive):
// Time Complexity: O(N)
// Space Complexity: O(N), where N is the number of nodes in the tree

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }
    
    void preorderHelper(TreeNode* node, vector<int>& result) {
        if (!node) return;
        // Visit the root node
        result.push_back(node->val);
        // Traverse the left subtree
        preorderHelper(node->left, result);
        // Traverse the right subtree
        preorderHelper(node->right, result);
    }
};

// Approach 2 - Optimized (Iterative):
// Time Complexity: O(N)
// Space Complexity: O(N), where N is the number of nodes in the tree

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        if (root) stk.push(root);
        
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            // Visit the node
            result.push_back(node->val);
            
            // Push right child first so it's visited last
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }
        return result;
    }
};
