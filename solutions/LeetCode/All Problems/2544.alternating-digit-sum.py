#
# @lc app=leetcode id=2544 lang=python3
#
# [2544] Alternating Digit Sum
#

# @lc code=start
class Solution:
    def alternateDigitSum(self, n: int) -> int:
        digs = [int(s) for s in str(n)]
        for i in range(len(digs)):
            digs[i] *= -1 if i % 2 else 1
        
        return sum(digs)
# @lc code=end

