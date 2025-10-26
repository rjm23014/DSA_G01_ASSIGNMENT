// Problem: Build Heap 975375
// Link: https://www.naukri.com/code360/problems/build-heap_975375

#include <vector>
#include <algorithm>

using namespace std;

// Problem: Build Heap 975375
// Problem: Build a heap from a given array. 

// Approach 1 - Brute Force:
// [Brief explanation]
// - Insert elements one by one into a heap.
// Time Complexity: O(N log N)
// Space Complexity: O(N)

class Solution1 {
    public:
    void buildHeap(vector<int>& arr) {
        vector<int> heap; // Create a new heap
        for (int num : arr) {
            heap.push_back(num); // Insert each number into the heap
            std::push_heap(heap.begin(), heap.end()); // Heapify after insertion
        }
        arr = heap; // Replace the original array with the heap
    }
};

// Approach 2 - Optimized:
// [Brief explanation]
// - Use `std::make_heap()` to convert the entire array into a heap directly.
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution2 {
    public:
    void buildHeap(vector<int>& arr) {
        std::make_heap(arr.begin(), arr.end()); // Convert array to max heap
    }
};
