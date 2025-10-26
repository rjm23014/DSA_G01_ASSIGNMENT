// Problem: Count Elements With Maximum Frequency
// Link: https://leetcode.com/problems/count-elements-with-maximum-frequency/description/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Count Elements With Maximum Frequency
// Problem: Given an array nums, return the sum of frequencies of all elements that occur with the maximum frequency.

// Approach 1 - Brute Force:
// Count frequencies using a map, find the maximum frequency, then sum frequencies of all elements that have this max frequency.
// Time Complexity: O(N) where N is the size of nums
// Space Complexity: O(N) for the map storing frequencies

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int maxFreq = 0;
        for (const auto& p : freq) {
            if (p.second > maxFreq) maxFreq = p.second;
        }
        int count = 0;
        for (const auto& p : freq) {
            if (p.second == maxFreq) count += p.second;
        }
        return count;
    }
};

// Approach 2 - Optimized:
// Use a frequency array since the problem constraints or examples suggest nums contains positive integers within a known range (e.g., 1 to 100).
// Directly count frequencies in an array, find the max, and sum.
// Time Complexity: O(N) due to single pass count + constant pass over fixed-size frequency array
// Space Complexity: O(1) fixed-size frequency array

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        constexpr int maxVal = 100; // Assuming nums[i] in [1, 100]
        int frequency[maxVal + 1] = {0};
        for (int num : nums) frequency[num]++;
        int maxFreq = 0, count = 0;
        for (int i = 1; i <= maxVal; i++) {
            if (frequency[i] > maxFreq) {
                maxFreq = frequency[i];
                count = frequency[i];
            } else if (frequency[i] == maxFreq) {
                count += frequency[i];
            }
        }
        return count;
    }
};
