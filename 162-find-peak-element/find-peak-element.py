class Solution:
    def findPeakElement(self, nums: list[int]) -> int:
        left = 0
        right = len(nums) - 1
        
        # Perform binary search
        while left < right:
            mid = (left + right) // 2
            
            # If mid element is smaller than its right neighbor, 
            # we are on an upward slope. A peak must be to the right.
            if nums[mid] < nums[mid + 1]:
                left = mid + 1
            # Otherwise, we are on a downward slope. 
            # A peak could be mid itself or to the left.
            else:
                right = mid
                
        # left and right converge to a peak element index
        return left
