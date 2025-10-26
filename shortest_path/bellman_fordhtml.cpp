// Problem: Bellman Ford.Html
// Link: https://cp-algorithms.com/graph/bellman_ford.html

#include <vector>
#include <climits>
using namespace std;

// [Single-Source Shortest Paths with Negative Weights]
// Problem: Finds shortest paths from a source to all other vertices in a weighted graph, even with negative weights, and detects negative cycles.

// Approach 1 - Brute Force:
// Relax all edges up to V-1 times, where V is the number of vertices.
// Time Complexity: O(V*E)
// Space Complexity: O(V)

class SolutionBrute {
public:
    struct Edge { int a, b, cost; };
    void BellmanFord(int n, int m, int v, const vector<Edge>& edges) {
        const int INF = INT_MAX;
        vector<int> d(n, INF);
        d[v] = 0;
        for (int i = 0; i < n - 1; ++i) {
            bool any = false;
            for (const auto& e : edges) {
                if (d[e.a] < INF && d[e.b] > d[e.a] + e.cost) {
                    d[e.b] = d[e.a] + e.cost;
                    any = true;
                }
            }
            if (!any) break; // Early exit if no update in a phase
        }
        // Optionally, check for negative cycles here by scanning edges once more
        // and seeing if any distance can be further reduced.
    }
};

// Approach 2 - Optimized (Early Termination):
// Relax all edges V-1 times, but terminate early if no updates occur.
// Also includes parent[] to reconstruct paths and negative cycle detection.
// Time Complexity: O(V*E) average, but typically faster due to early exit.
// Space Complexity: O(V)

class SolutionOptimized {
public:
    struct Edge { int a, b, cost; };
    pair<vector<int>, vector<int>> BellmanFord(int n, int m, int v, const vector<Edge>& edges) {
        const int INF = INT_MAX;
        vector<int> d(n, INF);  // Distance from source
        vector<int> p(n, -1);   // Parent of each node in shortest path tree
        d[v] = 0;
        for (int i = 0; i < n - 1; ++i) {
            bool updated = false;
            for (const auto& e : edges) {
                if (d[e.a] < INF && d[e.b] > d[e.a] + e.cost) {
                    d[e.b] = d[e.a] + e.cost;
                    p[e.b] = e.a;
                    updated = true;
                }
            }
            if (!updated) break; // Early exit if no update
        }
        // Detect negative cycle
        bool hasNegCycle = false;
        for (const auto& e : edges)
            if (d[e.a] < INF && d[e.b] > d[e.a] + e.cost)
                hasNegCycle = true;
        // Return distances and parents; note: caller should check hasNegCycle
        return {d, p};
    }
};
