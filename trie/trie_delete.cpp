// Problem: Trie Delete
// Link: https://www.geeksforgeeks.org/trie-delete/

#include <vector>
#include <string>
#include <memory>
using namespace std;

// Trie Delete
// Problem: Given a trie root, delete the key from the trie if it exists.

// Approach 1 - Brute Force: Rebuild the trie from scratch after removing the key.
// Time Complexity: O(total characters in all keys)
// Space Complexity: O(total characters in all keys)

class Solution {
public:
    struct TrieNode {
        TrieNode *children[26] = {};
        bool isEnd = false;
    };

    void insert(TrieNode* root, const string& key) {
        for (char c : key) {
            int idx = c - 'a';
            if (!root->children[idx]) root->children[idx] = new TrieNode();
            root = root->children[idx];
        }
        root->isEnd = true;
    }

    void collectKeys(TrieNode* root, string &path, vector<string>& keys) {
        if (root->isEnd) keys.push_back(path);
        for (int i = 0; i < 26; ++i) {
            if (root->children[i]) {
                path.push_back('a' + i);
                collectKeys(root->children[i], path, keys);
                path.pop_back();
            }
        }
    }

    void deleteTrie(TrieNode* root) {
        if (!root) return;
        for (int i = 0; i < 26; ++i) {
            deleteTrie(root->children[i]);
        }
        delete root;
    }

    TrieNode* deleteKey(TrieNode* root, string key) {
        // Collect all keys except the one to delete
        vector<string> keys;
        string path;
        collectKeys(root, path, keys);
        // Delete the entire trie
        deleteTrie(root);
        root = new TrieNode();
        // Rebuild trie without the key to delete
        for (const auto& k : keys) {
            if (k != key) insert(root, k);
        }
        return root;
    }
};

// Approach 2 - Optimized: Delete key in place by recursively pruning unused nodes.
// Time Complexity: O(n), where n is length of key
// Space Complexity: O(n) for recursion stack (could be O(1) tail recursive)

class Solution {
public:
    struct TrieNode {
        TrieNode *children[26] = {};
        bool isEnd = false;
    };

    bool isEmpty(TrieNode* node) {
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) return false;
        }
        return true;
    }

    TrieNode* deleteHelper(TrieNode* root, const string& key, int depth = 0) {
        if (!root) return nullptr;

        // Base case: reached end of key
        if (depth == key.length()) {
            if (root->isEnd) root->isEnd = false;
            // If node is not part of any other key, delete it
            if (isEmpty(root)) {
                delete root;
                return nullptr;
            }
            return root;
        }

        // Recur for the child
        int idx = key[depth] - 'a';
        root->children[idx] = deleteHelper(root->children[idx], key, depth + 1);

        // If the current node is not a leaf and became empty, delete it
        if (root != nullptr && !root->isEnd && isEmpty(root)) {
            delete root;
            return nullptr;
        }
        return root;
    }

    TrieNode* deleteKey(TrieNode* root, string key) {
        return deleteHelper(root, key);
    }
};
