// Problem: Implement Trie Prefix Tree
// Link: https://leetcode.com/problems/implement-trie-prefix-tree/description/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Implement Trie Prefix Tree
// Problem: Implement a Trie data structure with insert, search, and startsWith methods.

// Approach 1 - Brute Force:
// This approach is not efficient for Trie as it involves checking every string in a list.
// Time Complexity: O(N * M) where N is the number of words and M is the maximum length of a word.
// Space Complexity: O(N * M)

class SolutionBrute {
    public:
    vector<string> words;
    
    void insert(string word) {
        words.push_back(word);
    }
    
    bool search(string word) {
        for (const auto& w : words) {
            if (w == word) return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        for (const auto& w : words) {
            if (w.find(prefix) == 0) return true;
        }
        return false;
    }
};

// Approach 2 - Optimized:
// This approach uses a Trie to efficiently store and retrieve words.
// Time Complexity: O(M) where M is the length of the word.
// Space Complexity: O(N * M) where N is the number of words and M is the average length of a word.

class TrieNode {
    public:
    unordered_map<char, TrieNode*> children;
    bool isWord;
    
    TrieNode() : isWord(false) {}
};

class SolutionOptimized {
    private:
    TrieNode* root;
    
    public:
    SolutionOptimized() : root(new TrieNode()) {}
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) return false;
            node = node->children[c];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children.count(c)) return false;
            node = node->children[c];
        }
        return true;
    }
};
