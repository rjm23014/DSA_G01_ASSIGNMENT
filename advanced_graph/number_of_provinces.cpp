// Problem: Number Of Provinces
// Link: https://leetcode.com/problems/number-of-provinces/description/

#include <vector>
#include <queue>
using namespace std;

// Number Of Provinces
// Problem: Count the number of connected components in an undirected graph given as an adjacency matrix.

// Approach 1 - Brute Force (DFS with adjacency matrix traversal)
// For each unvisited node, traverse all reachable nodes via DFS using direct matrix checks.
// Time Complexity: O(n^2) (each DFS explores all connections for each node)
// Space Complexity: O(n) (visited array)

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (int neighbor = 0; neighbor < n; ++neighbor) {
                if (!visited[neighbor] && isConnected[node][neighbor] == 1) {
                    dfs(neighbor);
                }
            }
        };

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i);
                provinces++;
            }
        }
        return provinces;
    }
};
