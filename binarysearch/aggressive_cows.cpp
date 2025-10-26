// Problem: Aggressive Cows
// Link: https://www.geeksforgeeks.org/problems/aggressive-cows/0

#include <vector>
#include <algorithm>
using namespace std;

// Aggressive Cows
// Problem: Place k aggressive cows in stalls to maximize the minimum distance between any two cows.

// Approach 1 - Brute Force:
// Try all possible distances from 1 up to max distance between stalls and check feasibility.
// Time Complexity: O(n * d) where d = max(stalls) - min(stalls)
// Space Complexity: O(1)
class Solution {
    bool canPlaceCows(const vector<int>& stalls, int dist, int k) {
        int count = 1;  // placed first cow at first stall
        int lastPos = stalls[0];
        for (int i = 1; i < (int)stalls.size(); ++i) {
            if (stalls[i] - lastPos >= dist) {
                ++count;
                lastPos = stalls[i];
                if (count >= k) return true;
            }
        }
        return false;
    }
public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int maxDist = stalls.back() - stalls.front();
        for (int dist = 1; dist <= maxDist; ++dist) {
            if (!canPlaceCows(stalls, dist, k))
                return dist - 1;
        }
        return maxDist;
    }
};

// Approach 2 - Optimized:
// Use binary search on the answer for minimum distance and check feasibility.
// Time Complexity: O(n log d) where d = max(stalls) - min(stalls)
// Space Complexity: O(1)
class Solution {
    bool canPlaceCows(const vector<int>& stalls, int dist, int k) {
        int count = 1;
        int lastPos = stalls[0];
        for (int i = 1; i < (int)stalls.size(); ++i) {
            if (stalls[i] - lastPos >= dist) {
                ++count;
                lastPos = stalls[i];
                if (count >= k) return true;
            }
        }
        return false;
    }
public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls.back() - stalls.front();
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlaceCows(stalls, mid, k)) {
                ans = mid;    // mid is valid, try for larger distance
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
