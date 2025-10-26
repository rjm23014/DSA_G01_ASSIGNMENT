// Problem: Merge Two Sorted Lists
// Link: https://leetcode.com/problems/merge-two-sorted-lists/description/

#include <vector>
#include <list> // Though not directly used, it's good practice to include relevant headers.
using namespace std;

// Merge Two Sorted Lists
// Problem: Given the heads of two sorted linked lists, merge them into one sorted list.

// Approach 1 - Recursive:
// Brief explanation: This approach recursively merges the two sorted lists by comparing the head values.
// Time Complexity: O(m + n), where m and n are lengths of the two lists.
// Space Complexity: O(m + n), for recursion call stack.
class Solution {
    public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2) return list1 ? list1 : list2;
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

// Approach 2 - Iterative:
// Brief explanation: This approach iteratively merges the two sorted lists by using a dummy node.
// Time Complexity: O(m + n), where m and n are lengths of the two lists.
// Space Complexity: O(1), auxiliary space.
class Solution {
    public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0); // Dummy node
        ListNode* current = dummy;
        
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        
        // Attach the remaining nodes, if any
        current->next = list1 ? list1 : list2;
        
        return dummy->next;
    }
};
