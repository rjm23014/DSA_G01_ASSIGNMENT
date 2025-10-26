// Problem: Applications Advantages And Disadvantages Of Trie
// Link: https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-trie/

#include <vector>
#include <string>
using namespace std;

// Applications Advantages And Disadvantages Of Trie
// Problem: Describe applications, advantages, and disadvantages of the Trie data structure.

// Approach 1 - Brute Force:
// Use a sorted vector of strings and linear search with string operations.
// Time Complexity: O(N*L) per operation (N = number of strings, L = avg length)
// Space Complexity: O(N*L)

class Solution {
    vector<string> data;
public:
    // Insert word to sorted vector
    void insert(string word) {
        data.push_back(word); // Not actually maintaining sorted order for clarity/simplicity
    }

    // Search via linear scan
    bool search(string word) {
        for (string& s : data)
            if (s == word) return true;
        return false;
    }

    // Check if any string starts with prefix
    bool startsWith(string prefix) {
        for (string& s : data)
            if (s.substr(0, prefix.size()) == prefix) return true;
        return false;
    }
};

// Approach 2 - Optimized:
// Implement Trie with efficient insertion/search/prefix operations.
// Time Complexity: O(L) per operation (L = length of string)
// Space Complexity: O(26^L) in worst case, but O(N*L) in practice

class Solution {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };
    TrieNode* root;

public:
    Solution() : root(new TrieNode()) {}

    // Insert into trie
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    // Search for complete word in trie
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    // Search if any word starts with prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};
