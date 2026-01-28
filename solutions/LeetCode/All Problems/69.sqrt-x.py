#
# @lc app=leetcode id=69 lang=python3
#
# [69] Sqrt(x)
#

# @lc code=start
class Solution:
    def mySqrt(self, x: int) -> int:
        lower = 0
        upper = x
        
        while lower <= upper:
            mid = (lower + upper) // 2
            if mid * mid > x:
                upper = mid - 1
            elif mid * mid < x:
                lower = mid + 1
            else:
                return mid
        
        return upper
# @lc code=end

