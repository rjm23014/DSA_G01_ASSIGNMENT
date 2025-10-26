// Problem: Top K Frequent Elements
// Link: https://leetcode.com/problems/top-k-frequent-elements/

#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

// Top K Frequent Elements
// Problem: Return the k most frequent elements in the array

// Approach 1 - Brute Force:
// Count frequencies, then sort elements by frequency
// Time Complexity: O(n log n), where n is the number of elements
// Space Complexity: O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;
        
        vector<pair<int, int>> freqVec(freq.begin(), freq.end());
        // Sort descending by frequency
        sort(freqVec.begin(), freqVec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqVec[i].first);
        }
        return result;
    }
};

// Approach 2 - Optimized:
// Use a min-heap of size k to keep top k frequent elements while iterating frequencies
// Time Complexity: O(n log k), n = nums size
// Space Complexity: O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;
        
        // Min-heap ordered by frequency
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (auto& [num, count] : freq) {
            minHeap.emplace(count, num);
            if ((int)minHeap.size() > k) minHeap.pop();
        }
        
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(result.begin(), result.end()); // optional: largest freq first
        return result;
    }
};
