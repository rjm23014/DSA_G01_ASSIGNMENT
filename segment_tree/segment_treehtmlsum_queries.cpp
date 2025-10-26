// Problem: Segment Tree.Html#Sum Queries
// Link: https://cp-algorithms.com/data_structures/segment_tree.html#sum-queries

#include <vector>
#include <algorithm>

// Problem: Calculate the sum of elements in a given range using a segment tree.
// Problem Description: Efficiently compute the sum of elements in a range by utilizing a segment tree.

// Approach 1 - Brute Force:
// Brute Force approach iterates over all elements in the range to calculate the sum.
// Time Complexity: O(n)
// Space Complexity: O(1)

class BruteForceSolution {
public:
    int sumRange(std::vector<int>& arr, int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum += arr[i];
        }
        return sum;
    }
};

// Approach 2 - Optimized:
// Optimized approach uses a segment tree to efficiently compute range sums.
// Time Complexity: O(log n) for both construction and query
// Space Complexity: O(n)

class OptimizedSolution {
private:
    std::vector<int> tree;
    int n;

public:
    OptimizedSolution(std::vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n); // Allocate space for the segment tree
        buildTree(arr, 0, 0, n - 1);
    }

    // Function to build the segment tree
    void buildTree(const std::vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start]; // Leaf node
        } else {
            int mid = start + (end - start) / 2;
            buildTree(arr, 2 * node + 1, start, mid); // Left subtree
            buildTree(arr, 2 * node + 2, mid + 1, end); // Right subtree
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Combine results
        }
    }

    // Function to query the range sum
    int sumRange(int left, int right) {
        return queryTree(0, 0, n - 1, left, right);
    }

    // Recursive function to query a range sum
    int queryTree(int node, int start, int end, int left, int right) {
        if (left > end || right < start) {
            return 0; // Outside query range
        } else if (left <= start && right >= end) {
            return tree[node]; // Fully inside query range
        } else {
            int mid = start + (end - start) / 2;
            return queryTree(2 * node + 1, start, mid, left, right) + 
                   queryTree(2 * node + 2, mid + 1, end, left, right); // Partially inside
        }
    }
};
