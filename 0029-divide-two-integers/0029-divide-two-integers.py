class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # determine if the result is negative or positive
        # by checking if the signs of the dividend and the divisor are different
        negative = (dividend < 0) != (divisor < 0)
        
        dividend = abs(dividend)
        divisor = abs(divisor)
        
        
        res = 0
        
        # while the dividend is greater than or equal to the divisor, keep dividing
        while dividend >= divisor:
            shift = 0
            #multiplying divisor (*2)
            while dividend >= (divisor << shift):
                shift += 1
                
            # add the current quotient to the result
            res += 1 << (shift - 1)
            # subtract the current dividend from the total dividend
            dividend -= divisor << (shift - 1)
        
       
        if negative:
            res = -res
     
        if res > 2**31 - 1:
            return 2**31 - 1
        
        if res < -2**31:
            return -2**31
    
        return res

