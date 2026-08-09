"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return root
        
        curr = root  # Track the current node in the current level
        
        while curr:
            dummy = Node(0)  # Dummy node to track the head of the next level
            prev = dummy     # Pointer to build the links in the next level
            
            # Iterate through the current level using the established 'next' links
            while curr:
                if curr.left:
                    prev.next = curr.left
                    prev = prev.next
                if curr.right:
                    prev.next = curr.right
                    prev = prev.next
                curr = curr.next  # Move horizontally across the current level
            
            # Move down to the start of the newly connected next level
            curr = dummy.next
            
        return root

