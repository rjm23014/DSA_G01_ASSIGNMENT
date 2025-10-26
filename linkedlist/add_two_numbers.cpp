// Problem: Add Two Numbers
// Link: https://leetcode.com/problems/add-two-numbers/description/

#include <iostream>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Add Two Numbers
// Problem: Add two numbers represented by two linked lists in reverse order and return the sum as a linked list.

// Approach 1 - Brute Force:
// Convert linked lists to integers, add them, then convert sum back to linked list.
// Time Complexity: O(m + n) due to list traversal and integer to list conversion (could be limited by large number handling).
// Space Complexity: O(m + n) for storing output list and integer conversions (potentially large).

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Convert l1 to number
        long long num1 = 0, place = 1;
        while (l1) {
            num1 += l1->val * place;
            place *= 10;
            l1 = l1->next;
        }
        // Convert l2 to number
        long long num2 = 0;
        place = 1;
        while (l2) {
            num2 += l2->val * place;
            place *= 10;
            l2 = l2->next;
        }
        long long sum = num1 + num2;
        
        // Special case if sum == 0
        if (sum == 0) return new ListNode(0);

        // Convert sum back to linked list
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        while (sum > 0) {
            int digit = sum % 10;
            ListNode* node = new ListNode(digit);
            if (!head) {
                head = curr = node;
            } else {
                curr->next = node;
                curr = curr->next;
            }
            sum /= 10;
        }
        return head;
    }
};

// Approach 2 - Optimized:
// Simulate grade-school addition directly on the linked lists digit-by-digit using carry.
// Time Complexity: O(max(m, n)) where m, n are lengths of two lists.
// Space Complexity: O(max(m, n)) for the output linked list.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        return dummy.next;
    }
};
