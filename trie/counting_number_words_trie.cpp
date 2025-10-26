// Problem: Counting Number Words Trie
// Link: https://www.geeksforgeeks.org/counting-number-words-trie/

#include <string>
#include <vector>
using namespace std;

// Counting Number Words Trie
// Problem: Given a list of words, count how many words exist in the Trie (dictionary).

// Approach 1 - Brute Force:
// Insert all words in a set and count size.
// Time Complexity: O(N * L) for insertion (N = number of words, L = average word length)
// Space Complexity: O(N * L) for storing all words

#include <unordered_set>

class Solution {
public:
    int countWords(vector<string>& words) {
        unordered_set<string> dict;
        for (auto& w : words) dict.insert(w);
        return (int)dict.size();
    }
};

// Approach 2 - Optimized:
// Use Trie data structure to insert words and count.
// Each unique word is counted by marking its end node only once.
// Time Complexity: O(N * L) for building Trie
// Space Complexity: O(N * L) for Trie nodes

class Solution {
    struct TrieNode {
        TrieNode* children[26]{};
        bool isEnd = false;
    };
    TrieNode* root = new TrieNode();

    void insert(const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->children[idx])
                cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
        cur->isEnd = true;
    }

    int countWordsInTrie(TrieNode* node) {
        if (!node) return 0;
        int count = node->isEnd ? 1 : 0;
        for (auto child : node->children)
            count += countWordsInTrie(child);
        return count;
    }

public:
    int countWords(vector<string>& words) {
        for (auto& w : words) insert(w);
        return countWordsInTrie(root);
    }
};
