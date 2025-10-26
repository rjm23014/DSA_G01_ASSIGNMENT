// Problem: Kth Largest Element In An Array
// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <vector>
#include <algorithm>
#include <queue>

// Kth Largest Element In An Array
// Problem: Find the kth largest element in an unsorted array.

// Approach 1 - Brute Force:
// Sort the array and pick the (n - k)th element.
// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k]; // Convert kth largest to index
    }
};

// Approach 2 - Optimized (Quickselect):
// Use the partitioning idea from quicksort, recursively reducing the problem size.
// Time Complexity: O(n) average, O(n^2) worst-case
// Space Complexity: O(1)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Shuffle to avoid worst-case O(n^2) time
        auto rng = default_random_engine();
        shuffle(nums.begin(), nums.end(), rng);
        int n = nums.size();
        int left = 0, right = n - 1, target = n - k; // (n - k) is the index needed

        while (left <= right) {
            int idx = partition(nums, left, right);
            if (idx == target)
                return nums[idx];
            else if (idx < target)
                left = idx + 1;
            else
                right = idx - 1;
        }
        return -1; // Should not reach here
    }

private:
    // Hoare's partition scheme
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], i = left - 1, j = right + 1;
        while (true) {
            do { i++; } while (nums[i] < pivot);
            do { j--; } while (nums[j] > pivot);
            if (i >= j) return j;
            swap(nums[i], nums[j]);
        }
    }
};
