import collections

class Solution:
    def stoneGameIX(self, stones: list[int]) -> bool:
        # Group stones by their remainder when divided by 3
        count = collections.Counter(stone % 3 for stone in stones)
        
        # Scenario 1: Even number of remainder-0 stones
        if count[0] % 2 == 0:
            return min(count[1], count[2]) > 0
            
        # Scenario 2: Odd number of remainder-0 stones
        return abs(count[1] - count[2]) > 2
