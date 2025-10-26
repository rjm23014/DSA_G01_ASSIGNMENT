// Problem: Sort Colors
// Link: https://leetcode.com/problems/sort-colors/

#include <vector>
#include <algorithm> // for std::count (used in brute force)
using namespace std;

// Sort Colors
// Problem: Given an array with 0s, 1s, and 2s, sort it in-place so that same colors are adjacent in order 0,1,2.

// Approach 1 - Brute Force:
// Count number of 0s, 1s, and 2s and overwrite the array.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        for (int num : nums) {
            if (num == 0) count0++;
            else if (num == 1) count1++;
            else count2++;
        }
        int i = 0;
        while (count0--) nums[i++] = 0;
        while (count1--) nums[i++] = 1;
        while (count2--) nums[i++] = 2;
    }
};

// Approach 2 - Optimized:
// Dutch National Flag algorithm uses three pointers to partition array in one pass.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = (int)nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
