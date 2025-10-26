// Problem: Maximum Occurring Character In A String
// Link: https://takeuforward.org/data-structure/maximum-occurring-character-in-a-string/

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Maximum Occurring Character In A String
// Problem: Given a string, return the character that occurs the maximum number of times.

// Approach 1 - Brute Force:
// Count frequency of each character using unordered_map and track the max frequency.
// Time Complexity: O(N) where N is string length (one pass for frequency counting)
// Space Complexity: O(N) in worst case if all characters are distinct

class Solution {
public:
    char maxOccurringChar(string str) {
        unordered_map<char, int> freq;
        int maxCount = 0;
        char maxChar = '\0';

        for (char c : str) {
            freq[c]++;
            if (freq[c] > maxCount) {
                maxCount = freq[c];
                maxChar = c;
            }
        }
        return maxChar;
    }
};

// Approach 2 - Optimized:
// Use a fixed-size frequency array of size 256 (ASCII) to store counts to reduce overhead.
// Time Complexity: O(N) to count + O(256) to find max frequency ~ O(N)
// Space Complexity: O(1) fixed extra space for frequency array regardless of input size

class Solution {
public:
    char maxOccurringChar(string str) {
        vector<int> freq(256, 0);
        int maxCount = 0;
        char maxChar = '\0';

        for (char c : str) {
            freq[c]++;
            if (freq[c] > maxCount) {
                maxCount = freq[c];
                maxChar = c;
            }
        }
        return maxChar;
    }
};
