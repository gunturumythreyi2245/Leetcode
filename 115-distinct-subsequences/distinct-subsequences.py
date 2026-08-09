class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        
        # dp[j] stores the number of distinct subsequences of s that match t[:j]
        # Base case: An empty string t[:0] matches any prefix of s in exactly 1 way
        dp = [1] + [0] * n
        
        for char_s in s:
            # Iterate backwards to use values from the previous state of the array
            for j in range(n, 0, -1):
                if char_s == t[j - 1]:
                    dp[j] += dp[j - 1]
                    
        return dp[n]
