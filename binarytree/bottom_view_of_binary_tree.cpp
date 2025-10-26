// Problem: Bottom View Of Binary Tree
// Link: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

#include <vector>
#include <queue>
#include <map>
#include <utility>

using namespace std;

// Bottom View of Binary Tree
// Problem: Find the bottom view of a binary tree by returning the values of nodes at the bottom level from left to right.

// Approach 1 - Brute Force (Preorder Traversal):
// Brief explanation: This approach involves a preorder traversal to calculate the level and horizontal distance of each node.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> bottomView(TreeNode* root) {
        if (!root) return {};
        
        vector<int> result;
        map<int, int> map;
        queue<pair<TreeNode*, pair<int, int>>> q; // (node, <level, hd>)
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto node = q.front().first;
            auto [level, hd] = q.front().second;
            q.pop();
            
            if (node) {
                // Update the map with the last encountered node at each hd
                map[hd] = node->val;
                
                // Add children to the queue
                q.push({node->left, {level + 1, hd - 1}});
                q.push({node->right, {level + 1, hd + 1}});
            }
        }
        
        // Traverse the map to get the bottom view in order
        for (auto& [key, val] : map) {
            result.push_back(val);
        }
        
        return result;
    }
};

// Approach 2 - Optimized (Level Order Traversal):
// Brief explanation: Utilize a map to store the bottommost node at each horizontal distance.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> bottomView(TreeNode* root) {
        if (!root) return {};
        
        vector<int> result;
        map<int, int> map;
        queue<pair<TreeNode*, int>> q; // (node, hd)
        q.push({root, 0});
        
        while (!q.empty()) {
            auto node = q.front().first;
            auto hd = q.front().second;
            q.pop();
            
            if (node) {
                // Update the map with the last encountered node at each hd
                map[hd] = node->val;
                
                // Add children to the queue
                q.push({node->left, hd - 1});
                q.push({node->right, hd + 1});
            }
        }
        
        // Traverse the map to get the bottom view in order
        for (auto& [key, val] : map) {
            result.push_back(val);
        }
        
        return result;
    }
};
