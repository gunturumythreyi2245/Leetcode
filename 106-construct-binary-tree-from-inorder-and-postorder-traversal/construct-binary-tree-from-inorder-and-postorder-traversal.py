# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, inorder: list[int], postorder: list[int]) -> TreeNode | None:
        # Pre-compute indices to achieve O(1) lookups
        in_map = {val: idx for idx, val in enumerate(inorder)}
        
        def dfs(left: int, right: int) -> TreeNode | None:
            # 1. CRITICAL BASE CASE: Prevents infinite recursion and IndexErrors
            if left > right:
                return None
            
            # 2. Extract the current root value from the end of postorder
            root_val = postorder.pop()
            root = TreeNode(root_val)
            
            # 3. Locate the root position in the inorder sequence
            mid = in_map[root_val]
            
            # 4. ALWAYS build the right subtree first when popping from postorder
            root.right = dfs(mid + 1, right)
            root.left = dfs(left, mid - 1)
            
            return root
            
        # 5. Kick off the recursion with the initial boundaries
        return dfs(0, len(inorder) - 1)
