// Problem: Bfs Traversal Of Graph
// Link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <vector>
#include <queue>
using namespace std;

// BFS Traversal Of Graph
// Problem: Given a graph, perform a breadth-first search (BFS) traversal visiting all vertices in the graph.

// Approach 1 - Brute Force:
// Perform BFS starting from each unvisited vertex to ensure traversal of all disconnected components.
// Time Complexity: O(V + E) where V is vertices and E is edges
// Space Complexity: O(V) for visited array and queue

class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfsTraversal;
        vector<bool> visited(V, false);

        // Run BFS for all disconnected components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    bfsTraversal.push_back(node);

                    for (auto neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }

        return bfsTraversal;
    }
};

// Approach 2 - Optimized:
// Since problem usually expects BFS starting from node 0 (as per problem statement on GfG),
// we can run BFS starting only from node 0 assuming connected graph or that we only need traversal from 0.
// Time Complexity: O(V + E)
// Space Complexity: O(V)

class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfsTraversal;
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfsTraversal.push_back(node);

            for (auto neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return bfsTraversal;
    }
};
