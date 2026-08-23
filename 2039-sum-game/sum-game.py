class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)
        
        # Track digit sums for each half
        left_sum = 0
        right_sum = 0
        
        # Track the number of question marks for each half
        left_q = 0
        right_q = 0
        
        # Process the left half of the string
        for i in range(n // 2):
            if num[i] == '?':
                left_q += 1
            else:
                left_sum += int(num[i])
                
        # Process the right half of the string
        for i in range(n // 2, n):
            if num[i] == '?':
                right_q += 1
            else:
                right_sum += int(num[i])
                
        # Bob wins if and only if the difference in value sums 
        # matches exactly 9 points per 2 unmatched question marks.
        # Otherwise, Alice wins.
        return (left_sum - right_sum) * 2 != (right_q - left_q) * 9
