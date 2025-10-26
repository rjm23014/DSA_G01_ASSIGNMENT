// Problem: Create Binary Tree From Descriptions
// Link: https://leetcode.com/problems/create-binary-tree-from-descriptions/description/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;

// Create Binary Tree From Descriptions
// Problem: Given parent-child relationships with left/right info, build the binary tree and return its root.

// Approach 1 - Brute Force:
// Use a map to create TreeNodes for all values encountered and link children accordingly.
// Identify root as the node that never appears as a child.
// Time Complexity: O(n) - process each description once
// Space Complexity: O(n) - storing all nodes and auxiliary data structures

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        for (auto& d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            if (nodes.find(parent) == nodes.end())
                nodes[parent] = new TreeNode(parent);
            if (nodes.find(child) == nodes.end())
                nodes[child] = new TreeNode(child);
            if (isLeft == 1)
                nodes[parent]->left = nodes[child];
            else
                nodes[parent]->right = nodes[child];
            children.insert(child);
        }
        // root is the one that never appears as a child
        for (auto& d : descriptions) {
            if (children.find(d[0]) == children.end())
                return nodes[d[0]];
        }
        return nullptr; // problem guarantees valid tree, shouldn't reach here
    }
};

// Approach 2 - Optimized:
// Similar to Approach 1 but uses a single pass and a helper function with caching children info.
// Uses unordered_map<int, pair<int,int>> to store left and right child for each node for concise representation.
// Builds tree recursively once root is found.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> hasParent;
        unordered_map<int, pair<int, int>> children; // parent -> (leftChild, rightChild)
        for (auto& d : descriptions) {
            hasParent.insert(d[1]);
            if (d[2] == 1)
                children[d[0]].first = d[1];
            else
                children[d[0]].second = d[1];
        }
        int rootVal = -1;
        for (auto& d : descriptions) {
            if (hasParent.find(d[0]) == hasParent.end()) {
                rootVal = d[0];
                break;
            }
        }
        function<TreeNode*(int)> build = [&](int val) -> TreeNode* {
            if (val == 0) return nullptr;
            TreeNode* node = new TreeNode(val);
            auto it = children.find(val);
            if (it != children.end()) {
                node->left = build(it->second.first);
                node->right = build(it->second.second);
            }
            return node;
        };
        return build(rootVal);
    }
};
