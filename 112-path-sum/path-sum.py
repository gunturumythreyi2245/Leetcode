from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        # Base case: if the node is empty, no path exists
        if not root:
            return False
        
        # Check if it's a leaf node
        if not root.left and not root.right:
            return root.val == targetSum
        
        # Recurse down both subtrees, subtracting the current value from the target
        remaining_sum = targetSum - root.val
        return (self.hasPathSum(root.left, remaining_sum) or 
                self.hasPathSum(root.right, remaining_sum))
