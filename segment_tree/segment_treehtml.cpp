// Problem: Segment Tree.Html
// Link: https://cp-algorithms.com/data_structures/segment_tree.html

#include <vector>
using namespace std;

// Segment Tree
// Problem: Implement a data structure that supports efficient range sum queries and point updates on an array.

// Approach 1 - Brute Force:
// Use a simple array and for each range sum query iterate over the range to calculate the sum.
// Time Complexity: O(n) per query
// Space Complexity: O(n)

class Solution {
    vector<int> arr;
public:
    Solution(const vector<int>& input) : arr(input) {}

    // Query sum from l to r (inclusive)
    int query(int l, int r) {
        int sum = 0;
        for (int i = l; i <= r; ++i)
            sum += arr[i];
        return sum;
    }

    // Update value at index pos
    void update(int pos, int val) {
        arr[pos] = val;
    }
};

// Approach 2 - Optimized:
// Use a segment tree to store sums of segments for O(log n) range sum queries and point updates.
// Time Complexity: O(log n) per query and update
// Space Complexity: O(n)

class Solution {
    int n;
    vector<int> tree;

    void build(const vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr)
            return tree[v];
        int tm = (tl + tr) / 2;
        return query(v*2, tl, tm, l, min(r, tm)) +
               query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            tree[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, val);
            else
                update(v*2+1, tm+1, tr, pos, val);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }

public:
    Solution(const vector<int>& input) {
        n = (int)input.size();
        tree.assign(4 * n, 0);
        build(input, 1, 0, n - 1);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    void update(int pos, int val) {
        update(1, 0, n - 1, pos, val);
    }
};
