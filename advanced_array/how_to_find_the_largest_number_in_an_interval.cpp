// Problem: How To Find The Largest Number In An Interval
// Link: https://leetcode.com/discuss/interview-question/algorithms/199350/how-to-find-the-largest-number-in-an-interval

#include <vector>
#include <algorithm>
using namespace std;

// Find The Largest Number In An Interval
// Problem: Given a list of intervals, find the point with the maximum number of overlapping intervals.

// Approach 1 - Brute Force:
// Check each point between the minimum start and maximum end of the intervals,
// count how many intervals cover that point and track the maximum count.
// Time Complexity: O(N * M) where N = number of intervals, M = range of interval values
// Space Complexity: O(1)

class Solution {
public:
    int maxOverlapBruteForce(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        int minStart = intervals[0][0], maxEnd = intervals[0][1];
        for (auto& interval : intervals) {
            minStart = min(minStart, interval[0]);
            maxEnd = max(maxEnd, interval[1]);
        }
        int maxOverlap = 0;
        for (int point = minStart; point <= maxEnd; ++point) {
            int count = 0;
            for (auto& interval : intervals) {
                if (interval[0] <= point && point <= interval[1]) {
                    ++count;
                }
            }
            maxOverlap = max(maxOverlap, count);
        }
        return maxOverlap;
    }
};

// Approach 2 - Optimized:
// Use a difference array technique:
// Increment count at start index, decrement count after end index,
// then compute prefix sums to find maximum overlap count.
// Time Complexity: O(N + M) where M is maxEnd - minStart range of intervals
// Space Complexity: O(M)

class Solution {
public:
    int maxOverlapOptimized(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        int minStart = intervals[0][0], maxEnd = intervals[0][1];
        for (auto& interval : intervals) {
            minStart = min(minStart, interval[0]);
            maxEnd = max(maxEnd, interval[1]);
        }

        // Create difference array sized to cover the interval range
        vector<int> diff(maxEnd - minStart + 2, 0);

        for (auto& interval : intervals) {
            diff[interval[0] - minStart] += 1;
            if (interval[1] - minStart + 1 < (int)diff.size()) {
                diff[interval[1] - minStart + 1] -= 1;
            }
        }

        int maxOverlap = 0, current = 0;
        for (int i = 0; i < (int)diff.size(); ++i) {
            current += diff[i];
            maxOverlap = max(maxOverlap, current);
        }
        return maxOverlap;
    }
};
