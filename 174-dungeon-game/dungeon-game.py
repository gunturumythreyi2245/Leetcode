class Solution:
    def calculateMinimumHP(self, dungeon: list[list[int]]) -> int:
        rows = len(dungeon)
        cols = len(dungeon[0])
        
        # Create a DP table filled with infinity
        # Add an extra row and column to handle boundaries easily
        dp = [[float('inf')] * (cols + 1) for _ in range(rows + 1)]
        
        # Base cases: The knight needs at least 1 HP after rescuing the princess
        dp[rows][cols - 1] = 1
        dp[rows - 1][cols] = 1
        
        # Fill the table backward from bottom-right to top-left
        for r in range(rows - 1, -1, -1):
            for c in range(cols - 1, -1, -1):
                # Choose the path that requires less health (down vs right)
                min_health_next = min(dp[r + 1][c], dp[r][c + 1])
                
                # Health needed before entering this cell
                dp[r][c] = min_health_next - dungeon[r][c]
                
                # If the cell gives health (positive), health needed drops.
                # However, the knight must always have at least 1 HP to stay alive.
                if dp[r][c] <= 0:
                    dp[r][c] = 1
                    
        # The answer is the minimum health required at the starting room (0,0)
        return dp[0][0]
