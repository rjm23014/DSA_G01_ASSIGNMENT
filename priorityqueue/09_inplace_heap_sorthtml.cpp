// Problem: 09 Inplace Heap Sort.Html
// Link: https://www.csl.mtu.edu/cs2321/www/newLectures/09_Inplace_Heap_Sort.html

#include <vector>
#include <algorithm>
using namespace std;

// Inplace Heap Sort
// Problem: Sort an array in ascending order using inplace heap sort

// Approach 1 - Brute Force: Convert to max-heap, then repeatedly extract max and shift the heap down.
// Time Complexity: O(n^2) (suboptimal heapify implementation)
// Space Complexity: O(1) (inplace, no extra space)

class Solution {
public:
    // Build max heap by iterating from first non-leaf to root
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest); // recursive heapify
        }
    }

    // Brute force inplace heapsort
    void sort(vector<int>& arr) {
        int n = arr.size();
        // Build heap, starting from last non-leaf node
        for (int i = n / 2 - 1; i >= 0; --i)
            heapify(arr, n, i);
        // Extract elements one by one
        for (int i = n - 1; i >= 0; --i) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

// Approach 2 - Optimized: Inplace, but use iterative heapify for efficiency
// Time Complexity: O(n log n)
// Space Complexity: O(1) (inplace)

class Solution {
public:
    // Bottom-up iterative heapify to avoid recursion stack
    void heapify(vector<int>& arr, int n, int i) {
        int current = i;
        while (true) {
            int largest = current;
            int l = 2 * current + 1;
            int r = 2 * current + 2;
            if (l < n && arr[l] > arr[largest]) largest = l;
            if (r < n && arr[r] > arr[largest]) largest = r;
            if (largest == current) break;
            swap(arr[current], arr[largest]);
            current = largest;
        }
    }

    // Standard inplace heapsort with optimized heapify
    void sort(vector<int>& arr) {
        int n = arr.size();
        // Build max heap (bottom-up)
        for (int i = n / 2 - 1; i >= 0; --i)
            heapify(arr, n, i);
        // Repeatedly move max to end and shrink heap
        for (int i = n - 1; i > 0; --i) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};
