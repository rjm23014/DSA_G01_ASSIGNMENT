// Problem: First Bad Version
// Link: https://leetcode.com/problems/first-bad-version/

#include <vector>
// No additional includes needed
using namespace std;

// First Bad Version
// Problem: Find the first version that is bad given isBadVersion(version) API.

// Approach 1 - Brute Force:
// Check every version starting from 1 until a bad version is found.
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int firstBadVersion(int n) {
        for (int v = 1; v <= n; ++v) {
            if (isBadVersion(v)) return v;
        }
        return n; // fallback, if all versions are good (not specified in problem constraints)
    }
};

// Approach 2 - Optimized:
// Use binary search to minimize calls to isBadVersion.
// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid; // first bad version is at mid or before
            } else {
                left = mid + 1; // first bad version is after mid
            }
        }
        return left;
    }
};
