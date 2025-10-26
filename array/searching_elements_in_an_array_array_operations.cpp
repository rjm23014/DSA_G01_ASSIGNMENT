// Problem: Searching Elements In An Array Array Operations
// Link: https://www.geeksforgeeks.org/searching-elements-in-an-array-array-operations/

#include <vector>
#include <algorithm> // for binary_search and find
using namespace std;

// Searching Elements In An Array Array Operations
// Problem: Given an array and a target element, search for the element's index or indicate absence

// Approach 1 - Brute Force:
// Linear search by checking each element sequentially
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int search(const vector<int>& arr, int x) {
        for (int i = 0; i < (int)arr.size(); i++) {
            if (arr[i] == x) return i;
        }
        return -1;
    }
};

// Approach 2 - Optimized:
// If the array is sorted, use binary search to find the element efficiently
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int search(const vector<int>& arr, int x) {
        int left = 0, right = (int)arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x) return mid;
            else if (arr[mid] < x) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};
