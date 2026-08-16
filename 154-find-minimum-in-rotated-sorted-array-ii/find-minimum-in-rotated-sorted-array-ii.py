class Solution:
    def findMin(self, nums: list[int]) -> int:
        left = 0
        right = len(nums) - 1
        
        while left < right:
            mid = (left + right) // 2
            
            # Case 1: Minimum is in the right half
            if nums[mid] > nums[right]:
                left = mid + 1
            # Case 2: Minimum is at mid or in the left half
            elif nums[mid] < nums[right]:
                right = mid
            # Case 3: Duplicates found! Reduce search space by 1
            else:
                right -= 1
                
        return nums[left]
