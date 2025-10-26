// Problem: Depth First Traversal For A Graph
// Link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <vector>
#include <unordered_map>
using namespace std;

// Depth First Traversal For A Graph
// Problem: Perform DFS on a graph represented as adjacency list, print visited vertices.

// Approach 1 - Brute Force (Recursive DFS)
// Traverse all vertices recursively, visiting deepest node first, using visited array.
// Time Complexity: O(V + E)
// Space Complexity: O(V) for recursion stack & visited array

class Solution {
public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;
        vector<bool> visited(V, false);
        dfs(0, adj, visited, result);  // Start from vertex 0
        return result;
    }

    void dfs(int u, vector<int> adj[], vector<bool>& visited, vector<int>& result) {
        visited[u] = true;
        result.push_back(u);
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited, result);
            }
        }
    }
};

// Approach 2 - Optimized (Iterative DFS with explicit stack)
// Simulate recursion using stack, always expands deepest unvisited node.
// Time Complexity: O(V + E)
// Space Complexity: O(V) for stack and visited array

class Solution {
public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;
        vector<bool> visited(V, false);
        stack<int> st;
        st.push(0);  // Start from vertex 0

        while (!st.empty()) {
            int u = st.top();
            st.pop();
            if (!visited[u]) {
                visited[u] = true;
                result.push_back(u);
                // Push neighbors in reverse order for left-to-right traversal
                for (int i = adj[u].size() - 1; i >= 0; --i) {
                    int v = adj[u][i];
                    if (!visited[v]) {
                        st.push(v);
                    }
                }
            }
        }
        return result;
    }
};
