// Problem: Calculate Frequency Of Characters In A String
// Link: https://takeuforward.org/data-structure/calculate-frequency-of-characters-in-a-string/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Calculate Frequency Of Characters In A String
// Problem: Given a string, calculate and return the frequency of each character.

// Approach 1 - Brute Force:
// Use nested loops to count frequency of each character by iterating through the string repeatedly.
// Time Complexity: O(n^2) (n = length of string)
// Space Complexity: O(n) (for storing result)

class Solution {
public:
    vector<pair<char,int>> findFrequency(string str) {
        vector<pair<char,int>> freq;
        int n = (int)str.size();
        vector<bool> counted(n, false);

        for (int i = 0; i < n; i++) {
            if (counted[i]) continue;
            int count = 1;
            for (int j = i+1; j < n; j++) {
                if (str[i] == str[j]) {
                    count++;
                    counted[j] = true;
                }
            }
            freq.push_back({str[i], count});
        }
        return freq;
    }
};

// Approach 2 - Optimized:
// Use an unordered_map to count frequencies in a single pass over the string.
// Time Complexity: O(n)
// Space Complexity: O(k) (k = distinct characters in string)

class Solution {
public:
    vector<pair<char,int>> findFrequency(string str) {
        unordered_map<char,int> freqMap;
        for(char c : str) {
            freqMap[c]++;
        }
        vector<pair<char,int>> freq(freqMap.begin(), freqMap.end());
        return freq;
    }
};
