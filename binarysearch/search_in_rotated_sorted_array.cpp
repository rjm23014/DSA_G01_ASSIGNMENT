// Problem: Search In Rotated Sorted Array
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <vector>
using namespace std;

// Search in Rotated Sorted Array
// Problem: Find the index of target in a rotated sorted array of distinct integers; return -1 if not found.

// Approach 1 - Brute Force:
// Check each element sequentially until the target is found.
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == target) return i;
        }
        return -1;
    }
};

// Approach 2 - Optimized:
// Use modified binary search exploiting the fact that one half of the array is always sorted.
// Determine which half is sorted, then decide which half to search based on the target's value.
// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;

            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
