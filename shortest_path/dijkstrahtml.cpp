// Problem: Dijkstra.Html
// Link: https://cp-algorithms.com/graph/dijkstra.html

#include <vector>
#include <iostream>
#include <limits>
#include <queue>

using namespace std;

// Problem: Implement Dijkstra's algorithm to find the shortest path from a source node to all other nodes in a graph.
// Given: A graph represented as an adjacency list, and a source node.

// Approach 1 - Brute Force ( Yen's k-Shortest Paths for simplicity):
// Brute Force methods are not typically used for Dijkstra's algorithm due to their inefficiency.
// Instead, a direct implementation of Dijkstra's with a simple loop is provided here as "Brute Force" for demonstration.
// Time Complexity: O(|E|*|V|) without optimization, where |E| is the number of edges and |V| is the number of vertices.
// Space Complexity: O(|V| + |E|) for storing distances and previous nodes.

class Solution {
public:
    vector<int> dijkstraBrute(vector<vector<pair<int, int>>>& graph, int source) {
        int n = graph.size();
        vector<int> distances(n, numeric_limits<int>::max());
        distances[source] = 0;

        // Iterate |V| times to ensure all nodes are visited and distances updated.
        for (int i = 0; i < n; ++i) {
            for (int u = 0; u < n; ++u) {
                for (auto& edge : graph[u]) {
                    int v = edge.first;
                    int weight = edge.second;
                    if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                        distances[v] = distances[u] + weight;
                    }
                }
            }
        }

        return distances;
    }
};

// Approach 2 - Optimized (Using Priority Queue for efficient node selection):
// Uses a priority queue to select the node with the smallest distance, reducing time complexity.
// Time Complexity: O(|E|log|V|) using a priority queue, where |E| is the number of edges and |V| is the number of vertices.
// Space Complexity: O(|V| + |E|) for storing distances and previous nodes.

class SolutionOptimized {
public:
    vector<int> dijkstraOptimized(vector<vector<pair<int, int>>>& graph, int source) {
        int n = graph.size();
        vector<int> distances(n, numeric_limits<int>::max());
        distances[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {distance, node}
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            for (auto& edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (d + weight < distances[v]) {
                    distances[v] = d + weight;
                    pq.push({distances[v], v});
                }
            }
        }

        return distances;
    }
};
