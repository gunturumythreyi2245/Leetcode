from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Base case: if the list is empty or has only one node, it is already sorted
        if not head or not head.next:
            return head
        
        # Step 1: Split the list into two halves
        mid = self.get_mid(head)
        left = head
        right = mid.next
        mid.next = None  # Break the link between the two halves
        
        # Step 2: Recursively sort both halves
        left_sorted = self.sortList(left)
        right_sorted = self.sortList(right)
        
        # Step 3: Merge the two sorted halves
        return self.merge(left_sorted, right_sorted)
        
    def get_mid(self, head: ListNode) -> ListNode:
        """Finds the middle node using slow and fast pointers."""
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow

    def merge(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        """Merges two sorted linked lists into one."""
        dummy = ListNode(0)
        tail = dummy
        
        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next
            
        # Attach any remaining nodes
        tail.next = list1 if list1 else list2
        return dummy.next
