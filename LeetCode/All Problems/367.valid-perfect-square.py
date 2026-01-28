#
# @lc app=leetcode id=367 lang=python3
#
# [367] Valid Perfect Square
#

# @lc code=start
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        lower = 0
        upper = num
        
        while lower < upper:
            mid = (lower + upper) // 2
            if upper * upper == num:
                return True
            if mid * mid < num:
                lower = mid + 1
            if mid * mid > num:
                upper = mid - 1
            
        
        return False
# @lc code=end

