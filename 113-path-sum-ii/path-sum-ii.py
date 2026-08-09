from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        result = []
        
        def dfs(node: Optional[TreeNode], current_sum: int, current_path: List[int]):
            if not node:
                return
            
            # Action: include the current node in our path tracking
            current_path.append(node.val)
            current_sum += node.val
            
            # Condition: If it's a leaf node, check if the path matches targetSum
            if not node.left and not node.right:
                if current_sum == targetSum:
                    result.append(list(current_path)) # Append a deep copy
            else:
                # Continue down left and right subtrees
                dfs(node.left, current_sum, current_path)
                dfs(node.right, current_sum, current_path)
            
            # Backtrack: remove the current node before returning up the tree
            current_path.pop()
            
        dfs(root, 0, [])
        return result
