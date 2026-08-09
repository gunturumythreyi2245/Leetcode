from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        curr = root
        
        while curr:
            if curr.left:
                # Find the rightmost node in the left subtree
                predecessor = curr.left
                while predecessor.right:
                    predecessor = predecessor.right
                
                # Connect the original right subtree to the rightmost node
                predecessor.right = curr.right
                
                # Move the entire left subtree to the right side
                curr.right = curr.left
                curr.left = None
            
            # Move on to the next node on the right side
            curr = curr.right
