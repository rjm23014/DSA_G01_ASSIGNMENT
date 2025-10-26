// Problem: Remove Duplicates From Sorted Array
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include <vector>
using namespace std;

// Remove Duplicates From Sorted Array
// Problem: Remove duplicates in-place such that each unique element appears only once.

// Approach 1 - Brute Force:
// Use an auxiliary vector to store unique elements, then copy back.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> unique;
        unique.push_back(nums[0]);
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] != nums[i-1]) {
                unique.push_back(nums[i]);
            }
        }
        for (int i = 0; i < (int)unique.size(); ++i) {
            nums[i] = unique[i];
        }
        return (int)unique.size();
    }
};

// Approach 2 - Optimized:
// Two pointers: one for iterating, other for position of next unique element.
// Overwrite duplicates in-place, no extra space.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int j = 1; // index for next unique element
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] != nums[i-1]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};
