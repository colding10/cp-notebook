#
# @lc app=leetcode id=2496 lang=python3
#
# [2496] Maximum Value of a String in an Array
#

# @lc code=start
class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        best = 0
        for s in strs:
            if s.isnumeric():
                val = int(s)
            else:
                val = len(s)
            
            best = max(best, val)
        
        return best
# @lc code=end

