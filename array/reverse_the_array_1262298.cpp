// Problem: Reverse The Array 1262298
// Link: https://www.naukri.com/code360/problems/reverse-the-array_1262298

#include <vector>
#include <algorithm> // for std::reverse
using namespace std;

// Reverse The Array
// Problem: Reverse the given array in place

// Approach 1 - Brute Force:
// Create a new temporary array, copy elements from original in reverse order,
// then copy back to the original array.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> reverseArray(int arr[], int n) {
        vector<int> temp(n);
        for (int i = 0; i < n; ++i) {
            temp[i] = arr[n - 1 - i]; // copy in reverse order
        }
        for (int i = 0; i < n; ++i) {
            arr[i] = temp[i]; // copy back to original
        }
        return vector<int>(arr, arr + n);
    }
};

// Approach 2 - Optimized:
// Reverse the array in place by swapping elements symmetrically using two pointers.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> reverseArray(int arr[], int n) {
        int left = 0, right = n - 1;
        while (left < right) {
            swap(arr[left], arr[right]);
            ++left;
            --right;
        }
        return vector<int>(arr, arr + n);
    }
};
