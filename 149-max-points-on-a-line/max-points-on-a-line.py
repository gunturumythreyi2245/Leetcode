import math
from collections import defaultdict
from typing import List

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        # If there are 2 or fewer points, they always form a line
        if n <= 2:
            return n
            
        max_points = 1
        
        for i in range(n):
            slopes = defaultdict(int)
            x1, y1 = points[i]
            
            for j in range(i + 1, n):
                x2, y2 = points[j]
                
                # Calculate rise and run
                dx = x2 - x1
                dy = y2 - y1
                
                # Simplify the slope fraction using GCD
                gcd = math.gcd(dx, dy)
                slope = (dx // gcd, dy // gcd)
                
                # Ensure direction is consistent (e.g., (-1, -2) becomes (1, 2))
                if slope[0] < 0 or (slope[0] == 0 and slope[1] < 0):
                    slope = (-slope[0], -slope[1])
                
                slopes[slope] += 1
                
            # If a slope appears k times from point i, it means k+1 points are on that line
            if slopes:
                max_points = max(max_points, max(slopes.values()) + 1)
                
        return max_points
