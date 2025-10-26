// Problem: Largest Subarray With 0 Sum
// Link: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Largest Subarray With 0 Sum
// Problem: Find the length of the longest subarray with sum equal to 0.

// Approach 1 - Brute Force:
// Check every subarray by two nested loops, calculate sum and update maximum length for sum 0.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int maxLen(vector<int>& arr) {
        int n = (int)arr.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int currSum = 0;
            for (int j = i; j < n; j++) {
                currSum += arr[j];
                if (currSum == 0) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};

// Approach 2 - Optimized:
// Use a hash map to store prefix sum first occurrence index.
// If prefix sum repeats, subarray between indices sums to zero.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int maxLen(vector<int>& arr) {
        unordered_map<int, int> prefixSumIndex;
        int prefixSum = 0, maxLen = 0;
        for (int i = 0; i < (int)arr.size(); i++) {
            prefixSum += arr[i];
            if (prefixSum == 0) {
                maxLen = i + 1;  // Subarray from start to i sums to zero
            } else {
                if (prefixSumIndex.find(prefixSum) != prefixSumIndex.end()) {
                    maxLen = max(maxLen, i - prefixSumIndex[prefixSum]);
                } else {
                    prefixSumIndex[prefixSum] = i;
                }
            }
        }
        return maxLen;
    }
};
