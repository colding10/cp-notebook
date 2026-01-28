#
# @lc app=leetcode id=119 lang=python3
#
# [119] Pascal's Triangle II
#

# @lc code=start
from math import comb
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        return [comb(rowIndex, j) for j in range(rowIndex+1)]
# @lc code=end

