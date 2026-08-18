class Solution:
    def trailingZeroes(self, n: int) -> int:
        count = 0
        # Count how many times 5 is a factor in the numbers from 1 to n
        while n > 0:
            n //= 5
            count += n
        return count
