#
# @lc app=leetcode id=51 lang=python3
#
# [51] N-Queens
#

# @lc code=start
from itertools import permutations

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        if n == 0:
            return []
        
        graph = ["." * i + "Q" + "." * (n-i-1) for i in range(n)]
        return list(set(permutations(graph)))
        
# @lc code=end

