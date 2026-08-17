class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        # Edge Case: If numerator is 0, the answer is just "0"
        if numerator == 0:
            return "0"
            
        res = []
        
        # Determine the sign of the result
        # If one number is negative (but not both), add a negative sign
        if (numerator < 0) ^ (denominator < 0):
            res.append("-")
            
        # Work with absolute values to simplify the division steps
        num = abs(numerator)
        den = abs(denominator)
        
        # Calculate the integer part before the decimal point
        res.append(str(num // den))
        remainder = num % den
        
        # If there is no remainder, it's a whole number! Return immediately.
        if remainder == 0:
            return "".join(res)
            
        # Otherwise, add a decimal point and process the fractional part
        res.append(".")
        
        # Map stores: {remainder: index_in_res_array}
        seen_remainders = {}
        
        while remainder != 0:
            # If the remainder has been seen before, a repeating cycle is found
            if remainder in seen_remainders:
                # Insert an opening parenthesis at the first occurrence index
                res.insert(seen_remainders[remainder], "(")
                res.append(")")
                break
                
            # Store the current array length as the index position for this remainder
            seen_remainders[remainder] = len(res)
            
            # Simulate basic long division steps
            remainder *= 10
            res.append(str(remainder // den))
            remainder %= den
            
        return "".join(res)
