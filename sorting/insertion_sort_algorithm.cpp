// Problem: Insertion Sort Algorithm
// Link: https://www.geeksforgeeks.org/insertion-sort-algorithm/

#include <vector>
using namespace std;

// Insertion Sort Algorithm
// Problem: Sort an array/vector in ascending order using insertion sort

// Approach 1 - Brute Force:
// Classic insertion sort inserts each element into its correct position by swapping repeatedly.
// Time Complexity: O(n^2) - nested loops
// Space Complexity: O(1) - in-place sorting

class Solution {
public:
    void insertionSort(vector<int>& arr) {
        int n = (int)arr.size();
        for (int i = 1; i < n; i++) {
            int j = i;
            // Swap arr[j] backward until it reaches correct position
            while (j > 0 && arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                j--;
            }
        }
    }
};

// Approach 2 - Optimized:
// Instead of swapping repeatedly, store the key and shift greater elements right,
// then insert the key at the right position.
// Time Complexity: O(n^2) in worst case, but generally faster due to fewer swaps
// Space Complexity: O(1) - in-place sorting

class Solution {
public:
    void insertionSort(vector<int>& arr) {
        int n = (int)arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            // Shift elements greater than key to the right
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;  // Insert key at correct position
        }
    }
};
