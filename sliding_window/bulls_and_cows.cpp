// Problem: Bulls And Cows
// Link: https://leetcode.com/problems/bulls-and-cows/description/?envType=problem-list-v2&envId=hash-table

#include <string>
#include <vector>
using namespace std;

// Bulls And Cows
// Problem: Count bulls (correct digit in correct position) and cows (correct digit in wrong position) between secret and guess strings

// Approach 1 - Brute Force:
// Check each position for bulls first. Then for each non-bull digit in guess, scan all unmatched secret digits to count cows.
// Time Complexity: O(n^2) due to nested scanning for cows
// Space Complexity: O(n) to track matched indices

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        vector<bool> secret_matched(n, false), guess_matched(n, false);
        int bulls = 0, cows = 0;

        // Count bulls (exact matches)
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                secret_matched[i] = true;
                guess_matched[i] = true;
            }
        }

        // Count cows (value matches but different positions)
        for (int i = 0; i < n; i++) {
            if (guess_matched[i]) continue;
            for (int j = 0; j < n; j++) {
                if (!secret_matched[j] && guess[i] == secret[j]) {
                    cows++;
                    secret_matched[j] = true;
                    break;
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

// Approach 2 - Optimized:
// Count bulls directly. For cows, use frequency array of digits for unmatched chars in secret and guess, then sum minimum counts.
// Time Complexity: O(n), n = length of strings (single pass + frequency count)
// Space Complexity: O(1), fixed size arrays (10 digits only)

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> secret_count(10, 0), guess_count(10, 0);
        int n = secret.size();

        // Count bulls and frequencies for unmatched digits
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                secret_count[secret[i] - '0']++;
                guess_count[guess[i] - '0']++;
            }
        }

        // Count cows by summing the minimum frequency of each digit in secret and guess
        for (int i = 0; i < 10; i++) {
            cows += min(secret_count[i], guess_count[i]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
