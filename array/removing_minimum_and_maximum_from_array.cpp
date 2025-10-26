// Problem: Removing Minimum And Maximum From Array
// Link: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/

#include <vector>
#include <algorithm>
using namespace std;

// Removing Minimum And Maximum From Array
// Problem: Remove minimum and maximum elements from the array by deleting from either front or back with minimal deletions.

// Approach 1 - Brute Force:
// Find indices of min and max elements by scanning the array twice.
// Then calculate minimal deletions using all possible ways.
// Time Complexity: O(n), n = size of nums (two scans for min and max)
// Space Complexity: O(1)

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = (int)nums.size();
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int minIdx = -1, maxIdx = -1;
        // Find indices of min and max
        for (int i = 0; i < n; ++i) {
            if (nums[i] == minVal) minIdx = i;
            else if (nums[i] == maxVal) maxIdx = i;
            if (minIdx != -1 && maxIdx != -1) break;
        }
        if (minIdx > maxIdx) swap(minIdx, maxIdx);

        // Remove both from front
        int front = maxIdx + 1;
        // Remove both from back
        int back = n - minIdx;
        // Remove min from front, max from back
        int frontBack = (minIdx + 1) + (n - maxIdx);
        // Remove max from front, min from back
        int backFront = (maxIdx + 1) + (n - minIdx);

        return min({front, back, frontBack, backFront});
    }
};

// Approach 2 - Optimized:
// Use std::minmax_element to find min and max positions in single pass.
// Calculate minimal deletions similarly with less manual code.
// Time Complexity: O(n) due to single scan with minmax_element
// Space Complexity: O(1)

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = (int)nums.size();
        auto [minIt, maxIt] = minmax_element(nums.begin(), nums.end());
        int i = int(minIt - nums.begin());
        int j = int(maxIt - nums.begin());
        if (i > j) swap(i, j);

        return min({j + 1,              // remove all from front up to max index
                    n - i,              // remove all from back up to min index
                    i + 1 + n - j});    // remove min from front and max from back
    }
};
