class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        if n <= 1:
            return 0
            
        # Step 1: Initialize the palindrome lookup table
        is_pal = [[False] * n for _ in range(n)]
        
        # Fill the palindrome table
        for length in range(1, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                if s[i] == s[j]:
                    if length <= 2 or is_pal[i + 1][j - 1]:
                        is_pal[i][j] = True
                        
        # Step 2: Initialize cuts array
        cuts = [i for i in range(n)]
        
        for i in range(n):
            # Check if the prefix s[0...i] is a palindrome
            if is_pal[0][i]:
                cuts[i] = 0
                continue
                
            # Check all possible partition points
            for j in range(1, i + 1):
                if is_pal[j][i]:
                    cuts[i] = min(cuts[i], cuts[j - 1] + 1)
                    
        return cuts[n - 1]
