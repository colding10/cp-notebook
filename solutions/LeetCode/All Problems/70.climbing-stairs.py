#
# @lc app=leetcode id=70 lang=python3
#
# [70] Climbing Stairs
#

# @lc code=start

from math import comb, perm


class Solution:
    def climbStairs(self, n: int) -> int:
        a, b = 1, 1

        for i in range(n):
            a, b = b, a + b
        return a


# @lc code=end
