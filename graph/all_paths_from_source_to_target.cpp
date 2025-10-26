// Problem: All Paths From Source To Target
// Link: https://leetcode.com/problems/all-paths-from-source-to-target/description/

#include <vector>
using namespace std;

// All Paths From Source To Target
// Problem: Given a DAG represented as adjacency lists, find all paths from node 0 to node n-1.

// Approach 1 - Brute Force:
// Simple DFS/backtracking with recursive path exploration, storing all paths when target is reached.
// Time Complexity: O(n * 2^n) - exponential due to potentially all paths explored in DAG
// Space Complexity: O(n * 2^n) - result storage + recursion stack

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path = {0};
        dfs(graph, 0, path, res);
        return res;
    }
private:
    void dfs(const vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& res) {
        if (node == (int)graph.size() - 1) {
            res.push_back(path);
            return;
        }
        for (int nxt : graph[node]) {
            path.push_back(nxt);
            dfs(graph, nxt, path, res);
            path.pop_back();
        }
    }
};

// Approach 2 - Optimized:
// Same DFS/backtracking approach; optimization lies in avoiding unnecessary copies by using references and backtracking in-place.
// Time Complexity: O(n * 2^n) - all paths exploration remains the bottleneck
// Space Complexity: O(n * 2^n)

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> currentPath;
        currentPath.reserve(graph.size());
        backtrack(graph, 0, currentPath, result);
        return result;
    }
private:
    void backtrack(const vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& result) {
        path.push_back(node);
        if (node == (int)graph.size() - 1) {
            result.push_back(path);
        } else {
            for (int neighbor : graph[node])
                backtrack(graph, neighbor, path, result);
        }
        path.pop_back(); // backtrack
    }
};
