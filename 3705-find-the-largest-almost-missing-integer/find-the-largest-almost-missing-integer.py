from collections import Counter

class Solution:
    def largestInteger(self, nums: list[int], k: int) -> int:
        n = len(nums)
        
        # Case 1: The window covers the entire array.
        # There is exactly 1 window, so every element appears in exactly 1 window.
        # The answer is simply the maximum element in the entire array.
        if k == n:
            return max(nums)
        
        # Count the absolute occurrences of each number in the array.
        counts = Counter(nums)
        
        # Case 2: The window size is 1.
        # Each window isolates exactly one element. 
        # An element appears in exactly one window only if its global frequency is 1.
        if k == 1:
            unique_nums = [num for num, count in counts.items() if count == 1]
            return max(unique_nums) if unique_nums else -1
            
        # Case 3: 1 < k < n
        # Middle elements will always belong to at least 2 sliding windows.
        # Only the first element and the last element can belong to exactly 1 window.
        # They are eligible only if their global frequency in the array is 1.
        ans = -1
        if counts[nums[0]] == 1:
            ans = max(ans, nums[0])
        if counts[nums[-1]] == 1:
            ans = max(ans, nums[-1])
            
        return ans
