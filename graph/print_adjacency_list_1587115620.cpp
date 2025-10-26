// Problem: Print Adjacency List 1587115620
// Link: https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Print Adjacency List
// Problem: Given an undirected graph with V vertices and E edges, build and return its adjacency list in ascending order for each vertex.

// Approach 1 - Brute Force:
// Use an array of vectors to store adjacent nodes for each vertex. Sort each vector for ascending order separately.
// Time Complexity: O(V + E log E)
// Space Complexity: O(V + E)

class Solution {
public:
    vector<vector<int>> printAdjacency(int V, int E, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        // Sort each vertex's adjacency list for correct order
        for (int i = 0; i < V; ++i)
            sort(adjList[i].begin(), adjList[i].end());
        return adjList;
    }
};

// Approach 2 - Optimized:
// Same as Approach 1, but insert edges in ascending order using map/set for each vertex, avoiding the need for post-sort.
// Time Complexity: O(V + E log E)
// Space Complexity: O(V + E)

class Solution {
public:
    vector<vector<int>> printAdjacency(int V, int E, vector<vector<int>>& edges) {
        vector<set<int>> tempAdj(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            tempAdj[u].insert(v);
            tempAdj[v].insert(u);
        }
        // Convert from set to vector
        vector<vector<int>> adjList(V);
        for (int i = 0; i < V; ++i)
            adjList[i].assign(tempAdj[i].begin(), tempAdj[i].end());
        return adjList;
    }
};
