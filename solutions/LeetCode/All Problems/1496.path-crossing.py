#
# @lc app=leetcode id=1496 lang=python3
#
# [1496] Path Crossing
#

# @lc code=start
class Solution:
    def isPathCrossing(self, path: str) -> bool:
        seen = set()
        loc = (0, 0)
        
        for c in path:
            seen.add(loc)
            
            if c == "N":
                loc = (loc[0], loc[1] + 1)
            if c == "S":
                loc = (loc[0], loc[1] - 1)
            if c == "W":
                loc = (loc[0] + 1, loc[1])
            if c == "E":
                loc = (loc[0] - 1, loc[1])
            
            if loc in seen:
                return True
        
        return False
# @lc code=end

