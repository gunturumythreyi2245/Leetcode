class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        ans = []
        
        while columnNumber > 0:
            # Shift by 1 to map 1-26 to 0-25 for 0-indexed character math
            columnNumber -= 1
            
            # Find the remainder to isolate the current rightmost character
            remainder = columnNumber % 26
            
            # Convert 0-25 into 'A'-'Z' and add to list
            ans.append(chr(65 + remainder))
            
            # Divide by 26 to move to the next position on the left
            columnNumber //= 26
            
        # Reverse the list because characters were collected right-to-left
        return "".join(reversed(ans))
