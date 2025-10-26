// Problem: Jump Game Ii
// Link: https://leetcode.com/problems/jump-game-ii/

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Jump Game II
// Problem: Given an array where each element represents max jump length from that index,
// find the minimum number of jumps to reach the last index.

// Approach 1 - Brute Force:
// Explore all possible jumps recursively from each index to find minimal jumps.
// Time Complexity: O(2^n) exponential due to overlapping subproblems without memoization.
// Space Complexity: O(n) recursion stack depth.

class Solution {
public:
    int jumpFrom(const vector<int>& nums, int index) {
        if (index >= (int)nums.size() - 1) return 0;
        int minJumps = INT_MAX;
        for (int step = 1; step <= nums[index]; ++step) {
            int nextIndex = index + step;
            if (nextIndex < (int)nums.size()) {
                int subRes = jumpFrom(nums, nextIndex);
                if (subRes != INT_MAX) {
                    minJumps = min(minJumps, 1 + subRes);
                }
            }
        }
        return minJumps;
    }
    int jump(vector<int>& nums) {
        return jumpFrom(nums, 0);
    }
};

// Approach 2 - Optimized:
// Use a greedy approach to keep track of the farthest reachable index within the current jump.
// Increment jumps when reaching the boundary of the current range.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, currentEnd = 0, farthest = 0;
        int n = (int)nums.size();
        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};
