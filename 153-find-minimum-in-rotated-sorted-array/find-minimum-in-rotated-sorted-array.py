class Solution:
    def findMin(self, nums: list[int]) -> int:
        left = 0
        right = len(nums) - 1
        
        # Binary search loop
        while left < right:
            mid = (left + right) // 2
            
            # If mid element is greater than right element,
            # the minimum must be in the right half.
            if nums[mid] > nums[right]:
                left = mid + 1
            # Otherwise, the minimum is at mid or in the left half.
            else:
                right = mid
                
        # When left == right, we found the minimum element
        return nums[left]
