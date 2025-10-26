// Problem: Segment Tree And Lazy Propagation
// Link: https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/

#include <vector>
using namespace std;

// Segment Tree and Lazy Propagation
// Problem: Perform range updates (increment) and range sum queries on an array efficiently.

// Approach 1 - Brute Force:
// Directly apply each update by incrementing all elements in the range.
// Query by summing elements in the range.
// Time Complexity: Update O(N), Query O(N)
// Space Complexity: O(N)

class Solution {
    vector<int> arr;
public:
    Solution(const vector<int>& input) : arr(input) {}

    // Increment elements in [l, r] by val
    void update(int l, int r, int val) {
        for (int i = l; i <= r; i++) {
            arr[i] += val;
        }
    }

    // Return sum of elements in [l, r]
    int query(int l, int r) {
        int sum = 0;
        for (int i = l; i <= r; i++) {
            sum += arr[i];
        }
        return sum;
    }
};

// Approach 2 - Optimized:
// Use segment tree with lazy propagation to handle range updates and range queries in O(log N).
// Lazy array stores pending increments to propagate only when necessary.
// Time Complexity: Update O(log N), Query O(log N)
// Space Complexity: O(4*N) for segment tree and lazy arrays

class Solution {
    int n;
    vector<int> seg, lazy;

    void build(const vector<int> &arr, int idx, int st, int en) {
        if (st == en) {
            seg[idx] = arr[st];
            return;
        }
        int mid = (st + en) / 2;
        build(arr, 2 * idx, st, mid);
        build(arr, 2 * idx + 1, mid + 1, en);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }

    void propagate(int idx, int st, int en) {
        if (lazy[idx] != 0) {
            seg[idx] += (en - st + 1) * lazy[idx];
            if (st != en) {
                lazy[2 * idx] += lazy[idx];
                lazy[2 * idx + 1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    void update(int idx, int st, int en, int l, int r, int val) {
        propagate(idx, st, en);
        if (r < st || en < l) return;
        if (l <= st && en <= r) {
            lazy[idx] += val;
            propagate(idx, st, en);
            return;
        }
        int mid = (st + en) / 2;
        update(2 * idx, st, mid, l, r, val);
        update(2 * idx + 1, mid + 1, en, l, r, val);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }

    int query(int idx, int st, int en, int l, int r) {
        propagate(idx, st, en);
        if (r < st || en < l) return 0;
        if (l <= st && en <= r) return seg[idx];
        int mid = (st + en) / 2;
        return query(2 * idx, st, mid, l, r) + query(2 * idx + 1, mid + 1, en, l, r);
    }

public:
    Solution(const vector<int>& input) {
        n = (int)input.size();
        seg.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(input, 1, 0, n - 1);
    }

    // Increment elements in [l, r] by val
    void update(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    // Return sum of elements in [l, r]
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};
