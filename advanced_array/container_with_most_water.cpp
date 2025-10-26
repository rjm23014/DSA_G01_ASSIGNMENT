// Problem: Container With Most Water
// Link: https://leetcode.com/problems/container-with-most-water/

#include <vector>
#include <algorithm>
using namespace std;

// Container With Most Water
// Problem: Given heights of vertical lines, find two lines that form a container with x-axis to hold max water.

// Approach 1 - Brute Force:
// Check all pairs of lines and calculate area, keep track of max.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int n = (int)height.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int area = min(height[i], height[j]) * (j - i);
                max_area = max(max_area, area);
            }
        }
        return max_area;
    }
};

// Approach 2 - Optimized:
// Use two pointers at the ends, move the shorter line's pointer inward to find max area.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left = 0, right = (int)height.size() - 1;
        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);
            int current_area = width * h;
            max_area = max(max_area, current_area);

            // Move pointer at shorter height
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};
