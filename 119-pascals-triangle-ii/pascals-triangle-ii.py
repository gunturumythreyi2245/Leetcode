class Solution:
    def getRow(self, rowIndex: int) -> list[int]:
        # Initialize the row with 1s of the required size
        row = [1] * (rowIndex + 1)
        
        # Build the triangle row by row, working backward to modify in-place
        for i in range(2, rowIndex + 1):
            for j in range(i - 1, 0, -1):
                row[j] += row[j - 1]
                
        return row
