# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Start at the head of the list
        current = head
        
        while current and current.next:
            # If the next node has the same value, skip it
            if current.val == current.next.val:
                current.next = current.next.next
            else:
                # Otherwise, move to the next distinct node
                current = current.next
                
        return head
