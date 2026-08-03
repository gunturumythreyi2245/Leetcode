class Solution:
    def stoneGameIII(self, stoneValue: list[int]) -> str:
        n = len(stoneValue)
        # dp[i] stores the max relative score from index i to the end
        # Size n + 1 handles the base case dp[n] = 0
        dp = [0] * (n + 1)
        
        # Iterate backwards from the last stone to the first stone
        for i in range(n - 1, -1, -1):
            take = 0
            max_relative_score = float('-inf')
            
            # The player can choose to take 1, 2, or 3 stones
            for k in range(1, 4):
                if i + k <= n:
                    take += stoneValue[i + k - 1]
                    max_relative_score = max(max_relative_score, take - dp[i + k])
            
            dp[i] = max_relative_score
            
        # Determine the winner based on Alice's relative score advantage
        if dp[0] > 0:
            return "Alice"
        elif dp[0] < 0:
            return "Bob"
        else:
            return "Tie"
