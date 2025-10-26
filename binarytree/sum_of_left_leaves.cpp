// Problem: Sum Of Left Leaves
// Link: https://leetcode.com/problems/sum-of-left-leaves/

#include <vector>
#include <stack>
using namespace std;

// 404. Sum Of Left Leaves
// Problem: Find the sum of all left leaves in a given binary tree.

// Approach 1 - Brute Force: DFS recursion, checking each node
// For each node, check if its left child is a left leaf and accumulate sum.
// Time Complexity: O(n)
// Space Complexity: O(h) (recursion stack, worst case O(n))

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        // If left child exists and is a leaf, add it
        if (root->left && !root->left->left && !root->left->right)
            sum += root->left->val;
        else
            sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};

// Approach 2 - Optimized: Iterative DFS using stack
// Stack-based DFS to mimic recursion, checking left leaves on the fly
// Time Complexity: O(n)
// Space Complexity: O(h) (stack, worst case O(n))

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        stack<pair<TreeNode*, bool>> stk; // node, is_left_child
        stk.emplace(root, false);
        int sum = 0;
        while (!stk.empty()) {
            auto [node, is_left] = stk.top();
            stk.pop();
            // If current node is a left leaf, add value
            if (is_left && !node->left && !node->right)
                sum += node->val;
            if (node->right) stk.emplace(node->right, false);
            if (node->left) stk.emplace(node->left, true);
        }
        return sum;
    }
};
