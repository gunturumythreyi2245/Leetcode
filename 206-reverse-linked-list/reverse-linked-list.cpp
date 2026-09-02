/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // Temporarily store the next node
            curr->next = prev;               // Reverse the current node's pointer
            prev = curr;                     // Move prev forward
            curr = nextNode;                 // Move curr forward
        }
        return prev; // prev will point to the new head of the reversed list
    }
};
