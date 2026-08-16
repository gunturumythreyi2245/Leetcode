class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        # Initialize the global max with the first element
        global_max = nums[0]
        
        # Keep track of the current max and min products
        curr_max = nums[0]
        curr_min = nums[0]
        
        for i in range(1, len(nums)):
            num = nums[i]
            
            # Temporary variable to hold curr_max before it gets updated
            temp_max = max(num, curr_max * num, curr_min * num)
            
            # Update current min using the old curr_max
            curr_min = min(num, curr_max * num, curr_min * num)
            
            # Update current max
            curr_max = temp_max
            
            # Update the highest product found so far
            global_max = max(global_max, curr_max)
            
        return global_max
