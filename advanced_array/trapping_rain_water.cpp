// Problem: Trapping Rain Water
// Link: https://leetcode.com/problems/trapping-rain-water/

#include <vector>
#include <algorithm>
using namespace std;

// Trapping Rain Water
// Problem: Compute how much water can be trapped after raining in an elevation map.

// Approach 1 - Brute Force:
// Find max height to the left and right of each bar and calculate trapped water.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
    public:
    int trap(vector<int>& height) {
        int n = height.size();
        int waterTrapped = 0;
        for (int i = 0; i < n; i++) {
            int leftMax = 0, rightMax = 0;
            for (int j = i; j >= 0; --j) leftMax = max(leftMax, height[j]);
            for (int j = i; j < n; ++j) rightMax = max(rightMax, height[j]);
            waterTrapped += min(leftMax, rightMax) - height[i];
        }
        return waterTrapped;
    }
};

// Approach 2 - Optimized:
// Use two pointers to find max height to the left and right of each bar.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0; // No water can be trapped if n < 3
        
        int left = 0, right = n - 1;
        int lMax = height[0], rMax = height[n - 1];
        int waterTrapped = 0;
        
        while (left <= right) {
            if (rMax <= lMax) {
                waterTrapped += max(0, rMax - height[right]);
                rMax = max(rMax, height[right]);
                right--;
            } else {
                waterTrapped += max(0, lMax - height[left]);
                lMax = max(lMax, height[left]);
                left++;
            }
        }
        return waterTrapped;
    }
};
