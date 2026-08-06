class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0
            
        cols = len(matrix[0])
        heights = [0] * cols
        max_area = 0
        
        for row in matrix:
            # Update the histogram heights for the current row
            for i in range(cols):
                if row[i] == "1":
                    heights[i] += 1
                else:
                    heights[i] = 0  # Ground level resets if broken by a '0'
                    
            # Calculate the max rectangle for the current row's histogram
            max_area = max(max_area, self.largestRectangleArea(heights))
            
        return max_area

    # Helper function from LeetCode 84 (Largest Rectangle in Histogram)
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []  # Stores (index, height)
        max_area = 0
        
        for i, h in enumerate(heights):
            start = i
            while stack and stack[-1][1] > h:
                index, height = stack.pop()
                max_area = max(max_area, height * (i - index))
                start = index
            stack.append((start, h))
            
        for index, height in stack:
            max_area = max(max_area, height * (len(heights) - index))
            
        return max_area
