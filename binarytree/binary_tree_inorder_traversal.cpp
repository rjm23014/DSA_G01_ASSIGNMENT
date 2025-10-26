// Problem: Binary Tree Inorder Traversal
// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <vector>
#include <stack>
using namespace std;

// Binary Tree Inorder Traversal
// Problem: Given the root of a binary tree, return the inorder traversal of its nodes' values.

// Approach 1 - Brute Force:
// Recursive inorder traversal: traverse left subtree, visit root, traverse right subtree
// Time Complexity: O(n), where n is the number of nodes (each node visited once)
// Space Complexity: O(h) due to recursion stack, where h is the tree height

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
private:
    void inorder(TreeNode* node, vector<int>& res) {
        if (!node) return;
        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }
};

// Approach 2 - Optimized:
// Iterative inorder traversal using a stack to simulate recursion, avoids potential call stack overflow
// Time Complexity: O(n), visits each node once
// Space Complexity: O(h), stack holds at most h nodes at any time, h = tree height

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (curr != nullptr || !stk.empty()) {
            // Reach the leftmost node
            while (curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            res.push_back(curr->val);
            // Visit right subtree
            curr = curr->right;
        }
        return res;
    }
};
