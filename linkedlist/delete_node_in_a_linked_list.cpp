// Problem: Delete Node In A Linked List
// Link: https://leetcode.com/problems/delete-node-in-a-linked-list/description/

// Definition for singly-linked list node used by the solution.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

// Approach:
// We cannot access the node before the one to delete, so overwrite the current
// node with its successor and unlink that successor. This assumes the node is
// not the tail (per problem constraints).
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
	void deleteNode(ListNode* node) {
		if (!node || !node->next) {
			return; // Nothing to do if node is null or tail (invalid per constraints).
		}
		node->val = node->next->val;      // Copy value from next node.
		ListNode* to_delete = node->next; // Save pointer to remove.
		node->next = node->next->next;    // Bypass the next node.
		delete to_delete;                 // Free the removed node.
	}
};
