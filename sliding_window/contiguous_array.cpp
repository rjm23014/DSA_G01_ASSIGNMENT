// Problem: Contiguous Array
// Link: https://leetcode.com/problems/contiguous-array/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Contiguous Array
// Problem: Find max length of contiguous subarray with equal 0s and 1s.

// Approach 1 - Brute Force:
// Check all possible subarrays, count 0s and 1s, track max length with equal counts.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;
        for (int i = 0; i < n; ++i) {
            int zeros = 0, ones = 0;
            for (int j = i; j < n; ++j) {
                if (nums[j] == 0) zeros++;
                else ones++;
                if (zeros == ones) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        return max_len;
    }
};

// Approach 2 - Optimized:
// Treat 0 as -1, compute prefix sums, use hash map to track first occurrence of each sum.
// A subarray with sum 0 between two indices indicates equal 0s and 1s.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> sum_index; // prefix sum -> first occurrence index
        sum_index[0] = -1; // handle subarray starting at index 0
        int cur_sum = 0, max_len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cur_sum += (nums[i] == 0 ? -1 : 1); // 0 becomes -1, 1 remains +1
            if (sum_index.find(cur_sum) != sum_index.end()) {
                max_len = max(max_len, i - sum_index[cur_sum]);
            } else {
                sum_index[cur_sum] = i;
            }
        }
        return max_len;
    }
};
