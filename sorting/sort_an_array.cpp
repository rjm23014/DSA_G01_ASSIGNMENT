// Problem: Sort An Array
// Link: https://leetcode.com/problems/sort-an-array/description/

#include <vector>
#include <algorithm> // For std::sort in brute force
using namespace std;

// Sort An Array
// Problem: Given an integer array nums, sort the array in ascending order and return it.

// Approach 1 - Brute Force:
// Simply use the built-in sort function to sort the array.
// Time Complexity: O(n log n)
// Space Complexity: O(log n) due to stack space in sort (introsort)

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// Approach 2 - Optimized:
// Implement Merge Sort to sort the array without using built-in sort.
// Time Complexity: O(n log n)
// Space Complexity: O(n) for auxiliary array used in merge

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
private:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1, n2 = right - mid;
        vector<int> leftArr(n1), rightArr(n2);

        for (int i = 0; i < n1; i++)
            leftArr[i] = nums[left + i];
        for (int i = 0; i < n2; i++)
            rightArr[i] = nums[mid + 1 + i];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                nums[k++] = leftArr[i++];
            } else {
                nums[k++] = rightArr[j++];
            }
        }
        while (i < n1) nums[k++] = leftArr[i++];
        while (j < n2) nums[k++] = rightArr[j++];
    }
};
