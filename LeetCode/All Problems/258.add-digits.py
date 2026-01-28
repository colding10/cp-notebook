#
# @lc app=leetcode id=258 lang=python3
#
# [258] Add Digits
#

# @lc code=start
class Solution:
    def addDigits(self, num: int) -> int:
        s = str(num)
        while len(s) > 1:
            s = str(sum(int(c) for c in s))
        
        return int(s)
# @lc code=end

