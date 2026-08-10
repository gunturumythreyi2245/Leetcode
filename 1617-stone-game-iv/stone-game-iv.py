class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        # dp[i] represents if the current player can win with i stones remaining
        dp = [False] * (n + 1)
        
        # Iterate through every stone count from 1 to n
        for i in range(1, n + 1):
            k = 1
            # Check all possible perfect square moves from the current pile
            while k * k <= i:
                # If removing k*k stones forces the opponent into a losing state, 
                # then the current player wins this state.
                if not dp[i - k * k]:
                    dp[i] = True
                    break  # Found a winning move, no need to check further
                k += 1
                
        return dp[n]
