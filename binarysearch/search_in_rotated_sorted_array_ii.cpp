// Problem: Search In Rotated Sorted Array Ii
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <vector>
using namespace std;

// Search In Rotated Sorted Array II
// Problem: Search for a target value in a rotated sorted array that may contain duplicates

// Approach 1 - Brute Force:
// Simply scan through the entire array to find the target.
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (int num : nums) {
            if (num == target) return true;
        }
        return false;
    }
};

// Approach 2 - Optimized:
// Modified binary search that handles rotation and duplicates.
// Shrink search space when duplicates prevent direction deduction.
// Time Complexity: Average O(log n), Worst O(n) due to duplicates
// Space Complexity: O(1)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = static_cast<int>(nums.size()) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            
            // If duplicates at the edges, shrink search space
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                ++left;
                --right;
            }
            // Left half is sorted
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
