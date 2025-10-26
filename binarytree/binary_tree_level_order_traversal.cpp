// Problem: Binary Tree Level Order Traversal
// Link: https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <vector>
#include <queue>

using namespace std;

// Binary Tree Level Order Traversal
// Problem: Traverse a binary tree level by level from left to right.

// Approach 1 - Brute Force (Recursive):
// Brief Explanation: This approach involves recursively traversing the tree level by level.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        traverse(result, root, 0);
        return result;
    }
    
    void traverse(vector<vector<int>>& result, TreeNode* node, int level) {
        if (node == nullptr) return;
        
        if (result.size() <= level) {
            result.push_back(vector<int>());
        }
        result[level].push_back(node->val);
        
        traverse(result, node->left, level + 1);
        traverse(result, node->right, level + 1);
    }
};

// Approach 2 - Optimized (Iterative):
// Brief Explanation: This approach uses a queue for efficient level order traversal.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelNodes;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelNodes.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(levelNodes);
        }
        
        return result;
    }
};
