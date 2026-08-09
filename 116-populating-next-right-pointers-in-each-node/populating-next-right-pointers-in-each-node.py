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
        
        # Start with the root node
        leftmost = root
        
        # Loop down the left side of the tree level by level
        while leftmost.left:
            # Iterate through the current level using the 'next' pointers
            head = leftmost
            while head:
                # Connection 1: Connect left child to right child of the same parent
                head.left.next = head.right
                
                # Connection 2: Connect right child to the left child of the next sibling
                if head.next:
                    head.right.next = head.next.left
                
                # Move to the next node in the current level
                head = head.next
                
            # Move to the next level down
            leftmost = leftmost.left
            
        return root
