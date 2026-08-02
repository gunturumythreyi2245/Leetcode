class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        
        def backtrack(index: int, current_subset: List[int]):
            # Every state reached in the decision tree is a valid subset
            result.append(list(current_subset))
            
            for i in range(index, len(nums)):
                # Include the current number
                current_subset.append(nums[i])
                # Move to the next element
                backtrack(i + 1, current_subset)
                # Backtrack: exclude the current number
                current_subset.pop()
                
        backtrack(0, [])
        return result
