// Problem: Top View Of Binary Tree
// Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

// Top View Of Binary Tree
// Problem: Print the set of nodes visible when a binary tree is viewed from the top.

// Approach 1 - Brute Force:
// Use DFS to traverse the tree and store nodes by their horizontal distance from the root.
// Time Complexity: O(n * log n) due to sorting HDs
// Space Complexity: O(n) for storing nodes

class Solution {
public:
    vector<int> topView(Node* root) {
        if (!root) return {};

        vector<int> result;
        map<int, int> hdMap;

        dfs(root, 0, hdMap);
        
        for (auto& hd : hdMap) {
            result.push_back(hd.second);
        }

        return result;
    }

    void dfs(Node* node, int hd, map<int, int>& hdMap) {
        if (!node) return;

        if (hdMap.find(hd) == hdMap.end()) {
            // Store the first encountered node at each HD
            hdMap[hd] = node->data;
        }

        dfs(node->left, hd - 1, hdMap);
        dfs(node->right, hd + 1, hdMap);
    }
};

// Approach 2 - Optimized:
// Use BFS to traverse the tree level by level and store nodes by their horizontal distance from the root.
// Time Complexity: O(n)
// Space Complexity: O(n) for storing nodes

class Solution {
public:
    vector<int> topView(Node* root) {
        if (!root) return {};

        map<int, int> hdMap;
        queue<pair<Node*, int>> q;

        q.push({root, 0}); // Node and its HD

        while (!q.empty()) {
            auto [node, hd] = q.front(); q.pop();

            if (hdMap.find(hd) == hdMap.end()) {
                // Store the first encountered node at each HD
                hdMap[hd] = node->data;
            }

            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        vector<int> result;
        for (auto& hd : hdMap) {
            result.push_back(hd.second);
        }
        sort(result.begin(), result.end(), [](int a, int b) {
            // Sort based on HD
            auto itA = find_if(hdMap.begin(), hdMap.end(), [&](auto& p){ return p.second == a; });
            auto itB = find_if(hdMap.begin(), hdMap.end(), [&](auto& p){ return p.second == b; });
            return itA->first < itB->first;
        });

        return result; // Note: Sorting is not necessary if map is ordered by key
    }
};
