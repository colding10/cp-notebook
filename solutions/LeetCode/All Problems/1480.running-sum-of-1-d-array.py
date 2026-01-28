#
# @lc app=leetcode id=1480 lang=python3
#
# [1480] Running Sum of 1d Array
#

# @lc code=start
class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        out = [0]
        for i, v in enumerate(nums):
            out.append(out[i] + v)
        
        return out[1:]
# @lc code=end

