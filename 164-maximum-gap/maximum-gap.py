class Solution:
    def maximumGap(self, nums: list[int]) -> int:
        n = len(nums)
        if n < 2:
            return 0
            
        min_val = min(nums)
        max_val = max(nums)
        
        # If all numbers are identical, the maximum gap is zero
        if min_val == max_val:
            return 0
            
        # Calculate minimum possible gap size using Pigeonhole Principle
        bucket_size = max(1, (max_val - min_val) // (n - 1))
        bucket_count = (max_val - min_val) // bucket_size + 1
        
        # Tracks the min and max values within each separate bucket
        bucket_min = [float('inf')] * bucket_count
        bucket_max = [float('-inf')] * bucket_count
        
        # Put each number into its designated bucket
        for x in nums:
            idx = (x - min_val) // bucket_size
            bucket_min[idx] = min(bucket_min[idx], x)
            bucket_max[idx] = max(bucket_max[idx], x)
            
        # Scan buckets to find the maximum gap between neighbors
        max_gap = 0
        prev_max = min_val
        
        for i in range(bucket_count):
            # Skip empty buckets
            if bucket_min[i] == float('inf'):
                continue
                
            # Gap is measured from previous bucket's max to current bucket's min
            max_gap = max(max_gap, bucket_min[i] - prev_max)
            prev_max = bucket_max[i]
            
        return max_gap
