// Problem: The Maze Ii
// Link: https://leetcode.com/problems/the-maze-ii/description/

#include <vector>
#include <queue>
#include <limits>
using namespace std;

// The Maze II
// Problem: Find shortest distance for a ball rolling in a maze from start to destination, ball rolls until hitting a wall.

// Approach 1 - Brute Force:
// Use BFS without distance optimization, updating distances whenever a shorter path is found.
// Time Complexity: O(m * n * max(m,n)), since each roll can go up to max dimension length and each cell can be revisited
// Space Complexity: O(m * n) for distance matrix and queue

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, numeric_limits<int>::max()));
        dist[start[0]][start[1]] = 0;
        queue<pair<int,int>> q;
        q.push({start[0], start[1]});
        
        // directions: up, down, left, right
        vector<pair<int,int>> dirs{{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for(auto &[dx, dy]: dirs) {
                int nx = x, ny = y, count = 0;
                // roll until hitting a wall
                while(nx + dx >= 0 && nx + dx < m && ny + dy >= 0 && ny + dy < n && maze[nx + dx][ny + dy] == 0) {
                    nx += dx; ny += dy; count++;
                }
                if(dist[x][y] + count < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + count;
                    q.push({nx, ny});
                }
            }
        }
        return dist[dest[0]][dest[1]] == numeric_limits<int>::max() ? -1 : dist[dest[0]][dest[1]];
    }
};

// Approach 2 - Optimized:
// Use Dijkstra's algorithm with a priority queue to always expand the currently shortest distance node.
// This avoids unnecessary re-processing of longer paths and ensures each node minimized once.
// Time Complexity: O(m * n * log(m * n) * max(m,n)) due to priority queue operations and rolling distances
// Space Complexity: O(m * n) for distance matrix and queue

#include <queue>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, numeric_limits<int>::max()));
        dist[start[0]][start[1]] = 0;

        // Min-heap: (distance, (x, y))
        using T = pair<int, pair<int,int>>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, {start[0], start[1]}});

        vector<pair<int,int>> dirs{{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!pq.empty()) {
            auto [curDist, pos] = pq.top(); pq.pop();
            int x = pos.first, y = pos.second;
            if (dist[x][y] < curDist) continue; // already processed better distance
            if (x == dest[0] && y == dest[1]) return curDist;

            for (auto &[dx, dy] : dirs) {
                int nx = x, ny = y, steps = 0;
                // roll until hitting a wall
                while(nx + dx >= 0 && nx + dx < m && ny + dy >= 0 && ny + dy < n && maze[nx + dx][ny + dy] == 0) {
                    nx += dx; ny += dy; steps++;
                }
                int ndist = curDist + steps;
                if (ndist < dist[nx][ny]) {
                    dist[nx][ny] = ndist;
                    pq.push({ndist, {nx, ny}});
                }
            }
        }
        return -1;
    }
};
