// Problem: Bubble Sort Algorithm
// Link: https://www.geeksforgeeks.org/bubble-sort-algorithm/

#include <vector>
#include <algorithm>
using namespace std;

// Bubble Sort Algorithm
// Problem: Sort an integer array in ascending order using bubble sort.

// Approach 1 - Brute Force:
// Classic bubble sort compares and swaps every adjacent pair in each pass.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    void bubbleSort(vector<int>& arr) {
        int n = (int)arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

// Approach 2 - Optimized:
// Stops early if no swaps in a pass, meaning the array is already sorted.
// Time Complexity: Best O(n), Worst O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    void bubbleSort(vector<int>& arr) {
        int n = (int)arr.size();
        bool swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break; // Array is sorted, no need further passes
        }
    }
};
