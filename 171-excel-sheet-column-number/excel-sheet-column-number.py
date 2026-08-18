class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        ans = 0
        
        for char in columnTitle:
            # Convert character to 1-indexed number (A=1, B=2, ..., Z=26)
            # ord('A') is 65, so ord(char) - 64 maps 'A' to 1
            digit_value = ord(char) - 64
            
            # Shift the existing answer to the left by multiplying by 26
            # Then add the new digit value
            ans = ans * 26 + digit_value
            
        return ans
