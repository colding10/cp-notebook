#
# @lc app=leetcode id=326 lang=python3
#
# [326] Power of Three
#

# @lc code=start
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        x = 1/3
        while True:
            x *= 3
            if x > n:
                return False
            if x == n:
                return True
        
        return False
# @lc code=end

