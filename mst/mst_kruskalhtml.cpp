// Problem: Mst Kruskal.Html
// Link: https://cp-algorithms.com/graph/mst_kruskal.html

#include <vector>
#include <algorithm>
using namespace std;

// MST Kruskal.Html
// Problem: Find the Minimum Spanning Tree (MST) edges in a weighted, undirected graph using Kruskal's algorithm.

// Approach 1 - Brute Force:
// Sort edges by weight, iterate each edge and check cycle by scanning visited sets naively.
// Time Complexity: O(E * V) due to cycle detection by simple inspection
// Space Complexity: O(V+E)

class Solution {
public:
    struct Edge {
        int u, v, w;
    };
    
    // Naive cycle detection: DFS or Union-Find is not used in brute force, here we simulate checking connectivity by DFS
    bool createsCycle(int u, int v, vector<vector<int>>& adj, vector<bool>& visited) {
        if (u == v) return true;
        visited[u] = true;
        for (auto nbr : adj[u]) {
            if (!visited[nbr]) {
                if (createsCycle(nbr, v, adj, visited))
                    return true;
            }
        }
        return false;
    }
    
    vector<Edge> kruskal(int V, vector<Edge>& edges) {
        // Sort edges by weight ascending
        sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) { return a.w < b.w; });
        
        vector<vector<int>> adj(V);
        vector<Edge> mst;
        
        for (auto& e : edges) {
            vector<bool> visited(V, false);
            // Check if adding edge e creates a cycle
            if (!createsCycle(e.u, e.v, adj, visited)) {
                mst.push_back(e);
                adj[e.u].push_back(e.v);
                adj[e.v].push_back(e.u);
                if ((int)mst.size() == V - 1) break;
            }
        }
        return mst;
    }
};

// Approach 2 - Optimized:
// Use Union-Find (Disjoint Set Union) for cycle detection, sorting edges once by weight and union-find methods.
// Time Complexity: O(E log E) due to sorting edges and near O(1) amortized union/find operations.
// Space Complexity: O(V + E) for edges and DSU structures.

class Solution {
    struct Edge {
        int u, v, w;
        bool operator<(const Edge& other) const {
            return w < other.w;
        }
    };
    
    struct DSU {
        vector<int> parent, size;
        DSU(int n): parent(n), size(n,1) {
            for (int i = 0; i < n; ++i) parent[i] = i;
        }
        int find(int a) {
            while (a != parent[a]) {
                parent[a] = parent[parent[a]]; // path compression
                a = parent[a];
            }
            return a;
        }
        bool unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return false;
            if (size[a] < size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
    };
    
public:
    vector<Edge> kruskal(int V, vector<Edge>& edges) {
        sort(edges.begin(), edges.end()); // sort edges by weight ascending
        DSU dsu(V);
        vector<Edge> mst;
        
        for (auto& e : edges) {
            if (dsu.unite(e.u, e.v)) {
                mst.push_back(e);
                if ((int)mst.size() == V - 1) break;
            }
        }
        return mst;
    }
};
