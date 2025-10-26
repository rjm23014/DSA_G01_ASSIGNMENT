// Problem: Merge Sorted Array
// Link: https://leetcode.com/problems/merge-sorted-array/

#include <vector>
#include <algorithm> // For std::sort
using namespace std;

// Merge Sorted Array
// Problem: Merge two sorted arrays into one sorted array in-place.

// Approach 1 - Brute Force:
// Copy elements from both arrays into a new vector, then sort it.
// Time Complexity: O((m + n) log(m + n))
// Space Complexity: O(m + n)

class SolutionBrute {
    public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Copy elements from nums2 into nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
        // Sort nums1 in-place
        sort(nums1.begin(), nums1.end());
    }
};

// Approach 2 - Optimized:
// Use two pointers to merge the arrays in-place without extra space.
// Time Complexity: O(m + n)
// Space Complexity: O(1)

class SolutionOptimized {
    public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int writeIndex = m + n - 1; // Last index of the merged array
        int i = m - 1; // Index for nums1
        int j = n - 1; // Index for nums2
        
        while (j >= 0) {
            // Compare elements from both arrays and place the larger one at the end
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[writeIndex--] = nums1[i--];
            } else {
                nums1[writeIndex--] = nums2[j--];
            }
        }
    }
};
