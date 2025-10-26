// Problem: Same Tree
// Link: https://leetcode.com/problems/same-tree/

#include <stack>
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
using namespace std;

// Same Tree
// Problem: Check if two binary trees are identical in structure and node values.

// Approach 1 - Brute Force:
// Recursive comparison of node values and subtrees.
// Time Complexity: O(n) where n is the number of nodes in trees.
// Space Complexity: O(h) due to recursion stack, h is tree height.

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;            // both null
        if (!p || !q) return false;           // one null
        if (p->val != q->val) return false;  // value mismatch
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Approach 2 - Optimized:
// Iterative using stacks to avoid recursion overhead.
// Time Complexity: O(n)
// Space Complexity: O(h), h is tree height (stack space).

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stackP, stackQ;
        stackP.push(p);
        stackQ.push(q);
        while (!stackP.empty() && !stackQ.empty()) {
            TreeNode* nodeP = stackP.top(); stackP.pop();
            TreeNode* nodeQ = stackQ.top(); stackQ.pop();
            if (!nodeP && !nodeQ) continue;
            if (!nodeP || !nodeQ) return false;
            if (nodeP->val != nodeQ->val) return false;
            stackP.push(nodeP->right);
            stackP.push(nodeP->left);
            stackQ.push(nodeQ->right);
            stackQ.push(nodeQ->left);
        }
        return stackP.empty() && stackQ.empty();
    }
};
