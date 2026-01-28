#
# @lc app=leetcode id=63 lang=python3
#
# [63] Unique Paths II
#

# @lc code=start
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        if not obstacleGrid:
            return
        r, c = len(obstacleGrid), len(obstacleGrid[0])
        obstacleGrid[0][0] = 1 - obstacleGrid[0][0]
        for i in range(1, r):
            obstacleGrid[i][0] = obstacleGrid[i - 1][0] * (1 - obstacleGrid[i][0])
        for i in range(1, c):
            obstacleGrid[0][i] = obstacleGrid[0][i - 1] * (1 - obstacleGrid[0][i])
        for i in range(1, r):
            for j in range(1, c):
                obstacleGrid[i][j] = (
                    obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1]
                ) * (1 - obstacleGrid[i][j])
        return obstacleGrid[-1][-1]


# @lc code=end
