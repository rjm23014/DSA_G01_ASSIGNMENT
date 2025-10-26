// Problem: Find If Path Exists In Graph
// Link: https://leetcode.com/problems/find-if-path-exists-in-graph/description/

#include <vector>
#include <stack>
using namespace std;

// Find If Path Exists In Graph
// Problem: Given n vertices and edges, determine if a path exists between source and destination.

// Approach 1 - Brute Force:
// Use Depth First Search (DFS) to explore the graph from source, checking if destination is reachable.
// Time Complexity: O(n + e), where e is number of edges
// Space Complexity: O(n + e) for adjacency list and recursion stack

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return dfs(graph, source, destination, visited);
    }

private:
    bool dfs(const vector<vector<int>>& graph, int node, int destination, vector<bool>& visited) {
        if (node == destination) return true;
        visited[node] = true;
        for (int nei : graph[node]) {
            if (!visited[nei]) {
                if (dfs(graph, nei, destination, visited)) return true;
            }
        }
        return false;
    }
};

// Approach 2 - Optimized:
// Use Union-Find (Disjoint Set) to merge connected components and check if source and destination share the same representative.
// Time Complexity: O(e * α(n)), almost linear, where α(n) is inverse Ackermann function
// Space Complexity: O(n)

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void union_sets(int a, int b) {
        int rootA = find(a), rootB = find(b);
        if (rootA != rootB) {
            if (size[rootA] < size[rootB]) swap(rootA, rootB);
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);
        for (auto& edge : edges)
            ds.union_sets(edge[0], edge[1]);
        return ds.find(source) == ds.find(destination);
    }
};
