class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        ones = 0
        twos = 0
        
        for num in nums:
            # Update twos with bits that have appeared twice
            twos |= ones & num
            # Update ones with bits that have appeared once
            ones ^= num
            # Find bits that have appeared three times
            threes = ones & twos
            # Clear bits that have appeared three times from ones and twos
            ones &= ~threes
            # Clear bits that have appeared three times from twos
            twos &= ~threes
            
        return ones
