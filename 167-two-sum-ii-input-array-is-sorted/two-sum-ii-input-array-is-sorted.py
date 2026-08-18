class Solution:
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        # Initialize two pointers at the ends of the array
        left = 0
        right = len(numbers) - 1
        
        while left < right:
            current_sum = numbers[left] + numbers[right]
            
            # If we found the target, return the 1-indexed positions
            if current_sum == target:
                return [left + 1, right + 1]
            
            # If the sum is too small, move the left pointer right to increase it
            elif current_sum < target:
                left += 1
                
            # If the sum is too large, move the right pointer left to decrease it
            else:
                right -= 1
                
        return []
