// Problem: Max Chunks To Make Sorted
// Link: https://leetcode.com/problems/max-chunks-to-make-sorted/description/

#include <vector>
#include <algorithm>

using namespace std;

// Max Chunks To Make Sorted
// Problem: Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into chunks, sort each chunk, and concatenate them to form the sorted array.

// Approach 1 - Brute Force: 
// This approach involves generating all possible partitions of the array and checking if sorting each partition results in the sorted array.
// Time Complexity: O(2^n * n log n) due to generating all partitions and sorting each chunk.
// Space Complexity: O(n) for storing the partitions.

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxChunks = 0;

        // Generate all possible partitions
        for (int mask = 1; mask < (1 << n); ++mask) {
            vector<vector<int>> partitions;
            vector<int> currentChunk;
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i))) { // Start a new partition
                    if (!currentChunk.empty()) {
                        partitions.push_back(currentChunk);
                        currentChunk.clear();
                    }
                }
                currentChunk.push_back(arr[i]);
            }
            if (!currentChunk.empty()) {
                partitions.push_back(currentChunk);
            }

            // Check if sorting each partition results in the sorted array
            vector<int> sortedConcat;
            for (auto& chunk : partitions) {
                sort(chunk.begin(), chunk.end());
                sortedConcat.insert(sortedConcat.end(), chunk.begin(), chunk.end());
            }
            if (is_sorted(sortedConcat.begin(), sortedConcat.end()) && sortedConcat == arr) {
                maxChunks = max(maxChunks, (int)partitions.size());
            }
        }

        return maxChunks;
    }
};

// Approach 2 - Optimized:
// This approach involves iterating through the array and checking if the current index matches the maximum value seen so far.
// Time Complexity: O(n) for a single pass through the array.
// Space Complexity: O(1) as no additional space is used that scales with input size.

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunkCount = 0;
        int maxValueSoFar = 0;

        for (int i = 0; i < arr.size(); ++i) {
            maxValueSoFar = max(maxValueSoFar, arr[i]);
            // If the current index equals the maximum value seen so far, it's a valid chunk
            if (i == maxValueSoFar) {
                chunkCount++;
            }
        }

        return chunkCount;
    }
};
