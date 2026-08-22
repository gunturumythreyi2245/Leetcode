from functools import cmp_to_key

class Solution:
    def largestNumber(self, nums: list[int]) -> str:
        # Convert all integers to strings
        nums_str = list(map(str, nums))
        
        # Custom compare function: checks if X+Y is larger than Y+X
        def compare(x, y):
            if x + y > y + x:
                return -1
            elif x + y < y + x:
                return 1
            else:
                return 0
                
        # Sort strings using the custom comparator
        nums_str.sort(key=cmp_to_key(compare))
        
        # Join the sorted list into one string
        result = "".join(nums_str)
        
        # Handle edge case where the result is multiple zeros (e.g., "000" -> "0")
        return "0" if result[0] == "0" else result
