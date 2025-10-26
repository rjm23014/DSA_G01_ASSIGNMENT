// Problem: Selection Sort Algorithm 2
// Link: https://www.geeksforgeeks.org/selection-sort-algorithm-2/

#include <vector>
#include <algorithm>

// Selection Sort Algorithm 2
// Problem: Implement the selection sort algorithm to sort an array in ascending order.

// Approach 1 - Brute Force:
// This approach is inherently bruteforce as selection sort is straightforward and simple.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
    public:
    void selectionSort(std::vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            int min_idx = i; // Assume the current element is the minimum.
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] < nums[min_idx]) // Update min_idx if a smaller element is found.
                    min_idx = j;
            }
            std::swap(nums[i], nums[min_idx]); // Move the minimum element to its correct position.
        }
    }
};

// Approach 2 - Optimized:
// Since selection sort is fundamentally a comparison-based algorithm with a time complexity of O(n^2), 
// no optimization can improve its worst-case time complexity. However, we can make the code more concise and readable.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class SolutionOptimized {
    public:
    void selectionSort(std::vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            int min_idx = i;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] < nums[min_idx]) min_idx = j;
            }
            std::swap(nums[i], nums[min_idx]);
        }
    }
};
