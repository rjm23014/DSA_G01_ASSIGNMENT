// Problem: Binary Tree Postorder Traversal
// Link: https://leetcode.com/problems/binary-tree-postorder-traversal/

#include <vector>
#include <stack>
using namespace std;

// Binary Tree Postorder Traversal
// Problem: Given the root of a binary tree, return the postorder traversal of its nodes' values.

// Approach 1 - Brute Force:
// Recursive postorder traversal: visit left subtree, right subtree, then root.
// Time Complexity: O(N), where N is number of nodes.
// Space Complexity: O(H) due to recursion stack, H = height of tree.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
private:
    void postorder(TreeNode* node, vector<int>& res) {
        if (!node) return;
        postorder(node->left, res);
        postorder(node->right, res);
        res.push_back(node->val);
    }
};

// Approach 2 - Optimized:
// Iterative postorder traversal using one stack.
// Simulates recursion with explicit stack and tracks previously visited node.
// Time Complexity: O(N).
// Space Complexity: O(H), H = height of tree (stack space).

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> st;
        TreeNode* prev = nullptr;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();

            // Go down the tree
            if (!prev || prev->left == curr || prev->right == curr) {
                if (curr->left)
                    st.push(curr->left);
                else if (curr->right)
                    st.push(curr->right);
                else {
                    result.push_back(curr->val);
                    st.pop();
                }
            }
            // Going up from left child
            else if (curr->left == prev) {
                if (curr->right)
                    st.push(curr->right);
                else {
                    result.push_back(curr->val);
                    st.pop();
                }
            }
            // Going up from right child
            else if (curr->right == prev) {
                result.push_back(curr->val);
                st.pop();
            }

            prev = curr;
        }

        return result;
    }
};
