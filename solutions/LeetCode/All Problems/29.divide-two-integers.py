#
# @lc app=leetcode id=29 lang=python3
#
# [29] Divide Two Integers
#

# @lc code=start
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        lower = 0
        upper = dividend
        while lower <= upper:
            mid =  (upper + lower) // 2
            if mid * divisor == dividend:
                return mid
            elif mid * divisor < dividend:
                lower = mid + 1
            else:
                upper = mid - 1
            
        return lower
# @lc code=end

