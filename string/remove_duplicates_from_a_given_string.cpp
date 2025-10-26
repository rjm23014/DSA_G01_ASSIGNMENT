// Problem: Remove Duplicates From A Given String
// Link: https://www.geeksforgeeks.org/remove-duplicates-from-a-given-string/

#include <string>
#include <unordered_set>
using namespace std;

// Remove Duplicates From A Given String
// Problem: Remove all duplicate characters from the input string retaining the original order

// Approach 1 - Brute Force:
// Check for each character if it appeared before by scanning all previous characters.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    string removeDuplicates(string s) {
        int n = (int)s.size();
        int index = 0; // Index for placing unique characters
        for (int i = 0; i < n; i++) {
            int j;
            for (j = 0; j < i; j++) {
                if (s[i] == s[j])
                    break;
            }
            if (j == i)  // Character s[i] not found before i
                s[index++] = s[i];
        }
        s.resize(index);
        return s;
    }
};

// Approach 2 - Optimized:
// Use an unordered_set to track seen characters for O(1) average lookup, building result in one pass.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string removeDuplicates(string s) {
        unordered_set<char> seen;
        string result;
        for (char c : s) {
            if (seen.find(c) == seen.end()) {
                seen.insert(c);
                result += c;
            }
        }
        return result;
    }
};
