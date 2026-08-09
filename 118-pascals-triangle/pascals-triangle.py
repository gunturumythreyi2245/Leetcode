class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        triangle = []
        
        for i in range(numRows):
            # Create a row filled with 1s of size (i + 1)
            row = [1] * (i + 1)
            
            # Update the inner elements (excluding the first and last elements)
            for j in range(1, i):
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
                
            triangle.append(row)
            
        return triangle
