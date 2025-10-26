// Problem: Huffman Encoding3345
// Link: https://www.geeksforgeeks.org/problems/huffman-encoding3345/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>

// Huffman Encoding
// Problem: Given a string S of distinct characters, compress it using Huffman Coding and return a vector of Huffman codes for each character in the original order.

// Approach 1 - Brute Force: Frequency count and manual sorting, then build tree step-by-step.
// Time Complexity: O(n^2) for frequency counting and manual sorting.
// Space Complexity: O(n) for storing nodes and codes.

class Solution {
    struct Node {
        char data;
        unsigned freq;
        Node *left, *right;
        Node(char d, unsigned f) : data(d), freq(f), left(nullptr), right(nullptr) {}
    };

    struct compare {
        bool operator()(Node* l, Node* r) { return l->freq > r->freq; }
    };

    void getCodes(Node* root, string code, unordered_map<char, string>& codes) {
        if (!root) return;
        if (root->data != '$') codes[root->data] = code;
        getCodes(root->left, code + "0", codes);
        getCodes(root->right, code + "1", codes);
    }

    public:
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        for (int i = 0; i < N; ++i)
            minHeap.push(new Node(S[i], f[i]));

        while (minHeap.size() > 1) {
            Node *left = minHeap.top(); minHeap.pop();
            Node *right = minHeap.top(); minHeap.pop();
            Node *top = new Node('$', left->freq + right->freq);
            top->left = left; top->right = right;
            minHeap.push(top);
        }

        unordered_map<char, string> codes;
        getCodes(minHeap.top(), "", codes);

        vector<string> ans;
        for (char c : S)
            ans.push_back(codes[c]);

        return ans;
    }
};

// Approach 2 - Optimized: Use STL priority_queue and a single pass for code generation.
// Time Complexity: O(n log n) for building the heap and tree.
// Space Complexity: O(n) for nodes and codes.

class Solution {
    struct Node {
        char data;
        unsigned freq;
        Node *left, *right;
        Node(char d, unsigned f) : data(d), freq(f), left(nullptr), right(nullptr) {}
    };

    struct compare {
        bool operator()(Node* l, Node* r) { return l->freq > r->freq; }
    };

    void getCodes(Node* root, string code, unordered_map<char, string>& codes) {
        if (!root) return;
        if (root->data != '$') codes[root->data] = code;
        getCodes(root->left, code + "0", codes);
        getCodes(root->right, code + "1", codes);
    }

    public:
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        for (int i = 0; i < N; ++i)
            minHeap.push(new Node(S[i], f[i]));

        while (minHeap.size() > 1) {
            Node *left = minHeap.top(); minHeap.pop();
            Node *right = minHeap.top(); minHeap.pop();
            Node *top = new Node('$', left->freq + right->freq);
            top->left = left; top->right = right;
            minHeap.push(top);
        }

        unordered_map<char, string> codes;
        getCodes(minHeap.top(), "", codes);

        vector<string> ans;
        for (char c : S)
            ans.push_back(codes[c]);

        return ans;
    }
};
