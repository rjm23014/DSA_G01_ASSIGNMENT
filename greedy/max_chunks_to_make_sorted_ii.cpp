// Problem: Max Chunks To Make Sorted Ii
// Link: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/description/

#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// Max Chunks To Make Sorted II
// Problem: Given an array possibly with duplicates, split it into max chunks that can be sorted independently to form a fully sorted array.

// Approach 1 - Brute Force:
// Check all possible chunk partitions using a stack to merge chunks if necessary;
// Time Complexity: O(n^2) in worst cases due to repeated merges and comparisons.
// Space Complexity: O(n) for the stack.

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        for (int x : arr) {
            if (st.empty() || x >= st.top()) {
                st.push(x);
            } else {
                int maxVal = st.top();
                st.pop();
                while (!st.empty() && st.top() > x) {
                    st.pop();
                }
                st.push(maxVal);
            }
        }
        return (int)st.size();
    }
};

// Approach 2 - Optimized:
// Use prefix maximum and suffix minimum arrays to find all valid chunk boundaries, i.e., positions i where max(arr[0..i]) <= min(arr[i+1..n-1]).
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = (int)arr.size();
        vector<int> maxLeft(n), minRight(n + 1, INT_MAX);
        
        maxLeft[0] = arr[0];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], arr[i]);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            minRight[i] = min(minRight[i + 1], arr[i]);
        }
        
        int chunks = 0;
        for (int i = 0; i < n; i++) {
            if (maxLeft[i] <= minRight[i + 1]) {
                chunks++;
            }
        }
        return chunks;
    }
};
