// Problem: Minimum Platforms 1587115620
// Link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include <vector>
#include <algorithm>
using namespace std;

// Minimum Platforms
// Problem: Given arrival and departure times of trains, find the minimum number of platforms needed so that no train waits.

// Approach 1 - Brute Force:
// For every interval, count how many other intervals overlap with it. The maximum overlap across all intervals is the answer.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int findPlatform(int arr[], int dep[], int n) {
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int plat_needed = 1;
            for (int j = i + 1; j < n; ++j) {
                if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                    (arr[j] >= arr[i] && arr[j] <= dep[i]))
                    plat_needed++;
            }
            result = max(result, plat_needed);
        }
        return result;
    }
};

// Approach 2 - Optimized:
// Sort both arrival and departure arrays. Use two pointers to count platforms needed by comparing arrivals and departures.
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1)

class Solution {
public:
    int findPlatform(int arr[], int dep[], int n) {
        sort(arr, arr + n);
        sort(dep, dep + n);
        int plat_needed = 1, result = 1, i = 1, j = 0;
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) { // Another platform needed
                plat_needed++;
                i++;
            } else { // A platform freed
                plat_needed--;
                j++;
            }
            result = max(result, plat_needed);
        }
        return result;
    }
};
