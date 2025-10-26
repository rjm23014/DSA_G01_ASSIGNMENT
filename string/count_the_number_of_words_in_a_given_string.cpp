// Problem: Count The Number Of Words In A Given String
// Link: https://takeuforward.org/data-structure/count-the-number-of-words-in-a-given-string/

#include <string>
#include <cctype>
using namespace std;

// Count The Number Of Words In A Given String
// Problem: Count the total number of words in the input string.

// Approach 1 - Brute Force:
// Iterate through the string and count transitions from characters to spaces to detect words.
// Time Complexity: O(n), where n is string length
// Space Complexity: O(1)

class Solution {
public:
    int countWords(string str) {
        int count = 0;
        bool inWord = false;
        for (char ch : str) {
            if (!isspace(static_cast<unsigned char>(ch))) {
                if (!inWord) {
                    count++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }
        }
        return count;
    }
};

// Approach 2 - Optimized:
// Use std::stringstream to split words which internally handles multiple spaces efficiently.
// Time Complexity: O(n), where n is string length
// Space Complexity: O(n) for stringstream buffer

#include <sstream>

class Solution {
public:
    int countWords(string str) {
        stringstream ss(str);
        string word;
        int count = 0;
        while (ss >> word) count++;
        return count;
    }
};
