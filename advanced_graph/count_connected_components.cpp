// Problem: Count Connected Components
// Link: https://neetcode.io/problems/count-connected-components

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

// Problem: Count Connected Components
// Problem: Given the edges of an undirected graph, count the number of connected components.

// Approach 1 - Brute Force: DFS
// Utilize DFS to traverse the graph and count connected components.
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution_Brute {
    public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // Initialize adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Initialize visited array
        vector<bool> visited(n, false);
        
        // Function to perform DFS traversal
        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor);
                }
            }
        };
        
        // Count connected components
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i);
                count++;
            }
        }
        
        return count;
    }
};

// Approach 2 - Optimized: Union-Find
// Use the Union-Find algorithm to efficiently count connected components.
// Time Complexity: O(n + E * α(n)), where α(n) is the inverse Ackermann function which grows very slowly
// Space Complexity: O(n)

class UnionFind {
    public:
    vector<int> parent, rank;
    
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // Initialize parent of each node to itself
        }
    }
    
    // Find the root parent of a node
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    // Union two nodes into one group
    void union_(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution_Optimized {
    public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (auto& edge : edges) {
            uf.union_(edge[0], edge[1]);
        }
        
        // Count distinct roots
        unordered_set<int> roots;
        for (int i = 0; i < n; ++i) {
            roots.insert(uf.find(i));
        }
        
        return roots.size();
    }
};
