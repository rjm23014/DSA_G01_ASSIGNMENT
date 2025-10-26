// Problem: Find All Anagrams In A String
// Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Find All Anagrams In A String
// Problem: Given two strings s and p, return all start indices of p's anagrams in s.

// Approach 1 - Brute Force:
// Generates all substrings of s with length equal to p and checks if they are anagrams of p.
// Time Complexity: O(n*m*log(m)) due to sorting each substring.
// Space Complexity: O(n*m) for storing substrings and their sorted versions.

class BruteForceSolution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int n = s.length(), m = p.length();
        
        // Generate all substrings of s with length m
        for (int i = 0; i <= n - m; ++i) {
            string substr = s.substr(i, m);
            
            // Check if the substring is an anagram of p
            if (isAnagram(substr, p)) {
                result.push_back(i);
            }
        }
        
        return result;
    }
    
    bool isAnagram(const string& s1, const string& s2) {
        if (s1.length() != s2.length()) return false;
        
        string sorted1 = s1;
        string sorted2 = s2;
        
        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());
        
        return sorted1 == sorted2;
    }
};

// Approach 2 - Optimized (Sliding Window):
// Uses a sliding window to efficiently check for anagrams by comparing character frequencies.
// Time Complexity: O(n) because we only need to iterate through the string once.
// Space Complexity: O(1) since we use a fixed-size hash map to store letter frequencies.

class OptimizedSolution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int n = s.length(), m = p.length();
        
        if (n < m) return result; // p cannot be an anagram in s
        
        // Create frequency maps for s and p
        unordered_map<char, int> sCount, pCount;
        
        // Initialize pCount
        for (char c : p) {
            pCount[c]++;
        }
        
        // Window boundaries
        int left = 0;
        
        // Initialize the window
        for (int i = 0; i < n; ++i) {
            sCount[s[i]]++;
            
            // Shrink the window if necessary
            if (i >= m) {
                sCount[s[left]]--;
                if (sCount[s[left]] == 0) {
                    sCount.erase(s[left]);
                }
                left++;
            }
            
            // Check if the current window is an anagram of p
            if (sCount == pCount) {
                result.push_back(left);
            }
        }
        
        return result;
    }
};
