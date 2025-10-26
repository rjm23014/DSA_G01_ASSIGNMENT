// Problem: Escape A Large Maze
// Link: https://leetcode.com/problems/escape-a-large-maze/description/

#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

// Escape a Large Maze
// Problem: Given a giant grid, a blocked list, start, and target, determine if a valid path exists from start to target.

// Approach 1 - Brute Force: (NOTE: This does NOT pass on LeetCode; intended as conceptual comparison)
// Try full BFS/DFS: infeasible on 1Mx1M grid, would time out.
// Time Complexity: O(1e12) — prohibitive!
// Space Complexity: O(1e12)

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        // Infeasible for large grids—method shown for illustration only.
        // Not implemented as it is not practical
        return true;
    }
};

// Approach 2 - Optimized:
// Key insight: maximum area blockable by blocked set is limited (≈blocked.size²/2 squares).
// Use BFS from both source and target, terminate early if explored area exceeds maximum enclosable area.
// Switch to BFS from other point if either search "escapes" (proves not fully enclosed).
// Time Complexity: O(B²) where B = blocked.size (≤200)
// Space Complexity: O(B²) — only small fraction of grid searched

#define BLOCK_LIMIT 200

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if (blocked.empty()) return true;

        unordered_set<long long> blocks;
        for (const auto& b : blocked)
            blocks.insert(((long long)b[0] << 32) + b[1]); // use long long to hash x and y

        return canEscape(source, target, blocks) && canEscape(target, source, blocks);
    }

private:
    int max_area = BLOCK_LIMIT * BLOCK_LIMIT / 2; // max area blockable by "blocked" points[2]

    bool canEscape(const vector<int>& src, const vector<int>& dst, const unordered_set<long long>& blocks) {
        unordered_set<long long> visited;
        queue<pair<int, int>> q;
        q.push({src[0], src[1]});
        visited.insert(((long long)src[0] << 32) + src[1]);

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty() && visited.size() <= max_area) {
            auto [x, y] = q.front(); q.pop();
            for (auto [dx, dy] : directions) { // C++17 structured binding
                int nx = x + dx, ny = y + dy;
                long long key = ((long long)nx << 32) + ny;
                if (nx < 0 || ny < 0 || nx >= 1e6 || ny >= 1e6 || 
                    blocks.count(key) || visited.count(key)) continue;
                if (nx == dst[0] && ny == dst[1]) return true; // reached destination
                visited.insert(key);
                q.push({nx, ny});
            }
        }
        return visited.size() > max_area; // escaped the enclosed area, thus possible
    }
};
