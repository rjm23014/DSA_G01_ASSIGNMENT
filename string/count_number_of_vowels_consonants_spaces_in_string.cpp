// Problem: Count Number Of Vowels Consonants Spaces In String
// Link: https://takeuforward.org/data-structure/count-number-of-vowels-consonants-spaces-in-string/

#include <string>
using namespace std;

// Count Number Of Vowels Consonants Spaces In String
// Problem: Given a string, count the number of vowels, consonants, and spaces.

// Approach 1 - Brute Force:
// Iterate through each character and check vowels, consonants, and spaces via explicit conditions.
// Time Complexity: O(n), where n = length of string
// Space Complexity: O(1)

class Solution {
public:
    vector<int> countVowelsConsonantsSpaces(string str) {
        int vowels = 0, consonants = 0, spaces = 0;
        for (char c : str) {
            if (c == ' '){
                spaces++;
            } else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' 
                    || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                vowels++;
            } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                consonants++;
            }
        }
        return {vowels, consonants, spaces};
    }
};

// Approach 2 - Optimized:
// Use a set to store vowels for O(1) membership check, reduce condition checks.
// Time Complexity: O(n), where n = length of string
// Space Complexity: O(1)

#include <unordered_set>

class Solution {
public:
    vector<int> countVowelsConsonantsSpaces(string str) {
        unordered_set<char> vowelsSet = {'a','e','i','o','u','A','E','I','O','U'};
        int vowels = 0, consonants = 0, spaces = 0;
        for (char c : str) {
            if (c == ' ') {
                spaces++;
            } else if (vowelsSet.count(c)) {
                vowels++;
            } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                consonants++;
            }
        }
        return {vowels, consonants, spaces};
    }
};
