// Problem: Maximum Occuring Character 1587115620
// Link: https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/0

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Maximum Occuring Character
// Problem: Given a string, return the maximum occurring character. If there is a tie, returns the lexicographically smaller character.

// Approach 1 - Brute Force:
// Iterate through every character, count its frequency, and keep track of the maximum.
// Time Complexity: O(N^2)
// Space Complexity: O(1)

class Solution {
public:
    char getMaxOccuringChar(string str) {
        char max_char = 'z'; // Initialize to highest ASCII to handle tie
        int max_count = 0;
        int n = str.length();
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (str[j] == str[i]) cnt++;
            }
            if (cnt > max_count || (cnt == max_count && str[i] < max_char)) {
                max_count = cnt;
                max_char = str[i];
            }
        }
        return max_char;
    }
};

// Approach 2 - Optimized:
// Count character frequencies using a 256-element array, traverse once to find the maximum (resolve ties by ASCII).
// Time Complexity: O(N)
// Space Complexity: O(1), uses fixed-size array

class Solution {
public:
    char getMaxOccuringChar(string str) {
        int freq[256] = {0};
        int max_freq = 0;
        char result = 'z'; // Initialize to largest possible for tie resolution
        for (char c : str) {
            freq[c]++;
            // Update if frequency is higher, or if same frequency but lexicographically smaller character
            if (freq[c] > max_freq || (freq[c] == max_freq && c < result)) {
                max_freq = freq[c];
                result = c;
            }
        }
        return result;
    }
};
