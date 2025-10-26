// Problem: Is Binary Tree Heap
// Link: https://www.geeksforgeeks.org/problems/is-binary-tree-heap/0

#include <vector>
#include <iostream>
#include <climits>

// Is Binary Tree Heap
// Problem: Determine if a given binary tree is a max heap.

// Approach 1 - Brute Force:
// Check if the binary tree is complete and satisfies the heap property.
// Time Complexity: O(N)
// Space Complexity: O(H), where H is the height of the tree

class Solution {
    public:
    bool isCompleteTree(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);
        bool flag = false; // Flag to indicate if we encountered a non-full level

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                if (flag) return false; // Node has a left child after a non-full level
                q.push(node->left);
            } else {
                flag = true; // Mark as non-full level
            }

            if (node->right) {
                if (flag) return false; // Node has a right child after a non-full level
                q.push(node->right);
            } else {
                flag = true; // Mark as non-full level
            }
        }
        return true;
    }

    bool isMaxHeap(TreeNode* root) {
        if (!root) return true; // Empty tree is a heap

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                if (node->left->val > node->val) return false; // Heap property violated
                q.push(node->left);
            }
            if (node->right) {
                if (node->right->val > node->val) return false; // Heap property violated
                q.push(node->right);
            }
        }
        return true;
    }

    bool isCompleteTreeAndMaxHeap(TreeNode* root) {
        return isCompleteTree(root) && isMaxHeap(root);
    }
};

// Approach 2 - Optimized:
// Recursively check if the binary tree is complete and a max heap.
// Time Complexity: O(N)
// Space Complexity: O(H), where H is the height of the tree

class SolutionOptimized {
    public:
    bool isComplete(TreeNode* node, int i, int n) {
        if (!node) return true; // Empty nodes are considered complete
        if (i >= n) return false; // Node exists beyond the expected number of nodes

        return isComplete(node->left, 2 * i + 1, n) && isComplete(node->right, 2 * i + 2, n);
    }

    bool isMaxHeap(TreeNode* node, int minVal = INT_MIN) {
        if (!node) return true; // Base case

        if (node->val < minVal) return false; // Heap property violated

        return isMaxHeap(node->left, node->val) && isMaxHeap(node->right, node->val);
    }

    long countNodes(TreeNode* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    bool isCompleteTreeAndMaxHeap(TreeNode* root) {
        int n = countNodes(root);
        return isComplete(root, 0, n) && isMaxHeap(root);
    }
};
