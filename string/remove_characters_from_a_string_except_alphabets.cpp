// Problem: Remove Characters From A String Except Alphabets
// Link: https://takeuforward.org/data-structure/remove-characters-from-a-string-except-alphabets/

#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

// Remove Characters From A String Except Alphabets
// Problem: Given a string, remove all non-alphabet characters and return the resulting string

// Approach 1 - Brute Force:
// Iterate through the string, erase characters that are not alphabets in place
// Time Complexity: O(n^2) due to repeated erase operations shifting the string
// Space Complexity: O(1) (in-place modification)

class Solution {
public:
    string removeCharacters(string s) {
        for (int i = 0; i < (int)s.size(); i++) {
            if (!isalpha(s[i])) {
                s.erase(i, 1);
                i--; // Adjust index after erase
            }
        }
        return s;
    }
};

// Approach 2 - Optimized:
// Use std::remove_if with erase to efficiently remove non-alphabet characters
// Time Complexity: O(n) since remove_if + erase is linear
// Space Complexity: O(1) in-place modification

class Solution {
public:
    string removeCharacters(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return !isalpha(static_cast<unsigned char>(c));
        }), s.end());
        return s;
    }
};
