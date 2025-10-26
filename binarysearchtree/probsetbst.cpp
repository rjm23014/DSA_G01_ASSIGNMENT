// Problem: Probsetbst
// Link: https://mathcenter.oxford.emory.edu/site/cs171/probSetBst/

#include <vector>
#include <stack>
using namespace std;

// [Find Inorder Successor in BST]
// Problem: Given the root of a BST and a node value, find its in-order successor.

// Approach 1 - Brute Force (Recursive Inorder Traversal):
// Collect nodes via inorder (left-root-right), then scan for successor.
// Time Complexity: O(N)
// Space Complexity: O(N) for recursion stack and storage

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> inorder;
        inOrder(root, inorder);
        for (int i = 0; i < inorder.size() - 1; ++i)
            if (inorder[i] == p) return inorder[i+1];
        return nullptr;
    }
    void inOrder(TreeNode* root, vector<TreeNode*>& res) {
        if (!root) return;
        inOrder(root->left, res);
        res.push_back(root);
        inOrder(root->right, res);
    }
};

// Approach 2 - Optimized (Iterative Inorder Traversal):
// Traverse BST left-root-right, keeping track of the previous node.
// Return the current node when prev is p.
// Time Complexity: O(N) worst, O(H) average (closest to O(log N) for balanced BST)
// Space Complexity: O(H) stack space

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> st;
        TreeNode* prev = nullptr;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (prev == p) return root;
            prev = root;
            root = root->right;
        }
        return nullptr;
    }
};
