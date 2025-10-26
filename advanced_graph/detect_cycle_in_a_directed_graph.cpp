// Problem: Detect Cycle In A Directed Graph
// Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <vector>
using namespace std;

// Detect Cycle In A Directed Graph
// Problem: Check if a directed graph contains a cycle

// Approach 1 - Brute Force:
// Use DFS with a recursion stack (path) array to detect cycle
// Time Complexity: O(V + E)
// Space Complexity: O(V)
class Solution {
    bool dfs(int node, const vector<int> adj[], vector<int>& visited, vector<int>& path) {
        visited[node] = 1;
        path[node] = 1; // node is currently in recursion stack

        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                if (dfs(nbr, adj, visited, path)) return true;
            } 
            else if (path[nbr]) { // If neighbor is in recursion stack -> cycle
                return true;
            }
        }

        path[node] = 0; // remove from recursion stack
        return false;
    }

public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0), path(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, path)) return true;
            }
        }
        return false;
    }
};

// Approach 2 - Optimized:
// Use Kahn's Algorithm (Topological Sort) to detect cycle
// If topo sort includes all nodes, no cycle; otherwise, cycle exists
// Time Complexity: O(V + E)
// Space Complexity: O(V)
#include <queue>

class Solution {
public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);

        // Compute indegree for each vertex
        for (int i = 0; i < V; i++) {
            for (int nbr : adj[i]) {
                indegree[nbr]++;
            }
        }

        queue<int> q;
        // Start with all vertices of indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            count++;
            for (int nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) q.push(nbr);
            }
        }

        // If count doesn't cover all vertices, graph has a cycle
        return count != V;
    }
};
