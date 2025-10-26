// Problem: Kth Smallest Element5635
// Link: https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include <vector>
#include <algorithm>
#include <queue>
#include <random>
using namespace std;

// Kth Smallest Element
// Problem: Find the kth smallest element in an unsorted array

// Approach 1 - Brute Force:
// Sort the array and return the element at index k-1
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) or O(n) depending on sorting implementation

class Solution {
public:
    int kthSmallest(vector<int> arr, int k) {
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};

// Approach 2 - Optimized:
// Quickselect algorithm - average O(n) time by partitioning the array around a pivot
// Time Complexity: Average O(n), Worst O(n^2)
// Space Complexity: O(1) (in-place partitioning)

class Solution {
    int partition(vector<int>& arr, int left, int right) {
        int pivot = arr[right];
        int i = left;
        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[right]);
        return i;
    }
    
    int quickSelect(vector<int>& arr, int left, int right, int k) {
        if (left == right)
            return arr[left];
        int pivotIndex = partition(arr, left, right);
        int count = pivotIndex - left + 1;
        if (count == k)
            return arr[pivotIndex];
        else if (k < count)
            return quickSelect(arr, left, pivotIndex - 1, k);
        else
            return quickSelect(arr, pivotIndex + 1, right, k - count);
    }
public:
    int kthSmallest(vector<int> arr, int k) {
        return quickSelect(arr, 0, (int)arr.size() - 1, k);
    }
};
