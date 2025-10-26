// Problem: Symmetric Tree
// Link: https://leetcode.com/problems/symmetric-tree/

#include <queue>
// Definition for a binary tree node is provided by LeetCode.
using namespace std;

// Symmetric Tree
// Problem: Check if a binary tree is symmetric around its center.

// Approach 1 - Brute Force:
// Recursively compare left and right subtrees to verify mirror equality.
// Time Complexity: O(n), where n is number of nodes (each node visited once)
// Space Complexity: O(h), h is the tree height due to recursion stack
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
private:
    bool isMirror(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return (p->val == q->val) 
            && isMirror(p->left, q->right) 
            && isMirror(p->right, q->left);
    }
};

// Approach 2 - Optimized:
// Use iterative approach with two queues to compare nodes level-wise.
// Time Complexity: O(n), each node visited once
// Space Complexity: O(n), for queues in worst case
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);

        while (!q1.empty() && !q2.empty()) {
            TreeNode* n1 = q1.front(); q1.pop();
            TreeNode* n2 = q2.front(); q2.pop();

            if (!n1 && !n2) continue;
            if (!n1 || !n2 || n1->val != n2->val) return false;

            // Push children in opposite order for symmetry check
            q1.push(n1->left);
            q2.push(n2->right);

            q1.push(n1->right);
            q2.push(n2->left);
        }
        return q1.empty() && q2.empty();
    }
};
