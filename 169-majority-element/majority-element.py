class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        candidate = None
        count = 0
        
        for num in nums:
            # If count drops to 0, pick the current number as the new candidate
            if count == 0:
                candidate = num
                
            # If the current number matches our candidate, gain a vote
            if num == candidate:
                count += 1
            # If it does not match, lose a vote
            else:
                count -= 1
                
        return candidate
