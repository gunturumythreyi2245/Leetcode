class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        ROWS, COLS = len(board), len(board[0])
        
        def dfs(r: int, c: int, index: int) -> bool:
            # Base Case: found all letters
            if index == len(word):
                return True
                
            # Boundary check and character mismatch check
            if (r < 0 or r >= ROWS or 
                c < 0 or c >= COLS or 
                board[r][c] != word[index]):
                return False
            
            # Mark the current cell as visited
            temp = board[r][c]
            board[r][c] = "#"
            
            # Explore all 4 adjacent directions
            found = (dfs(r + 1, c, index + 1) or
                     dfs(r - 1, c, index + 1) or
                     dfs(r, c + 1, index + 1) or
                     dfs(r, c - 1, index + 1))
            
            # Backtrack: restore original character
            board[r][c] = temp
            
            return found

        # Try to start DFS from every cell in the grid
        for r in range(ROWS):
            for c in range(COLS):
                if dfs(r, c, 0):
                    return True
                    
        return False
