// Problem: Rotate Array
// Link: https://leetcode.com/problems/rotate-array/description/

#include <vector>
#include <algorithm> // For reverse
using namespace std;

// Rotate Array
// Problem: Given an array, rotate it to the right by k steps in-place.

// Approach 1 - Brute Force:
// Rotate one step at a time, moving last element to front, repeat k times.
// Time Complexity: O(n * k)
// Space Complexity: O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle k > n
        while (k--) {
            int last = nums.back();
            for (int i = n - 1; i > 0; --i)
                nums[i] = nums[i - 1];
            nums[0] = last;
        }
    }
};

// Approach 2 - Optimized:
// Reverse entire array, then first k elements, then remaining n-k elements.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // Handle k > n
        reverse(nums.begin(), nums.end()); // Reverse all
        reverse(nums.begin(), nums.begin() + k); // Reverse first k
        reverse(nums.begin() + k, nums.end()); // Reverse the rest
    }
};
