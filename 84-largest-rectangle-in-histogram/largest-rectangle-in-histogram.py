class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []  # Stores pairs of (index, height)
        max_area = 0
        
        for i, h in enumerate(heights):
            start = i
            # Pop elements from stack if the current bar is shorter than the top of the stack
            while stack and stack[-1][1] > h:
                index, height = stack.pop()
                # Calculate area with the popped height
                max_area = max(max_area, height * (i - index))
                # The current shorter bar can extend backward to the popped index
                start = index
            stack.append((start, h))
            
        # Clear out any remaining bars left in the stack
        for index, height in stack:
            max_area = max(max_area, height * (len(heights) - index))
            
        return max_area
