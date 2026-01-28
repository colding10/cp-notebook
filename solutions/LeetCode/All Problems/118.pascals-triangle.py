#
# @lc app=leetcode id=118 lang=python3
#
# [118] Pascal's Triangle
#

# @lc code=start
from math import comb

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        return [[comb(i, j) for j in range(i+1)] for i in range(numRows)]

# @lc code=end

