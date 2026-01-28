#
# @lc app=leetcode id=120 lang=python3
#
# [120] Triangle
#

# @lc code=start
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        for i, row in enumerate(triangle):
            if i == 0:
                continue
            
            for j, v in enumerate(row):
                parents = []
                if j > 0:
                    parents.append(triangle[i-1][j-1])
                if j < len(triangle[i]) - 1:
                    parents.append(triangle[i-1][j])
                    
                triangle[i][j] += min(parents)
        
        return min(triangle[-1])
                
# @lc code=end

