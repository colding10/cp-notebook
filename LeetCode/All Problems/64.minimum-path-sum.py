#
# @lc app=leetcode id=64 lang=python3
#
# [64] Minimum Path Sum
#

# @lc code=start
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        dp = [[float("inf") for _ in range(len(grid[0]))] for _ in range(len(grid))]
        dp[0][0] = grid[0][0]

        r, c = len(grid), len(grid[0])

        for i in range(1, r):
            dp[i][0] = dp[i - 1][0] + (1 - dp[i][0])
        for i in range(1, c):
            dp[0][i] = dp[0][i - 1] + (1 - dp[0][i])
        for i in range(1, r):
            for j in range(1, c):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1])
        return dp[-1][-1]


# @lc code=end
