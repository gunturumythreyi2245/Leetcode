from collections import deque
from typing import List

class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        # Step 1: Build the graph where adj[u] contains all methods invoked by u
        adj = {i: [] for i in range(n)}
        for u, v in invocations:
            adj[u].append(v)
            
        # Step 2: Use BFS to find all suspicious methods starting from k
        suspicious = {k}
        queue = deque([k])
        
        while queue:
            curr = queue.popleft()
            for neighbor in adj[curr]:
                if neighbor not in suspicious:
                    suspicious.add(neighbor)
                    queue.append(neighbor)
                    
        # Step 3: Check if any non-suspicious method invokes a suspicious method
        for u, v in invocations:
            if v in suspicious and u not in suspicious:
                # If an external method invokes a suspicious one, we cannot remove any
                return list(range(n))
                
        # Step 4: Otherwise, return all non-suspicious methods
        return [i for i in range(n) if i not in suspicious]
