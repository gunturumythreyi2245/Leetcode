class Solution:
    def sortedArrayToBST(self, nums: list[int]) -> TreeNode | None:
        def helper(left: int, right: int) -> TreeNode | None:
            # 1. CRITICAL BASE CASE: Stops recursion when sub-segment is empty
            if left > right:
                return None
            
            # 2. Choose the middle element
            mid = (left + right) // 2
            root = TreeNode(nums[mid])
            
            # 3. Recursively build subtrees
            root.left = helper(left, mid - 1)
            root.right = helper(mid + 1, right)
            
            return root
            
        return helper(0, len(nums) - 1)
