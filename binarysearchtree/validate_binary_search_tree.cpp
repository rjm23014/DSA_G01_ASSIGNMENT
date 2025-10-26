// Problem: Validate Binary Search Tree
// Link: https://leetcode.com/problems/validate-binary-search-tree/

#include <climits>
#include <vector>
using namespace std;

// Validate Binary Search Tree
// Problem: Determine if a binary tree is a valid BST where left subtree < node < right subtree.

// Approach 1 - Brute Force:
// Inorder traversal to collect node values in a vector, then check if sorted strictly ascending.
// Time Complexity: O(n) (traversal + verification)
// Space Complexity: O(n) (for storing values)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    vector<int> vals;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        vals.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        vals.clear();
        inorder(root);
        for (int i = 1; i < (int)vals.size(); ++i) {
            if (vals[i] <= vals[i - 1]) return false;
        }
        return true;
    }
};

// Approach 2 - Optimized:
// Recursively validate each node with min and max allowed value constraints, narrowing the range.
// Time Complexity: O(n) (each node visited once)
// Space Complexity: O(h) (due to recursion stack, h = tree height)

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
private:
    bool helper(TreeNode* node, long long low, long long high) {
        if (!node) return true;
        if (node->val <= low || node->val >= high) return false;
        return helper(node->left, low, node->val) && helper(node->right, node->val, high);
    }
};
