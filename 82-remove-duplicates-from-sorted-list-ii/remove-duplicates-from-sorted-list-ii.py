# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Create a dummy node pointing to the head
        dummy = ListNode(0, head)
        prev = dummy
        
        while head:
            # Check if current node is a duplicate
            if head.next and head.val == head.next.val:
                # Skip all nodes with the same value
                while head.next and head.val == head.next.val:
                    head = head.next
                # Link prev node past all duplicates
                prev.next = head.next
            else:
                # Move prev forward if no duplicates found
                prev = prev.next
                
            # Move head forward
            head = head.next
            
        return dummy.next
