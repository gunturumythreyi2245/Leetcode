class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        # Start both pointers at the beginning
        slow = head
        fast = head
        
        # Move through the list
        while fast and fast.next:
            slow = slow.next          # Moves 1 step
            fast = fast.next.next     # Moves 2 steps
            
            # If they meet, there is a cycle
            if slow == fast:
                return True
                
        # If fast reaches the end, there is no cycle
        return False
