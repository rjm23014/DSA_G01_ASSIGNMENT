// Problem: Mst Prim.Html
// Link: https://cp-algorithms.com/graph/mst_prim.html

#include <vector>
#include <queue>
#include <limits>
using namespace std;

// Minimum Spanning Tree - Prim's Algorithm
// Problem: Given a connected, undirected, weighted graph, find its MST using Prim's algorithm

// Approach 1 - Brute Force: Array-based Prim
// Update key and parent arrays by scanning all vertices at each step
// Time Complexity: O(V^2)
// Space Complexity: O(V)

class Solution {
public:
    // Returns the sum of MST edges. graph is adjacency matrix.
    int primMST(const vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> key(V, numeric_limits<int>::max());
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);
        key[0] = 0;

        for (int count = 0; count < V; ++count) {
            int u = -1;
            for (int v = 0; v < V; ++v) { // Find minimum key vertex
                if (!inMST[v] && (u == -1 || key[v] < key[u]))
                    u = v;
            }
            if (u == -1) break; // No MST (unconnected graph)
            inMST[u] = true;

            for (int v = 0; v < V; ++v) { // Update adjacent vertices
                if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        int mstWeight = 0;
        for (int i = 1; i < V; ++i) mstWeight += graph[i][parent[i]];
        return mstWeight;
    }
};

// Approach 2 - Optimized: Min-Heap (priority queue)
// Select the lightest edge using a priority queue
// Time Complexity: O(E log V) with adjacency list, O(V^2 log V) with matrix
// Space Complexity: O(V)

class Solution {
public:
    int primMST(const vector<vector<int>>& graph) {
        int V = graph.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> key(V, numeric_limits<int>::max());
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);
        pq.push({0, 0});
        key[0] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if (inMST[u]) continue;
            inMST[u] = true;

            for (int v = 0; v < V; ++v) {
                if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                    pq.push({key[v], v});
                }
            }
        }

        int mstWeight = 0;
        for (int i = 1; i < V; ++i) mstWeight += graph[i][parent[i]];
        return mstWeight;
    }
};
