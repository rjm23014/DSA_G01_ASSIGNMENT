// Problem: Operations On Priorityqueue
// Link: https://www.geeksforgeeks.org/problems/operations-on-priorityqueue/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <queue>
#include <vector>
using namespace std;

// Operations On Priorityqueue
// Problem: Perform given operations (insert, delete max, print max) on a priority queue.

// Approach 1 - Brute Force:
// Use a priority_queue from STL directly to simulate operations.
// Time Complexity: O(q log n) where q = number of queries, n = number of elements in pq
// Space Complexity: O(n) to store elements in priority queue

class Solution {
public:
    vector<int> pqOperations(int n, vector<vector<int>> &queries) {
        priority_queue<int> pq;
        vector<int> res;

        for (auto &q : queries) {
            int op = q[0];
            if (op == 1) {
                // Insert element q[1]
                pq.push(q[1]);
            } else if (op == 2) {
                // Remove max element if pq not empty
                if (!pq.empty()) {
                    pq.pop();
                }
            } else if (op == 3) {
                // Print max element if pq not empty else -1
                if (!pq.empty()) {
                    res.push_back(pq.top());
                } else {
                    res.push_back(-1);
                }
            }
        }

        return res;
    }
};

// Approach 2 - Optimized:
// Using the STL priority_queue is already optimal for this problem since insert/pop/top are O(log n) / O(1).
// Any other DS (e.g., balanced BST) doesn't improve asymptotic complexity for these queries.
// So this approach is essentially the same as above; just directly use STL priority_queue without overhead.
// Time Complexity: O(q log n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> pqOperations(int n, vector<vector<int>> &queries) {
        priority_queue<int> pq;
        vector<int> ans;

        for (auto &query : queries) {
            int type = query[0];
            if (type == 1) {
                pq.push(query[1]);
            } else if (type == 2) {
                if (!pq.empty()) pq.pop();
            } else if (type == 3) {
                ans.push_back(pq.empty() ? -1 : pq.top());
            }
        }

        return ans;
    }
};
