class Solution:
    def checkDivisibility(self, n: int) -> bool:
        # Initialize digit sum to 0 and digit product to 1
        digit_sum = 0
        digit_product = 1
        
        # Make a copy of n to extract digits without changing the original number
        temp = n
        
        while temp > 0:
            # Extract the last digit and truncate it from temp
            temp, digit = divmod(temp, 10)
            
            # Accumulate sum and product
            digit_sum += digit
            digit_product *= digit
            
        # Check if the original number is divisible by the sum of both values
        return n % (digit_sum + digit_product) == 0
