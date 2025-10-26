// Problem: Median Of A Row Wise Sorted Matrix
// Link: https://leetcode.com/problems/median-of-a-row-wise-sorted-matrix/description/

#include <vector>
#include <algorithm>
using namespace std;

// Median Of A Row Wise Sorted Matrix
// Problem: Find median of a matrix where each row is sorted, total elements odd

// Approach 1 - Brute Force:
// Flatten matrix into a vector, sort it, return middle element.
// Time Complexity: O(r * c * log(r * c)) for sorting all elements
// Space Complexity: O(r * c) for the flattened array

class Solution {
public:
    int median(vector<vector<int>>& matrix) {
        vector<int> nums;
        for (auto &row : matrix) {
            nums.insert(nums.end(), row.begin(), row.end());
        }
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// Approach 2 - Optimized:
// Use binary search on value range between min and max elements.
// For each mid value, count elements <= mid using upper_bound on each row (row-wise sorted).
// Narrow down until median is found.
// Time Complexity: O(32 * r * log c) ~ O(r * log c) since values up to 10^6 and binary search 32 bits
// Space Complexity: O(1) no extra space except variables

class Solution {
public:
    int median(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        int low = 1, high = 1000000; // Given constraints max element can be 10^6

        while (low < high) {
            int mid = low + (high - low) / 2;
            // Count elements less than or equal to mid
            int count = 0;
            for (int i = 0; i < r; i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (count < (r * c + 1) / 2)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
