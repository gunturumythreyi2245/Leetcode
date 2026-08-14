from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Dummy node acts as the start of our new sorted list
        dummy = ListNode(0)
        curr = head
        
        while curr:
            # Save the next node to process later
            next_node = curr.next
            
            # Start from the beginning of the sorted list to find insertion point
            prev = dummy
            while prev.next and prev.next.val < curr.val:
                prev = prev.next
            
            # Insert curr between prev and prev.next
            curr.next = prev.next
            prev.next = curr
            
            # Move to the next node in the original list
            curr = next_node
            
        return dummy.next
